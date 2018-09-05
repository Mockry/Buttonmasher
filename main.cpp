//Included libraries
#include <SFML\Graphics.hpp>



int main()
{
	// Make a variable called gameWindow of the type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
		sf::Style::Titlebar | sf::Style::Close);



	// Game Loop
	while (gameWindow.isOpen()) 
	{
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


	}


	//exit point for the program
	return 0;
}