#include <iostream>
#include "./include/GameComponent.h"

int GameComponent::instances = 0;

int main() {
    GameComponent* gc1 = new GameComponent();
    GameComponent* gc2 = new GameComponent();
    GameComponent* gc3 = new GameComponent();

    time_t t = time(nullptr);
    tm* time = localtime(&t);

    gc1->Update(time);
    gc2->Update(time);
    gc3->Update(time);
}
