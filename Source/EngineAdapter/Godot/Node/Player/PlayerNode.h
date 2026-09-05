#pragma once

#include "Godot/Godot.h"
#include "Player/Player.h"

class PlayerNode : public godot::CharacterBody3D
{
    GDCLASS(PlayerNode, godot::CharacterBody3D);
public:
    PlayerNode();
    ~PlayerNode();

    void _ready() override;
    void _physics_process(double delta) override;

protected:
    static void _bind_methods();
    
private:
    Player* m_Player = nullptr;
};

