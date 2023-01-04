#ifndef _MAIN_H_
#define _MAIN_H_

#include <Windows.h>
#include <memory>
#include "memwrapper/memwrapper.h"

using GameloopPrototype = void(__cdecl*)();
std::unique_ptr<memwrapper::memhook<GameloopPrototype>> GameloopHook;

class AsiPlugin
{

public:
    explicit AsiPlugin();
    virtual ~AsiPlugin();
} AsiPlugin;

#endif