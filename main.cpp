#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
//#include <SFML/OpenGL.hpp>

#include <iostream>
#include <math.h>

//https://www.raywenderlich.com/2736-trigonometry-for-game-programming-part-1-2

class sprite_object {
  public:
    sf::Sprite image;
    sf::Vector2f location;
    sf::Vector2f scale;
    sf::Vector2f origin;
    float rotation;

};

int map_data[] = { 17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,17,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,
17,17,17,17,513,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,17,17,17,17,17,17,
17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,17,17,17,17,
17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,17,17,17,17,
17,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,17,17,17,
17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,17,17,17,
17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,17,17,17,
17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,102,17,17,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,310,311,311,311,311,311,312,0,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,5,17,17,
17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,17,17,0,0,0,0,0,0,17,17,
17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,17,17,
17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,513,17,17,17,17,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,17,513,0,0,0,0,0,0,0,0,0,4,17,17,1056,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,17,17,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,17,17,0,0,0,0,0,0,0,216,17,17,
17,17,17,0,0,0,17,17,17,17,0,0,0,0,0,0,0,4,17,17,17,17,17,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,5,17,17,17,17,17,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,17,17,17,
17,17,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,17,17,17,1055,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,
17,17,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,
17,17,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,17,17,17,0,0,17,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,5,17,17,17,
17,17,17,0,0,17,17,17,17,17,17,0,0,0,0,0,0,17,17,17,5,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,17,4,5,17,17,17,
17,17,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,17,17,
17,17,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,17,17,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,4,17,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,
17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1053,17,
17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,102,0,0,0,0,0,0,17,17,17,
17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,
17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,
17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,513,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,17,0,0,0,0,0,0,0,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,17,17,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,17,17,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1051,17,17,17,17,
17,17,17,17,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,
17,17,17,0,0,0,0,0,17,17,17,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,17,0,0,0,0,0,17,17,0,0,0,0,0,0,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,216,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,17,0,0,0,0,0,17,17,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,17,17,17,17,17,17,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,1054,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,17,0,0,0,0,0,310,311,311,311,312,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,
17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,513,17,17,17,17,
17,17,17,17,17,17,513,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,17,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,17,17,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,
17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,
17,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,17,17,4,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,17,17,17,4,216,0,0,0,0,0,0,0,0,0,0,0,17,17,17,
17,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,5,0,0,0,0,0,0,0,0,0,0,0,0,2,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,102,17,17,
17,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,4,0,0,0,0,0,0,0,0,97,17,17,17,
17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,17,17,17,5,0,0,0,0,0,0,0,0,17,17,17,17,
17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,17,17,17,17,
17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,0,17,17,17,
17,215,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,0,17,17,
17,17,0,0,0,0,0,0,0,0,0,215,17,17,17,17,17,17,17,17,102,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,0,17,17,
17,17,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,5,0,0,0,0,0,0,0,17,17,
17,17,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,0,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,17,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,17,
17,17,17,17,1052,0,0,0,0,0,0,1,1,1,582,583,583,583,584,0,0,0,0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0,625,625,625,625,625,625,625,625,0,0,17,17,
17,17,17,17,17,17,17,0,0,0,0,0,0,1,17,631,631,631,1,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,532,0,0,0,0,532,0,0,215,17,17,
17,17,17,17,17,17,17,17,0,0,0,0,0,17,17,17,17,631,1,0,0,0,0,0,0,0,0,17,17,17,17,17,17,0,0,0,0,0,0,580,0,0,0,0,580,0,0,17,17,17,
17,17,17,17,17,17,17,17,17,0,0,0,0,17,17,17,17,631,727,0,0,0,0,0,513,0,17,17,17,17,17,17,17,17,0,0,0,0,0,628,0,0,0,0,580,0,0,17,17,17,
17,17,17,17,17,17,17,17,17,0,215,215,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,215,215,0,17,17,17,0,0,0,0,580,0,17,17,17,17,
17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,0,0,628,17,17,17,17,17,
17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17};

sf::IntRect spriteid2texturelocation(int id) {

    int x = id % 48;
    int y = id / 48;
    //std::cout << "X: " << x << " Y: " << y << std::endl;
    return sf::IntRect(16*x, 16*y, 16, 16);
}


int main()
{

    float playerRot = 0.0f;
    sf::Vector2f playerLoc = {280.0f,400.0f};

    std::vector<sprite_object> spritelist = {};

    sf::Music music;
    if (!music.openFromFile("Chiptunes/Level 3.wav")) {
        std::cout << "Could not load music" << std::endl;
        return -1;
    }
    music.setLoop(true);
    //music.play();

    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("sci-fi-sounds/Audio/engineCircular_004.ogg")) {
        std::cout << "Could not load sound effects" << std::endl;
        return -1;
    }
    sound.setBuffer(buffer);
    //sound.play();
    
    sf::Texture sprite_sheet_texture;
    // load a 32x32 rectangle that starts at (10, 10)
    //if (!texture.loadFromFile("image.png", sf::IntRect(10, 10, 32, 32)))
    if (!sprite_sheet_texture.loadFromFile("1bitpack_kenney_1.1/Tilesheet/colored_transparent_packed.png")) {
        std::cout << "Could not load textures" << std::endl;
        return -1;
    }
    sprite_sheet_texture.setSmooth(false);

    sf::Sprite sheet_spr;
    sheet_spr.setTexture(sprite_sheet_texture);

    sf::Sprite player_spr;
    player_spr.setTexture(sprite_sheet_texture);
    player_spr.setTextureRect(sf::IntRect(16*28, 16*21, 16, 16));
    player_spr.setOrigin ( 8,8 );

    sf::Sprite wall_spr;
    wall_spr.setTexture(sprite_sheet_texture);
    wall_spr.setTextureRect(sf::IntRect(16*16, 16*0, 16, 16));
    wall_spr.setOrigin ( 8,8 );

    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
    window.setMouseCursorVisible(false);

    // activate the window
    window.setActive(true);

    sf::Clock clock;
    while (window.isOpen())
    {

        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                // glViewport(0, 0, event.size.width, event.size.height);
            }
        }



        // Collect all inputs here
        sf::Time elapsed = clock.restart();
        float fElapsedSecs  = elapsed.asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            //std::cout << "Mouse button pressed\n." << std::endl;
        }

        if (sf::Joystick::isConnected(0))
        {
            float joyx = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
            float joyy = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

            //std::cout << joyx << " : " << joyy <<std::endl;

            playerRot = playerRot + (joyx *  fElapsedSecs);
            
            if (playerRot < 0 ) {
                playerRot = playerRot + +360.0f;
            }
            if (playerRot > 360.0f ) {
                playerRot = playerRot - 360.0f;
            }

            playerLoc.x = playerLoc.x - ( sin(playerRot * M_PI / 180.0f) * fElapsedSecs * joyy);
            playerLoc.y = playerLoc.y + ( cos(playerRot * M_PI / 180.0f) * fElapsedSecs * joyy);

        }





        // update all locations and rotations
        sf::Vector2f locOffset = playerLoc;
        locOffset.x = locOffset.x + 32;
        locOffset.y = locOffset.y + 32;
        player_spr.setPosition(locOffset);
        player_spr.setRotation(playerRot);

        // clear the buffers
        window.clear();

        // draw sprites;
        //window.draw(sheet_spr);
        for (int y = 0; y < 45;y++) {
            for (int x = 0; x < 50;x++) {
                if (map_data[y*50+x] != 0) {
                    wall_spr.setPosition(32+x*16,32+y*16);
                    window.draw(wall_spr);
                }
            }
        }
        window.draw(player_spr);

         // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}