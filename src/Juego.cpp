#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace std;

/** GLOBAL **/
const sf::Time Juego::timePerFrame = sf::milliseconds(1000.0/25.0);
/** GLOBAL **/

Juego::Juego(int resol_x, int resol_y, string gamename)
{

    ventana= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    //ventana->setFramerateLimit(100);
    ventana->setVerticalSyncEnabled(true); //Para evitar cortes en los refrescos

    eUp=false;
    eDown=false;
    eLeft=false;
    eRight=false;

    switchFrame=0.2;
    frame=0;
}
void Juego::loop()
{

    while (ventana->isOpen())
    {


        //Proceso mis eventos

        handleEvents();


        if(updateClock.getElapsedTime().asMilliseconds()>timePerFrame.asMilliseconds())
        {
            //Calculamos el tiempo desde el ultimo update
            elapsedTime=updateClock.restart();

            //updateamos dependiendo del tiempo pasado
            updateGameState(elapsedTime);
        }

        //Se calcula el porcentaje de interpolacion
        interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());

        //Renderizamos con interpolacion
        render(interpolation);


    }

}


void Juego::handleEvents()
{

    sf::Event event;
    if (ventana->pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::KeyPressed:

            handleInputs(event.key.code, true);
            break;

        case sf::Event::KeyReleased:

            handleInputs(event.key.code, false);
            break;

        case sf::Event::Closed:
            ventana->close();
            break;
        }
    }

}

void Juego::handleInputs(sf::Keyboard::Key key, bool isPressed)
{

    if (key == sf::Keyboard::Up)            //Traslaciones
        eUp = isPressed;
    else if (key == sf::Keyboard::Down)
        eDown = isPressed;
    else if (key == sf::Keyboard::Left)
        eLeft = isPressed;
    else if (key == sf::Keyboard::Right)
        eRight = isPressed;

}

void Juego::updateGameState(sf::Time t)
{

    double x=0,y=0,potencia=50;

    if(t.asSeconds()>timePerFrame.asSeconds())
    {
        frame+=1;
        if(frame>1)
        {
            frame=-1;
        }
    }

    if(eRight)
    {
        x=potencia;
        y=0.0;
        pl.setDir(2,frame);
    }
    else if(eLeft)
    {
        x=-potencia;
        y=0.0;
        pl.setDir(3,frame);//Decimos a donde esta mirando el sprite
    }
    else if(eUp)
    {
        x=0.0;
        y=-potencia;
        pl.setDir(1,frame);//Decimos a donde esta mirando el sprite
    }
    else if(eDown)
    {
        x=0.0;
        y=potencia;;
        pl.setDir(0,frame);//Decimos a donde esta mirando el sprite

    }


    pl.updatePlayer(x,y,t);
    en.updateEnemy(pl.getState().getPosNow()[0],pl.getState().getPosNow()[1],t);

}

void Juego::render(double i)
{
    ventana->clear();
    pl.drawPlayer(*ventana,i);
    en.drawEnemy(*ventana,i);
    ventana->display();
}




