#ifndef ALTTPENGINE_HPP
#define ALTTPENGINE_HPP
#include <Sakura/Core/Engine.hpp>

class ALTTPEngine : public Sakura::Core::Engine
{
public:
    ALTTPEngine(int argc, char *argv[]);
    bool initialize();
    void onEvent(const sf::Event &event);

    void beforeUpdate();
    void onUpdate();
    void afterUpdate();

    void beforeDraw();
    void onDrawEntities();
    void onDraw();
    void onDrawConsole();
    void afterDraw();

    std::string gameVersion()  const;
    std::string defaultTitle() const;
private:
};

#endif // ALTTPENGINE_HPP
