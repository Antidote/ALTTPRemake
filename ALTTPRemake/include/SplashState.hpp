#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP
#include <RunState.hpp>

class SplashState : public RunState
{
public:
    SplashState();
    virtual ~SplashState();

    virtual void initialize();
    virtual void update(sf::Time dt);
    virtual void draw(sf::RenderTarget &rt);
    virtual bool isInitialized() const;
    Type type() const;
    virtual bool isDone() const;
    virtual std::string name() const;
    virtual RunState* nextState() const;

protected:
    bool        m_isInitialized;
    bool        m_isDone;
    std::string m_name;
    RunState*   m_nextState;
};

#endif // SPLASHSTATE_HPP
