#pragma once

class Character
{
public:
    Character(const std::string& name, float maxHealth, float maxEnergy);
    virtual ~Character() = default;

    // ---- Name ----
    const std::string& GetName() const;
    void SetName(const std::string& name);

    // ---- Health ----
    float GetHealth() const;
    float GetMaxHealth() const;
    void SetMaxHealth(float maxHealth);
    void SetHealth(float health);
    void Heal(float amount);
    void TakeDamage(float amount);
    bool IsAlive() const;

    // ---- Energy / Mana ----
    float GetEnergy() const;
    float GetMaxEnergy() const;
    void SetMaxEnergy(float maxEnergy);
    void SetEnergy(float energy);
    bool ConsumeEnergy(float amount);   // returns false if not enough energy
    void RestoreEnergy(float amount);

protected:
    std::string m_Name;

    float m_Health;
    float m_MaxHealth;

    float m_Energy;
    float m_MaxEnergy;
};
