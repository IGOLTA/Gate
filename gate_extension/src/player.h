#pragma once

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/input_event_mouse_motion.hpp>

namespace godot {
	class Player : public CharacterBody3D {
		GDCLASS(Player, CharacterBody3D)

	private:
		Input* input = Input::get_singleton();

		const float walkingSpeed = 7.5f;
		const float runningSpeed = 11.5f;
		const float jumpSpeed = 8.0f;
		const float gravity = 20.0f;
		const float lookSpeed = 0.002f;
		const float lookXLimit = Math::deg_to_rad(45.0f);
	
		Vector3 moveDirection = Vector3();
		
		Vector2 lastMousePos = Vector2();
	protected:
		static void _bind_methods();
	public:
		Node3D* get_head() const;
		void _physics_process(double delta) override;
		void _ready() override;
		void _input(const Ref<InputEvent>& event) override;
	};
}
