#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
    public:
        Animation();
        virtual ~Animation();

    protected:

    private:
    sf::Vector2u imcount;
};

#endif // ANIMATION_H
