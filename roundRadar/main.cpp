#include "main.h"

template<typename T>
void WriteMemory(void* addr, T value) {
	DWORD oldProt = 0;
	VirtualProtect(addr, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProt);
	*reinterpret_cast<T*>(addr) = value;
	VirtualProtect(addr, sizeof(T), oldProt, NULL);
}

float height = { 95 };
float width = { 75 };
float x = { 20 };
float y = { 119.5 };

void GameloopHooked() {

	// Radar height //
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A47D), &height);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A632), &height);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A6AB), &height);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A70E), &height);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A801), &height);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A8AB), &height);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A921), &height);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A9D5), &height);
	WriteMemory<void*>(reinterpret_cast<void*>(0x5834F6), &height);

	// Radar width //
	WriteMemory<void*>(reinterpret_cast<void*>(0x5834C2), &width);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A449), &width);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A7E9), &width);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A840), &width);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A943), &width);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A99D), &width);

	// Radar x //
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A79B), &x);
	WriteMemory<void*>(reinterpret_cast<void*>(0x5834D4), &x);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A836), &x);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A8E9), &x);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A98A), &x);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A469), &x);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A5E2), &x);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A6E6), &x);

	// Radar y //
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A7C7), &y);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A868), &y);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A913), &y);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A9C7), &y);
	WriteMemory<void*>(reinterpret_cast<void*>(0x583500), &y);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A499), &y);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A60E), &y);
	WriteMemory<void*>(reinterpret_cast<void*>(0x58A71E), &y);

	GameloopHook->call();
}

AsiPlugin::AsiPlugin() {
	GameloopHook = std::make_unique<memwrapper::memhook<GameloopPrototype>>(0x748DA3, &GameloopHooked);
	GameloopHook->install();
}

AsiPlugin::~AsiPlugin() {
	GameloopHook->remove();
}