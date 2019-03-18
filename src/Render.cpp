#include "Render.h"
using namespace std;

Render::Render() : sprite()
{
    renderPos.push_back(0.0);
    renderPos.push_back(0.0);
}

Render::Render(const Render& orig)
{
}

Render::~Render()
{
}

void Render::SetTexture(sf::Texture &tex)
{
    sprite = sf::Sprite(tex);
}

void Render::SetAnimation(int f){
aframe=f;
}

void Render::SetSprite(double u,double v,sf::IntRect s,double x, double y,double scale)
{

    sprite.setOrigin(u,v);
    sprite.setTextureRect(s);
    sprite.scale(scale,scale);


}
void Render::SetRect(sf::IntRect s){
sprite.setTextureRect(s);
}
void Render::Draw(sf::RenderWindow &window, const vector<double> &posBef,const vector<double> &posNow, double interpolation)
{


    renderPos[0]=(posNow[0]-posBef[0])*interpolation+posBef[0];
    renderPos[1]=(posNow[1]-posBef[1])*interpolation+posBef[1];

    sprite.setPosition(renderPos[0], renderPos[1]);
    window.draw(sprite);
}
