#include "Game.h"
#include "NPC.h"

NPC::NPC(const std::string& name, float maxHealth, float maxEnergy, float gravity, float moveSpeed, float jumpSpeed)
    : Character(name, maxHealth, maxEnergy), m_Movement(gravity, moveSpeed, jumpSpeed)
{}

void NPC::SetState(NPCState state)
{
    m_State = state;
}

NPCState NPC::GetState() const
{
    return m_State;
}