#pragma once
#include "main.hpp"
#include "TMapWidget.hpp"

namespace Lessons {

    class TApplication{

          protected:
                    sf::RenderWindow  * Window;
                          TMapWidget  * MapWidget;                    

          public:
                    TApplication ( );
                   ~TApplication ( );

                     void Init ( ); // инициализация
                     void Run  ( ); // рабочий цикл
                     void End  ( ); // деинициализация

    }; //class TApplication
} // namespace Lesson
