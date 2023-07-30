#include "player.h"

using namespace godot;

Node3D* Player::get_head() const
{
    return get_node<Node3D>("Head");
}

void Player::_bind_methods() {
}

void Player::_ready()
{
    if (Engine::get_singleton()->is_editor_hint()) return;

    input->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);
}

void Player::_input(const Ref<InputEvent>& event)
{
    if (Engine::get_singleton()->is_editor_hint()) return;

    if(auto mouseMotionEvent = dynamic_cast<const InputEventMouseMotion*>(event.ptr()))
    {
        auto vel = mouseMotionEvent->get_relative();
        auto head = get_node<Node3D>("Head");

        rotate_y(-vel.x * lookSpeed);

        Vector3 headRotation = head->get_rotation();
        headRotation.x = Math::clamp(headRotation.x - vel.y * lookSpeed, -lookXLimit, lookXLimit);
        headRotation.y = 0;
        headRotation.z = 0;
    	head->set_rotation(headRotation);
    }
}


void godot::Player::_physics_process(double delta)
{
    if (Engine::get_singleton()->is_editor_hint()) return;

    Vector3 forward = -this->get_transform().basis.get_column(2);
    Vector3 right = this->get_transform().basis.get_column(0);

    // Press Left Shift to run
    bool isRunning = input->is_action_pressed("run");
    float speed = isRunning ? runningSpeed : walkingSpeed;
    right *= speed * (input->is_action_pressed("right") - input->is_action_pressed("left"));
    forward *= speed * (input->is_action_pressed("forward") - input->is_action_pressed("backward"));

    float movementDirectionY = moveDirection.y;
    moveDirection = forward  + right;

    if (input->is_action_pressed("jump") && is_on_floor())
		moveDirection.y = jumpSpeed;
    else 
        moveDirection.y = movementDirectionY;

    if (!is_on_floor())
        moveDirection.y -= gravity * delta;

    set_velocity(moveDirection);
    move_and_slide();
}