#include "../include/TApplication.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>


namespace Lessons
{

    TApplication:: TApplication () :    Window ( nullptr ),
                                     MapWidget ( nullptr ) { }
    
    TApplication::~TApplication () { }


    void TApplication::
    Init ( ) {
            if ( Window == nullptr)   {
                 Window = new sf::RenderWindow 
                            ( sf::VideoMode (640,480),
                                     "4x tbs Lesson");
              MapWidget = new TMapWidget(0,0,640,640);
            }
    }//Init() 
    

    void TApplication::
    Run ( ) {
             while (Window->isOpen()) {   // пока окно открыто
                     sf::Event event;     // содержит события:
                                          // перемещение мыши
                                          // нажатие клавиши
                                          // закрытие окна
                     while (Window->pollEvent(event)) // очередь событий
                     {                                // что сейчс наверху
                            if (event.type == sf::Event::Closed)//
                                Window->close();        // если наверху событий заркть
                                                        // закрыть окно.
                     } // while window.poolevent 
                     
                        Window->clear   ( sf::Color::Black ); // обычно вызывается один раз в каждом кадре (очищает предыдущий кадр)
                     MapWidget->Draw    ( Window );
                        Window->display ( );
             }//while window.isOpen()    
    }//Run() 


    void TApplication::
    End ( ) {
            if (Window != nullptr)
            {
                delete Window;
                Window = nullptr;
            }
            if (MapWidget != nullptr)
            {
                delete MapWidget;
                MapWidget = nullptr;
            }
    }// End ( )

    
}// namespace Lesson
