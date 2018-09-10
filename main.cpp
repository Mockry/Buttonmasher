//Included libraries
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>



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


	//--------------------------------------







	// Game Loop
	while (gameWindow.isOpen()) 
	{

		// check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
		
			// check if the event is the the close event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}

		// TODO:: update game state

		//TODO: Draw graphics
		// set background colour
		gameWindow.clear(sf::Color::Cyan);

		//draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);

		gameWindow.draw(authorText);

		// Display the contents of the window on the screen
		gameWindow.display();

	}


	//exit point for the program
	return 0;
}