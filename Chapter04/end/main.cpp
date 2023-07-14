#include "LuaExecutor.h"
#include "LoggingLuaExecutorListener.h"
#include <memory>
#include <iostream>

int main()
{
    auto listener = std::unique_ptr<LuaExecutorListener>(new LoggingLuaExecutorListener());
    auto lua = std::make_unique<LuaExecutor>(*listener.get());
    lua->executeFile("script.lua");

    auto result = lua->call("greetings", LuaString::make("C++"), LuaString::make("Lua"));
    std::cout << getLuaValueString(result) << std::endl
              << std::endl;

    auto results = lua->vcall(
        "dump_params",
        LuaString::make("C++"),
        LuaString::make("Lua"),
        LuaNumber::make(3.14),
        LuaBoolean::make(true),
        LuaNil::make());
    for (auto result : results)
    {
        std::cout << getLuaValueString(result) << std::endl;
    }

    return 0;
}
