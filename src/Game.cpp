//
// Created by Hal Vipan on 23/08/2024.
//

#include <thread>
#include "Game.h"

using namespace std;

Game::Game(int maxComponents) {
    components = new GameComponent*[maxComponents];
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

void ComponentLoop(GameComponent* component) {
    for (int i = 0; i < 5; ++i) {
        this_thread::sleep_for(chrono::seconds(1));

        time_t t = time(nullptr);
        tm* currentTime = localtime(&t);

        component->Update(currentTime);
    }
}

void Game::Run() {
    initialise();

    vector<thread> threads;

    for (int i = 0; i < componentCount; ++i) {
        thread t(ComponentLoop, components[i]);
        threads.push_back(std::move(t));
    }

    for(thread &t : threads) {
        t.join();
    }

    terminate();
}