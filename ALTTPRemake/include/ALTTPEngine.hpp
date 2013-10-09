#ifndef ALTTPENGINE_HPP
#define ALTTPENGINE_HPP
#include <Sakura/Core/Engine.hpp>

class ALTTPEngine : public Sakura::Core::Engine
{
public:
    ALTTPEngine();
    void initialize(int argc, char *argv[]);

    std::string gameVersion()  const;
    std::string defaultTitle() const;
};

#endif // ALTTPENGINE_HPP
