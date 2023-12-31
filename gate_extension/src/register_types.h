#pragma once

#include "player.h"
#include "portals/portal.h"
#include "portals/portals_manager.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

void initialize_gate_module();
void uninitialize_gate_module();