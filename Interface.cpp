#include "Interface.h"


sf::RenderWindow* createWindow(){
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Movie Matchmaker!", sf::Style::Titlebar | sf::Style::Close);

    sf::RectangleShape rectangleGenre;
    rectangleGenre.setSize(sf::Vector2f(300, 150));
    rectangleGenre.setPosition(sf::Vector2f((desktop.width / 2) - 450, (desktop.height / 2) - 75));
    rectangleGenre.setFillColor(sf::Color::White);
    rectangleGenre.setOutlineColor(sf::Color::White);
    rectangleGenre.setOutlineThickness(2);

    sf::RectangleShape rectangleYear;
    rectangleYear.setSize(sf::Vector2f(300, 150));
    rectangleYear.setPosition(sf::Vector2f((desktop.width / 2) + 150, (desktop.height / 2) - 75));
    rectangleYear.setFillColor(sf::Color::White);
    rectangleYear.setOutlineColor(sf::Color::White);
    rectangleYear.setOutlineThickness(2);

    sf::Font font;
    font.loadFromFile("../short-baby-font/ShortBaby-Mg2w.ttf");
    sf::Text title("Welcome to the Movie Matchmaker", font);
    title.setStyle(sf::Text::Bold);
    title.setCharacterSize(70);
    title.setPosition((desktop.width / 2) - 600, 50);

    sf::Text instructions("Here We Will Return a Sorted Selection of Movie Recommendations! \n Please Choose a Sorting Category: Year or Genre", font);
    instructions.setCharacterSize(40);
    instructions.setPosition((desktop.width/2) - 600, 200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Color background(153, 153, 255);
        window.clear(background);
        window.draw(title);
        window.draw(instructions);
        window.draw(rectangleGenre);
        window.draw(rectangleYear);
        window.display();
    }

    return 0;
}


void Interface::resetWindow(sf::RenderWindow &window) {
}