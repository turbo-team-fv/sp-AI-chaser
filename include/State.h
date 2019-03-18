#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;


class State
{
    public:
        State();
        virtual ~State();

    vector<double> getPosBef();
    vector<double> getPosNow();
    vector<double> getVel();

    void setPosBef(double x, double y);
    void setPosNow(double x, double y);
    void setVel(double ax,double ay,bool acelerado);


    void updateState(sf::Time et);

    protected:


    private:
    vector<double> posNow,posBef;
    vector<double> vel;
};

#endif // STATE_H
