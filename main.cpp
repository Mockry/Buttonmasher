//Included libraries
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>


int main()
{
	//--------------------------------------
	// Game Setup

	// Make a variable called gameWindow of the type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
		sf::Style::Titlebar | sf::Style::Close);
	
	// Create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	//create music
	/*sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	gameMusic.play();*/



	// centers the sprite on the screen
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	//Create Font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	// create text
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher");
	titleText.setCharacterSize(36);
	titleText.setFillColor(sf::Color::Magenta);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);


	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("David Melville");
	authorText.setPosition(gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 80);

	int score = 0;

	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(sf::Color::Red);
	scoreText.setPosition(30, 30);


	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: 0");
	timerText.setCharacterSize(30);
	timerText.setFillColor(sf::Color::Red);
	timerText.setPosition(gameWindow.getSize().x - timerText.getLocalBounds().width - 30, 30);
	
	//Timer functionality
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;



	//--------------------------------------







	// Game Loop
	while (gameWindow.isOpen()) 
	{

		// check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{

			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x,gameEvent.mouseButton.y))
				{
					//We clicked the button!!!
					score = score + 1;
				}
			}

		
			// check if the event is the the close event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}

		// TODO:: update game state
		sf::Time frameTime = gameClock.restart();
		timeRemaining -= frameTime;
		timerText.setString("Time Remaining: " + std::to_string((int)std::ceilf(timeRemaining.asSeconds())));



		scoreText.setString("Score: " + std::to_string(score));


		
		// set background colour
		gameWindow.clear(sf::Color::Cyan);

		//draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(scoreText);
		gameWindow.draw(authorText);
		gameWindow.draw(timerText);
		// Display the contents of the window on the screen
		gameWindow.display();

	}


	//exit point for the program
	return 0;
}