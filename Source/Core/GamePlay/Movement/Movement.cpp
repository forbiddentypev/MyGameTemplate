#include "Game.h"
#include "Movement.h"

Vector3::Vector3()
    : x(0.0f)
    , y(0.0f)
    , z(0.0f)
{
}

Vector3::Vector3(float x, float y, float z)
    : x(x)
    , y(y)
    , z(z)
{
}

Movement::Movement()
    : m_Gravity(-9.8f)
    , m_MoveSpeed(5.0f)
    , m_JumpSpeed(10.0f)
{
}

Movement::Movement(float gravity, float moveSpeed, float jumpSpeed)
    : m_Gravity(gravity)
    , m_MoveSpeed(moveSpeed)
    , m_JumpSpeed(jumpSpeed)
{
}

void Movement::SetDirection(const Vector3& dir)
{
    m_Direction = dir;
}

void Movement::SetGrounded(bool grounded)
{
    m_IsOnGround = grounded;
}

Vector3 Movement::GetVelocity() const
{
    return m_Velocity;
}

void Movement::Jump() {
    if (m_IsOnGround)
        m_Velocity.y = m_JumpSpeed;
    SetGrounded(false);
}

void Movement::Update(float deltaTime)
{
    if (deltaTime < 0)
        deltaTime = 0;

    // Horizontal Movement
    m_Velocity.x = m_Direction.x * m_MoveSpeed;
    m_Velocity.z = m_Direction.z * m_MoveSpeed;

    // Verticle movement/Gravity
    if (m_IsOnGround)
    {
        if (m_Velocity.y < 0.0f)
            m_Velocity.y = 0.0f;
    }
    else
    {
        m_Velocity.y += m_Gravity * deltaTime;
    }
}
