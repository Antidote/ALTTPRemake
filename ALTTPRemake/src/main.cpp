#include <iostream>
#include "ALTTPEngine.hpp"

#ifdef SFML_SYSTEM_LINUX
    #include <X11/Xlib.h>
#endif

int main(int argc, char* argv[])
{
#ifdef SFML_SYSTEM_LINUX
    XInitThreads();
#endif
    std::ios_base::sync_with_stdio(false);
    ALTTPEngine engine;

#ifndef DEBUG
    try
    {
#endif
        engine.initialize(argc, argv);
        return engine.run();
#ifndef DEBUG
    }
    catch(...)
    {
        sEngineRef().console().print(Console::Fatal, "An unhandled exception has occurred");
        sEngineRef().setFullscreen(false);
        return 1;
    }
#endif
}
