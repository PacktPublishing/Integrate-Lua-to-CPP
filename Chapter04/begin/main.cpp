#include "LuaExecutor.h"
#include "LoggingLuaExecutorListener.h"
#include <memory>
#include <iostream>

int main()
{
    auto listener = std::unique_ptr<LuaExecutorListener>(new LoggingLuaExecutorListener());
    auto lua = std::make_unique<LuaExecutor>(*listener.get());
    lua->executeFile("script.lua");
    lua->execute("hello()");
    return 0;
}
