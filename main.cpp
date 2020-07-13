#include "./include/main.hpp"
#include "./include/TPlayer.hpp"
#include "./include/TApplication.hpp"
#include "./include/mapinit.hpp"
#include "./include/map.hpp"
#include "./include/variables.hpp"


#include <SFML/System/String.hpp>
#include <iostream>

using std::cout;

int main ( ) 
{
 sf::RenderWindow  window (sf::VideoMode ( WIDTH_WINDOW, HEIGHT_WINDOW),                                  //
                              "Lesson 3");// размер окна                            //

        sf::Image  map_image;                                                       //
               if  (!map_image.loadFromFile ("./img/map.png"))                      //
                    std::cout<<"ERRRORRR";                                          //
    
      sf::Texture  map;                                                             //
                   map.loadFromImage (map_image);                                   //
    
       sf::Sprite  s_map;                                                           //
                   s_map.setTexture (map);                                          //

           Player  p ("hero.png", 250, 250, 96.0, 96.0);                            //

        sf::Clock  clock;                                                           //
            float  time;                                                            //
            float  CurrentFrame = 0;                                                //
                 
            
/////////////////////////////////////////////////////////

    while (window.isOpen())
    {
        time   =  clock.getElapsedTime().asMicroseconds();
        time  /=  400;
        clock.restart ( );

        sf::Event  event;
            while  ( window.pollEvent ( event ))
            {
               if  (event.type == sf::Event::Closed)
                    window.close();
            } // while (pollEvent)

//////////////////////////////////////////////////////////


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
        window.clear(); 

        /////////////////////////////////////////////////////////////////

        
    for (int i=0; i<HEIGHT_MAP; i++) 
        for (int j=0; j<WIDTH_MAP; j++) 
        {
            if (TileMap[i][j]==' ') s_map.setTextureRect (sf::IntRect ( 0,0,32,32));
            if (TileMap[i][j]=='s') s_map.setTextureRect (sf::IntRect (32,0,32,32));
            if (TileMap[i][j]=='0') s_map.setTextureRect (sf::IntRect (64,0,32,32));

            s_map.setPosition(i*32, j*32);

            window.draw (s_map);
        }
        window.draw  (p.sprite);
        window.display();

    }//while (isopen)
} // main ()

