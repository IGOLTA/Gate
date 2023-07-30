#pragma once

#include "portal.h"

namespace godot
{
	class PortalsManager : public Node3D
	{
		GDCLASS(PortalsManager, Node3D)
	private:
		Portal* portal_1;
		Portal* portal_2;
	protected:
		static void _bind_methods();
	public:
		void _ready() override;
	};
}

