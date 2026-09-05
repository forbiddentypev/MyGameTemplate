#include "Game.h"
#include "Player.h"

Player::Player(const std::string& name, float maxHealth, float maxEnergy, float gravity, float moveSpeed, float jumpSpeed)
    : Character(name, maxHealth, maxEnergy), m_Movement(gravity, moveSpeed, jumpSpeed)
{}

Movement Player::GetMovement() const
{
    return m_Movement;
}