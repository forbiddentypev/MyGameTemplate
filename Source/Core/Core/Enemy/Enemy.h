#pragma once
#include "Character/Character.h"
#include "Movement/Movement.h"
#include "AI/AI.h"

class Enemy : public Character
{
public:
    Enemy(const std::string& name
        , float maxHealth
        , float maxEnergy
        , float gravity
        , float moveSpeed
        , float jumpSpeed
    );

    void SetState(AIState state);
    AIState GetState() const;

private:
    Movement m_Movement;
    AIState m_State = AIState::Idle;
};
