#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <string>
#include <iostream>
#include "./include/main.hpp"
#include "./include/TApplication.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
using std::cout;


class Player 
{
public:
      float x,y,w,h,dx,dy,speed;// координаты игрока х,у;ускорение dx xy
      int dir;

      sf::String   File;
      sf::Image    image;
      sf::Texture  texture;
      sf::Sprite   sprite;

      Player (sf::String F, float X, float Y, float W, float H)
      {
            dx = 0; dy = 0; speed = 0; dir = 0;
          File = F;
             w = W; h = H;
        
          image.loadFromFile  ("img/" + File);
          image.createMaskFromColor (sf::Color(41,33,59)); // убрать темную тень под героем

        texture.loadFromImage (image);
         sprite.setTexture    (texture);

         x = X; y = Y;

         sprite.setTextureRect(sf::IntRect(0,0,w,h)); //IntRect это привидение типов
                                                      //спрайт для вывода одного льва
      } // Player (file,x,y,w,h)


      void update (float time)
      {
         switch (dir)
         {
            case 0: dx =  speed;  dy = 0; break;
            case 1: dx = -speed;  dy = 0; break;
            case 2: dx = 0;  dy =  speed; break;
            case 3: dx = 0;  dy = -speed; break;
            default:break;
         }
         x += dx * time; // происходит изменение координат и как следствие
         y += dy * time; // происходит движение игрока
         
         speed = 0;      // что бы персонаж остановился
         sprite.setPosition ( x, y ); // перемещаем персонажа в новую позицию
      }//update (time)
};


int main ( ) 
{
    Player p("hero.png", 250, 250, 96.0, 96.0);

    sf::RenderWindow  window (sf::VideoMode(1200,800),
                              "Lesson 3");// размер окна

           sf::Image  heroimage;
                 if(! heroimage.loadFromFile  ("img/hero.png"))
                 {
                      // если картинка не найдена рисуем квадрат
                      heroimage.create  (50, 50, sf::Color (100,100,100) );
                 }

         sf::Texture  herotexture;
                      herotexture.loadFromImage ( heroimage ); 

         heroimage.~Image();// после создания текстуры heroimage нам не нужен

          sf::Sprite  herosprite;
                      herosprite.setTexture   ( herotexture );
                      herosprite.setTextureRect (sf::IntRect(0,192,96,96));
                      herosprite.setPosition  ( 50,25 );


    sf::Clock  clock;
        float  time;
        float  heroteleporttimer = 0;
        float  CurrentFrame = 0;

    while (window.isOpen())
    {

        time  = clock.getElapsedTime().asMicroseconds();
        time /= 400;
        heroteleporttimer += time;
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
        p.sprite.setScale(2,2);
        window.clear   ( );
        window.draw    ( p.sprite );
        window.display ( );

    }//while (isopen)

} // main ()

