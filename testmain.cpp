#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hi Bunny", font, 50);

    //THIS CODE DOESNT WORK!
    // Load a music to play
    // sf::Music music;
    // if (!music.openFromFile("lem.oog"))
    //     return EXIT_FAILURE;
    // // Play the music
    // music.play();

    sf::Music Music1;
    if (!Music1.openFromFile("fairy.ogg"))
    {
        // Error...
        std::cout<<"Error...";
    }

    Music1.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}