#include "Game.h"
#include "Enemy.h"

Enemy::Enemy(const std::string& name, float maxHealth, float maxEnergy, float gravity, float moveSpeed, float jumpSpeed)
    : Character(name, maxHealth, maxEnergy), m_Movement(gravity, moveSpeed, jumpSpeed)
{}

void Enemy::SetState(AIState state)
{
    m_State = state;
}

AIState Enemy::GetState() const
{
    return m_State;
}
