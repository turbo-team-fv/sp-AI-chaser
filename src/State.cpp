#include "State.h"

State::State()
{

    posNow.push_back(0.0),posNow.push_back(0.0);
    posBef.push_back(0.0),posBef.push_back(0.0);
    vel.push_back(0.0),vel.push_back(0.0);

}

vector<double> State::getPosBef()
{
    return posBef;
}

vector<double> State::getPosNow()
{
    return posNow;
}


void State::setPosNow(double x, double y)
{
    posNow[0]=x,posNow[1]=y;
}
void State::setPosBef(double x, double y)
{
    posBef[0]=x,posBef[1]=y;
}
void State::setVel(double ax, double ay, bool acelerado)
{
int freno=15;
    if(acelerado)//MOTOR CON ACELERACION
    {

        vel[0]+=ax;
        vel[1]+=ay;

        if (vel[0]<=freno&&vel[0]>=-freno)
        {
            vel[0] = 0.0;
        }
        else
        {
            //decrease the speed
            if(vel[0]>freno)
                vel[0] -= freno;

            if(vel[0]<-7.0)
                vel[0] += freno;
        }

        if (vel[1]<=freno&&vel[1]>=-freno)
        {
            vel[1] = 0.0;
        }
        else
        {
            //decrease the speed
            if(vel[1]>freno)
                vel[1] -= freno;

            if(vel[1]<-freno)
                vel[1] += freno;
        }
    }
    else//MOTOR SIMPLE
    {

        vel[0]=ax;
        vel[1]=ay;
    }

}

void State::updateState(sf::Time et)
{

    posBef=posNow;

    posNow[0] += vel[0]*et.asSeconds();
    posNow[1] += vel[1]*et.asSeconds();









}

State::~State()
{
    //dtor
}
