//#include "../include/main.hpp"
//
#include "../include/TPlayer.hpp"

Player::Player (sf::String F, float X, float Y, float W, float H)                 
               : h  ( H ),  w ( W ),                                              
                 x  ( X ),  y ( Y ), File  ( F ),                                 
                dx  ( 0 ), dy ( 0 ), speed ( 0 ), dir ( 0 )                       
    {                                                                         
        image.loadFromFile  ("img/" + File);                          
        image.createMaskFromColor (sf::Color(41,33,59)); // убрать темную тень под героем
                                                                                
        texture.loadFromImage (image);                                
        sprite.setTexture    (texture);                               
                                                                                
                                 sprite.setTextureRect(sf::IntRect(0,0,w,h)); //IntRect это привидение типов
                                                      //спрайт для вывода одного льва
      } // Player (file,x,y,w,h)                                                
                                                                                
                                                                                
      void Player::update (float time)                                                  
      {                                                                         
         switch (dir)                                                           
         {                                                                      
            case 0: dx =  speed;   dy = 0; break;                               
            case 1: dx = -speed;   dy = 0; break;                               
            case 2: dx = 0;   dy =  speed; break;                               
            case 3: dx = 0;   dy = -speed; break;                               
            default:break;                                                      
         }                                                                      
         x += dx * time; // происходит изменение координат и как следствие      
         y += dy * time; // происходит движение игрока                          
                                                                                
         speed = 0;      // что бы персонаж остановился                         
         sprite.setPosition ( x, y ); // перемещаем персонажа в новую позицию   
      }//update (time)                                                          
                                                                                

