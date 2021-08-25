#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
//#include <SFML/OpenGL.hpp>

#include <iostream>


sf::IntRect spriteid2texturelocation(int id) {

    int x = id % 48;
    int y = id / 48;
    //std::cout << "X: " << x << " Y: " << y << std::endl;
    return sf::IntRect(16*x, 16*y, 16, 16);
}

int main()
{

    sf::Music music;
    if (!music.openFromFile("Chiptunes/Level 3.wav")) {
        std::cout << "Could not load music" << std::endl;
        return -1;
    }
    music.play();

    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("sci-fi-sounds/Audio/engineCircular_004.ogg")) {
        std::cout << "Could not load sound effects" << std::endl;
        return -1;
    }
    sound.setBuffer(buffer);
    //sound.play();
    
    sf::Texture texture;
    // load a 32x32 rectangle that starts at (10, 10)
    //if (!texture.loadFromFile("image.png", sf::IntRect(10, 10, 32, 32)))
    if (!texture.loadFromFile("1bitpack_kenney_1.1/Tilesheet/colored_transparent_packed.png")) {
        std::cout << "Could not load textures" << std::endl;
        return -1;
    }
    texture.setSmooth(false);

    sf::Sprite full;
    full.setTexture(texture);

    sf::Sprite sprite1;
    sf::Sprite sprite2;

    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
        }

        sf::Time elapsed = clock.restart();
        float fElapsedSecs  = elapsed.asSeconds();

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        int charid;
        charid = ((localPosition.y / 16) * 48)+ (localPosition.x / 16) ;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            //std::cout << x << " : " << y << std::endl;
        }


        if (sf::Joystick::isConnected(0))
        {
            float joyx = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
            float joyy = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
        }

//        16,0  //wallpiece
//        28,1  //playerchar

        sprite1.setTexture(texture);
        sprite1.setTextureRect(spriteid2texturelocation(16));
        //sprite.setOrigin(texture.getSize().x/2.0f, texture.getSize().y/2.0f);
        sprite1.setPosition(sf::Vector2f(512,600));
        sprite1.setScale(8.0f, 8.0f);
        // position
        //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
        //sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

        // rotation
        //sprite.setRotation(90.f); // absolute angle
        //sprite.rotate(15.f); // offset relative to the current angle
        //sprite.rotate(5.0f*fElapsedSecs); // offset relative to the current angle

        // scale
        //sprite.setScale(sf::Vector2f(0.5f, 2.f)); // absolute scale factor
        //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale

        sprite2.setTexture(texture);
        sprite2.setTextureRect(spriteid2texturelocation(charid));
        sprite2.setPosition(sf::Vector2f(256,600));
        sprite2.setScale(8.0f, 8.0f);


        // clear the buffers
        window.clear();

        // draw...
        window.draw(full);
        window.draw(sprite1);
        window.draw(sprite2);

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}