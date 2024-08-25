#ifndef CO650_TASK1_GAME_H
#define CO650_TASK1_GAME_H


#include "GameComponent.h"

typedef void (*FP)();

class Game {
public:
    void Add(GameComponent* component);
    Game(int maxComponents);
    void Run();
    void SetInitialise(FP init);
    void SetTerminate(FP term);
private:
    int componentCount;
    GameComponent** components;
    FP initialise;
    FP terminate;
    const int TICKS_1000MS = 1000;
};


#endif //CO650_TASK1_GAME_H
