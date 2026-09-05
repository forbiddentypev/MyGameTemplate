#include "Game.h"
#include "Character.h"

Character::Character(const std::string& name, float maxHealth, float maxEnergy)
    : m_Name(name)
    , m_Health(maxHealth)
    , m_MaxHealth(maxHealth)
    , m_Energy(maxEnergy)
    , m_MaxEnergy(maxEnergy)
{
}

// ---- Name ----

const std::string& Character::GetName() const
{
    return m_Name;
}

void Character::SetName(const std::string& name)
{
    m_Name = name;
}

// ---- Health ----

float Character::GetHealth() const
{
    return m_Health;
}

float Character::GetMaxHealth() const
{
    return m_MaxHealth;
}

void Character::SetMaxHealth(float maxHealth)
{
    m_MaxHealth = std::max(0.0f, maxHealth);
    m_Health = std::min(m_Health, m_MaxHealth);
}

void Character::SetHealth(float health)
{
    m_Health = std::clamp(health, 0.0f, m_MaxHealth);
}

void Character::Heal(float amount)
{
    if (amount <= 0.0f)
        return;

    SetHealth(m_Health + amount);
}

void Character::TakeDamage(float amount)
{
    if (amount <= 0.0f)
        return;

    SetHealth(m_Health - amount);
}

bool Character::IsAlive() const
{
    return m_Health > 0.0f;
}

// ---- Energy / Mana ----

float Character::GetEnergy() const
{
    return m_Energy;
}

float Character::GetMaxEnergy() const
{
    return m_MaxEnergy;
}

void Character::SetMaxEnergy(float maxEnergy)
{
    m_MaxEnergy = std::max(0.0f, maxEnergy);
    m_Energy = std::min(m_Energy, m_MaxEnergy);
}

void Character::SetEnergy(float energy)
{
    m_Energy = std::clamp(energy, 0.0f, m_MaxEnergy);
}

bool Character::ConsumeEnergy(float amount)
{
    if (amount <= 0.0f)
        return true;

    if (m_Energy < amount)
        return false;

    m_Energy -= amount;
    return true;
}

void Character::RestoreEnergy(float amount)
{
    if (amount <= 0.0f)
        return;

    SetEnergy(m_Energy + amount);
}
