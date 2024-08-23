//
// Created by Hal Vipan on 23/08/2024.
//

#ifndef CO650_TASK1_GAMECOMPONENT_H
#define CO650_TASK1_GAMECOMPONENT_H

using namespace std;

class GameComponent {
public:
    GameComponent();
    void Update(const tm *time);
private:
    int id;
    static int instances;
};


#endif //CO650_TASK1_GAMECOMPONENT_H
