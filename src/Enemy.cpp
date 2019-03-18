#include "Enemy.h"

Enemy::Enemy(): rState(),pState()
{
    //inicializamos matriz de frames
    frames.resize(4);
    for (int i = 0 ; i < 4 ; i++)
		frames[i].resize(2);

    frames[0][0]=sf::IntRect(5, 7,44, 38);//Frente 0----0

    frames[1][0]=sf::IntRect(5,49,44, 37);//Detras 0----2

    frames[2][0]=sf::IntRect(99, 7,44, 38);//SideR 0-----4

    frames[3][0]=sf::IntRect(99, 49,43, 37);//SideL 0-----6


    //La carga de texturas podria ser otra clase
    tex.loadFromFile("resources/ufo.png");
    if (!tex.loadFromFile("resources/ufo.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }

    dir=1;
    frame=0;

    rState.SetTexture(tex);
    rState.SetSprite(28/2,44/2,frames[0][0],320,240,1.5);
}

int Enemy::getFrame(){
return frame;
}

void Enemy::setFrame(int f){
frame=f;
}
void Enemy::setDir(int d,int f)
{
    if(d>=0&&f>=0)
    {
        dir=d;
        frame=f;
    }
}

void Enemy::updateEnemy(double px, double py, sf::Time et)
{
double x=0.0,y=0.0,d=0;

//move the nerd towards the player
		if (px> pState.getPosNow()[0]){x+=20.0,y+=0.0; d=2; }
        else if (px< pState.getPosNow()[0]){x+=-20.0,y+=0.0; d=3; }
        if(py>pState.getPosNow()[1]) {y+=20.0,x+=0.0; d=0;}
		else if(py < pState.getPosNow()[1]){y+=-20.0,x+=0.0; d=1; }
		dir=d;
		pState.setVel(x,y,true);

cout<<"Desplaza en x: "<<x<<endl;
cout<<"Desplaza en y: "<<y<<endl;




    pState.updateState(et);

}

void Enemy::drawEnemy(sf::RenderWindow& w, double i)
{

    rState.SetRect(frames[dir][frame]);
    rState.Draw(w, pState.getPosBef(), pState.getPosNow(), i);
}

Enemy::~Enemy()
{
    //dtor
}
