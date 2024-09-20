#include <iostream>
#include "GameComponent.h"
#include "DrawableGameComponent.h"
#include "Game.h"
#include "MemberVariableUnsetException.h"

using namespace std;

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

    try {
        game->Run();
    }
    catch (MemberVariableUnsetException &e) {
        cout << "error: " << e.what() << ": " << e.memberVariable << endl;
    }
}
