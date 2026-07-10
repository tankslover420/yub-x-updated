#pragma once

#include <cstdint>
#include <Windows.h>

struct lua_State;
struct YieldState;
struct YieldingLuaThread;

#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
    const uintptr_t Print = REBASE(0x8273F0);
    const uintptr_t OpcodeLookupTable = REBASE(0x5E47F90);
    const uintptr_t ScriptContextResume = REBASE(0x1ECC890);
    const uintptr_t GetLuaStateForInstance = REBASE(0x1E456B0);

    namespace Luau
    {
        const uintptr_t Luau_Execute = REBASE(0x7FE910);
        const uintptr_t LuaO_NilObject = REBASE(0x5E47E60);
        const uintptr_t LuaH_DummyNode = REBASE(0x5E47D00);
        const uintptr_t LuaD_Throw = REBASE(0x7e0b30);
    }

    namespace DataModel
    {
        const uintptr_t Children = 0x70; 
        const uintptr_t GameLoaded = 0x668;
        const uintptr_t ScriptContext = 0x440;
        const uintptr_t FakeDataModelToDataModel = 0x1D0;

        const uintptr_t FakeDataModelPointer = REBASE(0x84a9e98);
    }

    namespace ExtraSpace
    {
        const uintptr_t ScriptContextToResume = 0x7e8;
        const uintptr_t RequireBypass = 0x960;
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