#pragma once

#include <cstdint>
#include <Windows.h>

struct lua_State;
struct YieldState;
struct YieldingLuaThread;

#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
    const uintptr_t Print = REBASE(0x470C4E0);
    const uintptr_t OpcodeLookupTable = REBASE(0x62dffa0);
    const uintptr_t ScriptContextResume = REBASE(0x1e067f0);
    const uintptr_t GetLuaStateForInstance = REBASE(0x1D36CE0);

    namespace Luau
    {
        const uintptr_t Luau_Execute = REBASE(0x47a1e30);
        const uintptr_t LuaO_NilObject = REBASE(0x6a4d5e8);
        const uintptr_t LuaH_DummyNode = REBASE(0x6a4d478);
        const uintptr_t LuaD_Throw = REBASE(0x478f6a0);
    }

    namespace DataModel
    {
        const uintptr_t Children = 0x70; 
        const uintptr_t GameLoaded = 0x578;
        const uintptr_t ScriptContext = 0x440;
        const uintptr_t FakeDataModelToDataModel = 0x1D0;

        const uintptr_t FakeDataModelPointer = REBASE(0x7d28508);
    }

    namespace ExtraSpace
    {
        const uintptr_t ScriptContextToResume = 0x7D8;
        const uintptr_t RequireBypass = 0x909;
    }
}

namespace Roblox
{
    inline auto Print = (uintptr_t(*)(int, const char*, ...))Offsets::Print;
    inline auto Luau_Execute = (void(__fastcall*)(lua_State*))Offsets::Luau::Luau_Execute;
    inline auto GetLuaStateForInstance = (lua_State*(__fastcall*)(uint64_t, uint64_t*, uint64_t*))Offsets::GetLuaStateForInstance;
    inline auto ScriptContextResume = (uint64_t(__fastcall*)(uint64_t, YieldState*, YieldingLuaThread**, uint32_t, uint8_t, uint64_t))Offsets::ScriptContextResume;
    inline auto LuaD_Throw = (void(__fastcall*)(lua_State*, int))Offsets::Luau::LuaD_Throw;
}

// Dont forget to update Encryptions and Structs