#include "portals_manager.h"

#include "portal.h"

using namespace godot;

void PortalsManager::_bind_methods()
{
	
}

void PortalsManager::_ready()
{
	if (Engine::get_singleton()->is_editor_hint()) return;

	portal_1 = get_node<Portal>("Portal1");
	portal_2 = get_node<Portal>("Portal2");

}

