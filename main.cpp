#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

int main() {

    Game SavsGame;

	while (SavsGame.IsRunning()) {
		SavsGame.CaptureInput(); // We want to capture input at the start of a frame.
    	SavsGame.Update();
		SavsGame.LateUpdate();
		SavsGame.Draw();
		SavsGame.CalculateDeltaTime();
    }
}