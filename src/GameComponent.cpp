#include <iostream>
#include "GameComponent.h"

using namespace std;

int GameComponent::instances = 0;

GameComponent::GameComponent() {
    id = ++instances;
}

void GameComponent::Update(const tm* eventTime) {
    int hour = eventTime->tm_hour;
    int minute = eventTime->tm_min;
    int seconds = eventTime->tm_sec;
    cout << "ID : " << id << " Updated @ " << hour << ":" << minute << ":" << seconds << endl;
}