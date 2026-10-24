#include <SFML/Graphics.hpp>

int main() {
    // Create a 800x600 window with a title
    sf::RenderWindow window(sf::VideoMode(800, 600), "My C++ Window");

    // Main window loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window if user clicks the 'X' button
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear previous frame
        window.clear(sf::Color(30, 30, 30));

        // Display the window contents
        window.display();
    }

    return 0;
}