#include "Game.hpp"

Game::Game() : window("Sav's Game") {
	deltaTime = clock.restart().asSeconds();
	vikingTexture.loadFromFile(workingDir.Get() + "Valkyrie.png");
	vikingSprite.setTexture(vikingTexture);
	vikingSprite.setTextureRect(sf::IntRect(1, 1, 30, 28));
	vikingSprite.scale(sf::Vector2f(5,5));

	chestTexture.loadFromFile(workingDir.Get() + "treasure.png");
	chestSprite.setTexture(chestTexture);
	chestSprite.scale(sf::Vector2f(3,3));


    if (!Music1.openFromFile("fairy.ogg"))
    {
        // Error...
        std::cout<<"Error...";
    }
    Music1.play();
}

void Game::Update() {
	window.Update();

    // const sf::Vector2f& backPos = backgroundSprite.getPosition();
    const sf::Vector2f& spritePos = vikingSprite.getPosition();
    const sf::Vector2f& chestPos = chestSprite.getPosition();
    const int moveSpeed = 100;
    
    int xMove = 0;
    if(input.IsKeyPressed(Input::Key::Left)) // 1
    {
        xMove = -moveSpeed; // 2
    }
    else if(input.IsKeyPressed(Input::Key::Right))
    {
        xMove = moveSpeed;
    }
    
    int yMove = 0;
    if(input.IsKeyPressed(Input::Key::Up))
    {
        yMove = -moveSpeed;
    }
    else if(input.IsKeyPressed(Input::Key::Down))
    {
        yMove = moveSpeed;
    }


    float xFrameMove = xMove * deltaTime; 
    float yFrameMove = yMove * deltaTime;

    
    vikingSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
    chestSprite.setPosition(200, 300);
    // backgroundSprite.setPosition(0,0);
    while ( vikingSprite.getGlobalBounds().intersects(chestSprite.getGlobalBounds()) ){
    	chestSprite.setPosition(chestPos.x + xFrameMove, chestPos.y + yFrameMove );
    }
}

void Game::LateUpdate(){

}

void Game::Draw(){

    window.BeginDraw();
    // window.Draw(backgroundSprite);
    window.Draw(vikingSprite); // Draw the sprite.
    window.Draw(chestSprite); // Draw the sprite.
    
    window.EndDraw();

}

bool Game::IsRunning() const {

	return window.IsOpen();
}

void Game::CalculateDeltaTime() {
    deltaTime = clock.restart().asSeconds();
}

void Game::CaptureInput()
{
    input.Update();
}


