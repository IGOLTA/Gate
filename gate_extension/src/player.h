#pragma once

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/math.hpp>

namespace godot {
	class Player : public CharacterBody3D {
		GDCLASS(Player, CharacterBody3D)

	private:
		Input* input = Input::get_singleton();

		const float walkingSpeed = 7.5f;
		const float runningSpeed = 11.5f;
		const float jumpSpeed = 8.0f;
		const float gravity = 20.0f;
		const float lookSpeed = 2.0f;
		const float lookXLimit = 45.0f;
	
		Vector3 moveDirection = Vector3(0, 0, 0);
	protected:
		static void _bind_methods();
	public:
		void _physics_process(double delta) override;
	};
}
