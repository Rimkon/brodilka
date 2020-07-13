#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "./include/main.hpp"
#include "./include/TPlayer.hpp"
#include "./include/TApplication.hpp"
#include "./include/mapinit.hpp"

#include "./include/map.hpp"

#include <iostream>

using std::cout;


int main ( ) 
{
    sf::RenderWindow  window (sf::VideoMode(640,480),
                              "Lesson 3");// размер окна

//    sf::Sprite s_map = mapinit  ("img/map.png");

        sf::Image  map_image;
           if (!map_image.loadFromFile ("./img/map.png"))
               std::cout<<"ERRRORRR";

  sf::Texture  map;
               map.loadFromImage (map_image);

   sf::Sprite  s_map;
               s_map.setTexture (map);

              Player  p ("hero.png", 250, 250, 96.0, 96.0);

           sf::Clock  clock;
               float  time;
               float  CurrentFrame = 0;
                 

/////////////////////////////////////////////////////////
    while (window.isOpen())
    {
 
   // s_map.setTextureRect (sf::IntRect ( 0,0,32,32));
    //s_map.setPosition    (199,199);
                
    for (int i=0; i<HEIGHT_MAP; i++) 
        for (int j=0; j<WIDTH_MAP; j++) 
        {
            if (TileMap[i][j]==' ') s_map.setTextureRect (sf::IntRect ( 0,0,32,32));
            if (TileMap[i][j]=='s') s_map.setTextureRect (sf::IntRect (32,0,32,32));
            if (TileMap[i][j]=='0') s_map.setTextureRect (sf::IntRect (64,0,32,32));

            s_map.setPosition(i*32, j*32);

            window.draw (s_map);
        }

                 ///////////////////////


           sf::Image  heroimage;
                 if(! heroimage.loadFromFile  ("img/hero.png"))
                 {
                      // если картинка не найдена рисуем квадрат
                      heroimage.create  (50, 50, sf::Color (100,100,100) );
                 }

         sf::Texture  herotexture;
                      herotexture.loadFromImage ( heroimage ); 

 
          sf::Sprite  herosprite;
                      herosprite.setTexture   ( herotexture );
                      herosprite.setTextureRect (sf::IntRect(0,192,96,96));
                      herosprite.setPosition  ( 50,25 );




        time  = clock.getElapsedTime().asMicroseconds();

        time /= 400;
        clock.restart ( );

        sf::Event  event;

        while  ( window.pollEvent ( event ))
        {
               if (event.type == sf::Event::Closed)
                   window.close();
        } // while (pollEvent)


        if (( sf::Keyboard::isKeyPressed ( sf::Keyboard::Left  )) || 
            ( sf::Keyboard::isKeyPressed ( sf::Keyboard::H    ))) 
        { 
            p.dir   = 1; 
            p.speed = 0.1;
            
            CurrentFrame += 0.005 * time;

            if (CurrentFrame > 3) 
                CurrentFrame -=3;

            p.sprite.setTextureRect (sf::IntRect(96*int(CurrentFrame),96,96,96));

        }//if (left)


        if (( sf::Keyboard::isKeyPressed ( sf::Keyboard::Right )) ||
            ( sf::Keyboard::isKeyPressed ( sf::Keyboard::L    ))) 
        { 
            p.dir   = 0; 
            p.speed = 0.1;
            
            CurrentFrame += 0.005 * time;

            if (CurrentFrame > 3) 
                CurrentFrame -=3;

            p.sprite.setTextureRect (sf::IntRect(96*int(CurrentFrame),192,96,96));

        }//if (right)
        

        if (( sf::Keyboard::isKeyPressed ( sf::Keyboard::Up  )) || 
            ( sf::Keyboard::isKeyPressed ( sf::Keyboard::K  ))) 
        { 
            p.dir   = 3; 
            p.speed = 0.1;

            CurrentFrame += 0.005 * time;

            if (CurrentFrame > 3) 
                CurrentFrame -=3;

            p.sprite.setTextureRect (sf::IntRect(96*int(CurrentFrame),288,96,96));
            
        }//if (Up)

        if (( sf::Keyboard::isKeyPressed ( sf::Keyboard::Down  )) || 
            ( sf::Keyboard::isKeyPressed ( sf::Keyboard::J    ))) 
        { 
            p.dir   = 2; 
            p.speed = 0.1;

            CurrentFrame += 0.005 * time;

            if (CurrentFrame > 3) 
                CurrentFrame -=3;

            p.sprite.setTextureRect (sf::IntRect(96*int(CurrentFrame),0,96,96));
            
        }//if(down)

        p.update(time);
        
        //herosprite.setScale(2,2);
//        p.sprite.setScale(2,2);
        window.clear   ( );
        window.draw(s_map);
        window.draw    ( p.sprite );
        window.display ( );



    }//while (isopen)
} // main ()

