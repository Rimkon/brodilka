//#include "../include/main.hpp"
#include "../include/TPlayer.hpp"
#include "../include/TApplication.hpp"
#include "../include/map.hpp"
#include "../include/mapinit.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>
#include <iostream>


sf::Sprite 
mapinit (sf::String filemap) {
        
      sf::Image  map_image;                               
             if (!map_image.loadFromFile (filemap)) 
                 std::cout<<"ERRRORRR";                        
                                                          
    sf::Texture  map;                                     
                 map.loadFromImage (map_image);           
                                                          
     sf::Sprite  s_map;
                 s_map.setTexture (map);                  

         return  s_map;                                               
} // mapinit (filemap)
