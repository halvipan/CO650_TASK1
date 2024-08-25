//
// Created by Hal Vipan on 23/08/2024.
//

#include <iostream>
#include <string>
#include "DrawableGameComponent.h"

using namespace std;

DrawableGameComponent::DrawableGameComponent(int x, int y) {
    x = 0;
    y = 0;
    direction = Right;
}

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
    int cur = (int) direction;
    int num = cur;
    while (num == cur) num = rand() % 4;
    direction = Direction(num);
}