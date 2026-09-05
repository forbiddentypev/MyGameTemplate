#pragma once

struct Vector3
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    Vector3();
    Vector3(float x, float y, float z);
};

class Movement
{
public:
    Movement();
    Movement(float gravity, float moveSpeed, float jumpSpeed);

    void SetDirection(const Vector3& dir);
    void SetGrounded(bool grounded);

    Vector3 GetVelocity() const;

    void Jump();
    void Update(float deltaTime);

private:
    float m_Gravity;
    float m_MoveSpeed;
    float m_JumpSpeed;
    bool m_IsOnGround = true;

    Vector3 m_Velocity;
    Vector3 m_Direction;

};
