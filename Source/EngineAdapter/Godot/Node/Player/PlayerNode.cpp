#include "PlayerNode.h"

PlayerNode::PlayerNode() {}
PlayerNode::~PlayerNode() { delete m_Player; }

void PlayerNode::_bind_methods()
{
    // Nothing to expose to the editor yet
}

void PlayerNode::_ready()
{
    m_Player = new Player("SomeName", 100.0f, 50.0f, -9.8f, 5.0f, 10.0f);
}

void PlayerNode::_physics_process(double delta)
{
    if (m_Player == nullptr)
        return;

    // 1. Real grounded state from Godot's own physics — not hardcoded.
    m_Player->GetMovement().SetGrounded(is_on_floor());

    // 2. Movement direction — hardcoded for now until input is wired up.
    ::Vector3 rawDirection(1.0f, 0.0f, 0.0f);
    m_Player->GetMovement().SetDirection(rawDirection);

    // 3. Advance the raw simulation.
    m_Player->GetMovement().Update(static_cast<float>(delta));

    // 4. Pull velocity out, convert to Godot's Vector3, actually apply it.
    ::Vector3 rawVelocity = m_Player->GetMovement().GetVelocity();
    godot::Vector3 godotVelocity(rawVelocity.x, rawVelocity.y, rawVelocity.z);

    set_velocity(godotVelocity);
    move_and_slide();
}
