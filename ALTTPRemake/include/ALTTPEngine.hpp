#ifndef ALTTPENGINE_HPP
#define ALTTPENGINE_HPP
#include <Engine.hpp>

class ALTTPEngine : public Engine
{
public:
    ALTTPEngine();
    void initialize(int argc, char *argv[]);

    static std::string gameVersion();
};

#endif // ALTTPENGINE_HPP
