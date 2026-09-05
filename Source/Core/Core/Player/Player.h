#pragma once

#include "Character/Character.h" // I used ../ just for the sake i never wanted to build CMake now, just i ussed the editor debugger
#include "Movement/Movement.h"

#include <string>

class Player : public Character
{
public:
    Player(const std::string& name
        , float maxHealth
        , float maxEnergy
        , float gravity
        , float moveSpeed
        , float jumpSpeed
    );

    Movement GetMovement() const;

private:
    Movement m_Movement;
};
