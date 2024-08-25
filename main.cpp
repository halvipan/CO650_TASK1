#include <iostream>
#include "GameComponent.h"
#include "DrawableGameComponent.h"
#include "Game.h"

using namespace std;

int GameComponent::instances = 0;

void init() {
    cout << "Initialising game" << endl;
}

void term() {
    cout << "Terminating game" << endl;
}

int main() {
    Game* game = new Game(2);
    game->SetInitialise(init);
    game->SetTerminate(term);
    game->Add(new GameComponent());
    game->Add(new DrawableGameComponent(0, 0));
    game->Run();
}
