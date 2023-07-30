#include "player.h"

using namespace godot;

void Player::_bind_methods() {
}

void godot::Player::_physics_process(double delta)
{
    if (Engine::get_singleton()->is_editor_hint()) return;

    Vector3 forward = this->get_transform().basis.rows[0];
    Vector3 right = this->get_transform().basis.rows[1];

    // Press Left Shift to run
    bool isRunning = input->is_action_pressed("run");
    float speed = isRunning ? runningSpeed : walkingSpeed;
    float curSpeedX = speed * (input->is_action_pressed("right") - input->is_action_pressed("left"));
    float curSpeedY = speed * (input->is_action_pressed("forward") - input->is_action_pressed("backward"));

    float movementDirectionY = moveDirection.y;
    moveDirection = (forward * curSpeedX) + (right * curSpeedY);

    if (input->is_action_pressed("jump") && is_on_floor())
    {
        moveDirection.y = jumpSpeed;
    }
    else
    {
        moveDirection.y = movementDirectionY;
    }

    if (!is_on_floor())
    {
        moveDirection.y -= gravity * delta;
    }

    set_velocity(moveDirection * delta);
    move_and_slide();

    // Player and Camera rotation
    auto mouse = input->get_last_mouse_velocity();


}