#include "Enemy.h"

Enemy::Enemy(): rState(),pState()
{
    //inicializamos matriz de frames
    frames.resize(4);
    for (int i = 0 ; i < 4 ; i++)
		frames[i].resize(2);

    frames[0][0]=sf::IntRect(10, 4,28, 44);//Frente 0----0
    frames[0][1]=sf::IntRect(58, 6,28, 42);//Frente 1----1
    frames[1][0]=sf::IntRect(8,146,32, 46);//Detras 0----2
    frames[1][1]=sf::IntRect(56, 148,32, 44);//Detras 1--3
    frames[2][0]=sf::IntRect(6, 98,40, 46);//SideR 0-----4
    frames[2][1]=sf::IntRect(54, 100,40, 44);//SideR 1---5
    frames[3][0]=sf::IntRect(2, 50,40, 46);//SideL 0-----6
    frames[3][1]=sf::IntRect(50, 52,40, 44);//SideL 1----7

    //La carga de texturas podria ser otra clase
    tex.loadFromFile("resources/sp_alien_texture.png");
    if (!tex.loadFromFile("resources/sp_alien_texture.png"))
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
double x=0.0,y=0.0;

//move the nerd towards the player
		if (px> pState.getPosNow()[0]){x+=20.0,y+=0.0; }
        else if (px< pState.getPosNow()[0]){x+=-20.0,y+=0.0; }
        if(py>pState.getPosNow()[1]) {y+=20.0,x+=0.0;}
		else if(py < pState.getPosNow()[1]){y+=-20.0,x+=0.0; }
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
