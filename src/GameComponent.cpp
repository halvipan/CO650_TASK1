//
// Created by Hal Vipan on 23/08/2024.
//

#include <iostream>
#include "../include/GameComponent.h"

using namespace std;

GameComponent::GameComponent() {
    id = ++instances;
}

void GameComponent::Update(const tm* time) {
    int hour = time->tm_hour;
    int minute = time->tm_min;
    int seconds = time->tm_sec;
    cout << "ID : " << id << " Updated @ " << hour << ":" << minute << ":" << seconds << endl;
}