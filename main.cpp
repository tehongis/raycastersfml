#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
//#include <SFML/OpenGL.hpp>

#include <iostream>


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
    if (!texture.loadFromFile("1bitpack_kenney_1.1/Tilesheet/colored_transparent.png")) {
        std::cout << "Could not load textures" << std::endl;
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x/2.0f, texture.getSize().y/2.0f);
    sprite.setPosition(sf::Vector2f(512,384));
    sprite.setScale(1.0f, 1.0f);
    // position
    //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
    //sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

    // rotation
    //sprite.setRotation(90.f); // absolute angle
    //sprite.rotate(15.f); // offset relative to the current angle

    // scale
    //sprite.setScale(sf::Vector2f(0.5f, 2.f)); // absolute scale factor
    //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale



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
        sf::Time elapsed = clock.restart();
        float fElapsedSecs  = elapsed.asSeconds();
        
        sprite.rotate(5.0f*fElapsedSecs); // offset relative to the current angle

        // clear the buffers
        // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.clear();

        // draw...
        window.draw(sprite);

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}