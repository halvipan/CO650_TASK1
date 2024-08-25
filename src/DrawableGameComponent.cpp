#include <iostream>
#include "DrawableGameComponent.h"

using namespace std;

// Instructions say to "Set the x and y values to zero and direction to Right"
DrawableGameComponent::DrawableGameComponent(int x, int y) {
    this->x = 0;
    this->y = 0;
    direction = Right;
}

// Alternatively, use the x and y params
//DrawableGameComponent::DrawableGameComponent(int x, int y) : x(x), y(y) {
//    direction = Right;
//}

void DrawableGameComponent::Update(const tm *eventTime) {
    GameComponent::Update(eventTime);

    if (direction == Up && y < SCREEN_HEIGHT) y++;
    if (direction == Down && y > 0) y--;
    if (direction == Right && x < SCREEN_WIDTH) x++;
    if (direction == Left && x > 0) x--;

    Draw();
    ChangeDirection();
}

void DrawableGameComponent::Draw() {
    string directions[4] = {"Left", "Right", "Up", "Down"};
    cout << directions[direction] << " : X:" << x << " Y:" << y << endl;
}

void DrawableGameComponent::ChangeDirection() {
    srand(time(nullptr));

    int num = direction;
    while (num == direction) {
        num = rand() % 4;
    }

    direction = Direction(num);
}