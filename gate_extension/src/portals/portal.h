#pragma once

#include "../player.h"

#include <godot_cpp/classes/viewport_texture.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/sub_viewport.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/shader_material.hpp>

namespace godot
{
	class Portal : public Node3D
	{
		GDCLASS(Portal, Node3D)
	private:
		Camera3D* camera;
		MeshInstance3D* mesh;
		SubViewport* viewport;

		NodePath otherPortalPath;
		NodePath playerPath;

		Portal* otherPortal;
		Node3D* playerHead;
		Camera3D* otherCamera;

	protected:
		static void _bind_methods();
	public:
		void _ready() override;
		void _process(double delta) override;

		NodePath get_other_portal() const;
		void set_other_portal(const NodePath& other_portal);
		NodePath get_player() const;
		void set_player(const NodePath& player_path);
		Camera3D* get_camera() const;
		MeshInstance3D* get_mesh() const;
		SubViewport* get_portal_viewport() const;
	};
}


