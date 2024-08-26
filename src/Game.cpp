#include <thread>
#include "Game.h"
#include "MemberVariableUnsetException.h"

using namespace std;

Game::Game(int maxComponents) {
    components = new GameComponent*[maxComponents];
    componentCount = 0;
    initialise = nullptr;
    terminate = nullptr;
}

void Game::Add(GameComponent* component) {
    components[componentCount++] = component;
}

void Game::SetInitialise(FP init) {
    initialise = init;
}

void Game::SetTerminate(FP term) {
    terminate = term;
}

void ComponentLoop(GameComponent* component, mutex& mtx) {
    for (int i = 0; i < 5; ++i) {
        this_thread::sleep_for(chrono::seconds(1));

        time_t t = time(nullptr);
        tm* currentTime = localtime(&t);

        lock_guard<mutex> lock(mtx);
        component->Update(currentTime);
    }
}

void Game::Run() {
    if (initialise == nullptr) throw(MemberVariableUnsetException("initialise"));
    initialise();

    mutex mtx;
    vector<thread> threads;

    for (int i = 0; i < componentCount; ++i) {
        thread t(ComponentLoop, components[i], ref(mtx));
        threads.push_back(std::move(t));
    }

    for(thread &t : threads) {
        t.join();
    }

    if (terminate == nullptr) throw(MemberVariableUnsetException("terminate"));
    terminate();
}