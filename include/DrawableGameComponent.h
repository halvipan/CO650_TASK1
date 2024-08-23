//
// Created by Hal Vipan on 23/08/2024.
//

#ifndef CO650_TASK1_DRAWABLEGAMECOMPONENT_H
#define CO650_TASK1_DRAWABLEGAMECOMPONENT_H

#include "GameComponent.h"

using namespace std;

enum Direction { Left, Right, Up, Down };

class DrawableGameComponent : public GameComponent {
public:
    Direction direction;
    DrawableGameComponent(int x, int y);
    const int SCREEN_HEIGHT = 20;
    const int SCREEN_WIDTH = 80;
    void Update(const tm *eventTime) override;
private:
    void ChangeDirection();
    void Draw();
    int x;
    int y;
};


#endif //CO650_TASK1_DRAWABLEGAMECOMPONENT_H
