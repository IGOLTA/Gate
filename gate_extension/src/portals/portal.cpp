#include "portal.h"
#include "portal.h"

using namespace godot;

NodePath Portal::get_other_portal() const
{
	return otherPortalPath;
}

void Portal::set_other_portal(const NodePath& other_portal)
{
	otherPortalPath = other_portal;
}

NodePath Portal::get_player() const
{
	return playerPath;
}

void Portal::set_player(const NodePath& player_path)
{
	playerPath = player_path;
}

Camera3D* Portal::get_camera() const
{
	return get_portal_viewport()->get_node<Camera3D>("Camera");
}

MeshInstance3D* Portal::get_mesh() const
{
	return get_node<MeshInstance3D>("Mesh");
}

SubViewport* Portal::get_portal_viewport() const
{
	return get_node<SubViewport>("Viewport");
}

void Portal::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_other_portal"), &Portal::get_other_portal);
	ClassDB::bind_method(D_METHOD("set_other_portal", "p_other_portal"), &Portal::set_other_portal);
	ClassDB::add_property("Portal", PropertyInfo(Variant::NODE_PATH, "other_portal"), "set_other_portal", "get_other_portal");

	ClassDB::bind_method(D_METHOD("get_player"), &Portal::get_player);
	ClassDB::bind_method(D_METHOD("set_player", "p_player"), &Portal::set_player);
	ClassDB::add_property("Portal", PropertyInfo(Variant::NODE_PATH, "player"), "set_player", "get_player");
}

void Portal::_ready()
{
	if (Engine::get_singleton()->is_editor_hint()) return;

	viewport = get_portal_viewport();
	mesh = get_mesh();
	playerHead = get_node<Player>(get_player())->get_head();
	otherPortal = get_node<Portal>(get_other_portal());
	otherCamera = otherPortal->get_camera();

	camera = viewport->get_node<Camera3D>("Camera");

	viewport->set_size(get_viewport()->get_visible_rect().get_size());

	ShaderMaterial* material = dynamic_cast<ShaderMaterial*>(mesh->get_active_material(0).ptr());
	material->set_shader_parameter("ViewportTexture", viewport->get_texture());
}

void Portal::_process(double delta)
{
	if (Engine::get_singleton()->is_editor_hint()) return;

	camera->set_global_position(otherPortal->get_global_position() + playerHead->get_global_position() - get_global_position());
	camera->set_global_rotation(otherPortal->get_global_rotation() + playerHead->get_global_rotation() - get_global_rotation());
}
