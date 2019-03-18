#ifndef JUEGO_H
#define JUEGO_H
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#define UPDATE_TICK_TIME 1000/5
using namespace std;


class Juego
{
    public:
    Juego(int resol_x, int resol_y, string gamename);
    void loop();
    void render(double i);//Se le pasa la interpolacion
    void updateGameState(sf::Time et);
    void handleEvents();
    void handleInputs(sf::Keyboard::Key key, bool isPressed);





    private:
    /**GLOBAL **/
    static const sf::Time	timePerFrame;
    /**GLOBAL **/

    sf::RenderWindow * ventana;
    sf::Text Text;
    //Material interpolacion
    sf::Clock clock;
    sf::Clock updateClock;
    sf::Time elapsedTime;
    double switchFrame;
    int frame;
    //Material interpolacion
    Player pl;
    Enemy en;

    bool			eUp;
    bool			eDown;
    bool			eRight;
    bool			eLeft;
    double acelX,acelY;//aceleracion
    double interpolation;

};

#endif // JUEGO1_H
