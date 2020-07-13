#pragma once
#include "main.hpp"

class Player
{
public:
      float x,y,w,h,dx,dy,speed;// координаты игрока х,у;ускорение dx xy
      int dir;

const sf::String   File;
      sf::Image    image;
      sf::Texture  texture;
      sf::Sprite   sprite;

      Player (sf::String F, float X, float Y, float W, float H);

      void update (float time);


};//class Player

