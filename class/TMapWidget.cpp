#include "../include/TMapWidget.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

TMapWidget::
TMapWidget ( int aX,     int aY,
             int aWidth, int aHeight) :
                         X     ( aX ),     Y      ( aY ),
                         Width ( aWidth ), Height ( aHeight ),

                         SomeTexture () 
                         {
                               SomeTexture.loadFromFile("./img/Grassland.png");
                         }

TMapWidget::
~TMapWidget() {}


// созадем правила отрисовки
void TMapWidget::
Draw (sf::RenderWindow *Window)
{
    // Sprite наследуется от Drawable и tansformable
    // позволяет легко отображать текстуру или ее часть
     sf::Sprite SpriteStuff;
                SpriteStuff.setTexture  ( SomeTexture );
                SpriteStuff.setPosition ( X, Y );

     // задаем размеры нашей текстуры
     float WidgetWidth  = (float) Width  / (float) SomeTexture.getSize().x;
     float WidgetHeight = (float) Height / (float) SomeTexture.getSize().y;
    
     SpriteStuff.setScale ( WidgetWidth, WidgetHeight );

     Window->draw ( SpriteStuff );
}//Draw()



