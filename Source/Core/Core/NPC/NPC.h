#pragma once

#include "AI/AI.h"
#include "Movement/Movement.h"
#include "Character/Character.h"

class NPC : public Character
{
public:
    NPC(const std::string& name, float maxHealth, float maxEnergy, float gravity, float moveSpeed, float jumpSpeed);

    void SetState(NPCState state);
    NPCState GetState() const;

private:
    Movement m_Movement;
    NPCState m_State = NPCState::Idle;
};


