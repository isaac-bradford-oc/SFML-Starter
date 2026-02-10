#include "Circle.h"


int main()
{
	// The next two commands create a graphical window on your system
	// The "window" is a variable that describes and controls the displayed window
	RenderWindow window(VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Some circles");
	window.setFramerateLimit(60);
		
	// As long as the window "isOpen", then keep running this loop
	// this loop will check for an event where the user closed the screen
	//   -- close the screen by clicking the X in the upper right of the window
	while (window.isOpen())
	{
		// this while loop checks to see if an "event" occured. 
		// it's looking for the X (close window icon) has been clicked. 
		// if the X has been clicked then it close the window. 
		while (const std::optional event = window.pollEvent()) // as long as there are events, deal with them.
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		/*
		* The main loop is very simple
		*   -- First clear the window and fill it with black for a background
		*   -- Then draw all the images (circles here) on the screen. -- THIS 
		*      DOES NOT draw on the screen. It draws on the window, which 
		*      is not yet displayed. 
		*   -- after you have drawn on the window, display this window. 
		* In this way you can animate things later. 
		*/
		window.clear(Color::Black);

		// Create two variables which are widgets or draw objects. 
		//   both of these are circles. 
		//     makeCircle is passed the radius, and then the upper left x and y
		array<CircleShape, 20> circles;
		int radius = 60;
		int diameter = radius * 2;
		int startX = 5;
		int startY = 5;
		int rowLen = 5;

		for (size_t i = 0, x = startX, y = startY; i < circles.size(); i++) {
			x += diameter;
			if (i % rowLen == 0) { x = startX; y += diameter; }
			circles[i] = (makeCircle(radius, x, y));
			window.draw(circles[i]);
		} 

		// end the current frame; put everything on the screen
		window.display();
	}
	return 0;
}