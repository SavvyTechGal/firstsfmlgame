#ifndef Game_hpp
#define Game_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"
#include <iostream>

class Game {
private:
	Window window;
	WorkingDirectory workingDir;
	Input input;
	sf::Clock clock;
    float deltaTime;
	sf::Texture vikingTexture;
    sf::Sprite vikingSprite;
    sf::Texture chestTexture;
    sf::Sprite chestSprite;
    // sf::Texture backgroundTexture.loadFromFile("background1.png")
    // sf::Sprite backgroundSprite(backgroundTexture);
    sf::Music Music1;

public:
	Game();
	void Update();
	void LateUpdate();
	void Draw();
	bool IsRunning() const;
	void CalculateDeltaTime();
	void CaptureInput();
};

#endif
