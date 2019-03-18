#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Render.h"
#define kVel 5
class Enemy
{
public:
    Enemy();
    virtual ~Enemy();
    int getFrame();
        void setFrame(int f);
        void setDir(int d,int f);
        void updateEnemy(double px, double py, sf::Time et);
        void drawEnemy(sf::RenderWindow& w, double i);

protected:

private:
    sf::Texture  tex;
    sf::Sprite spri;

    int dir,frame;
    vector< vector< sf::Rect<int> > > frames;
    Render			rState;
    State       	pState;
};

#endif // ENEMY_H
