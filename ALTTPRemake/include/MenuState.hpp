#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP
#include <Sakura/Core/RunState.hpp>

class MenuState : public Sakura::Core::RunState
{
public:
    MenuState(const std::string& name);
    virtual ~MenuState();

    virtual void initialize();
    virtual void update(sf::Time dt);
    virtual void draw(sf::RenderTarget &rt);

    virtual bool isInitialized() const;

    virtual Type type() const;

    virtual bool isDone() const;

    virtual std::string name() const;

    virtual RunState* nextState() const;

protected:
    std::string m_name;
    bool        m_isDone;
    bool        m_isInitialized;
};

#endif // MENUSTATE_HPP
