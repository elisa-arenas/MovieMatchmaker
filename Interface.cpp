#include "Interface.h"


sf::RenderWindow* createWindow(){
    sf::RenderWindow window(sf::VideoMode(900, 700), "Movie Matchmaker!", sf::Style::Titlebar | sf::Style::Close);

    //save image as a sprite and size correctly
    sf::Texture texture;
    texture.loadFromFile("../movies.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();
    // Calculate the scale factor to fit the smaller dimension of the window
    float scaleFactor = std::min((float)windowSize.x / textureSize.x, (float)windowSize.y / textureSize.y);
    // Set the scale of the sprite
    sprite.setScale(scaleFactor, scaleFactor);
    // Center the sprite in the window
    sprite.setPosition((windowSize.x - textureSize.x * scaleFactor) / 2, 120);

    //create title
    sf::Font font;
    font.loadFromFile("../short-baby-font/ShortBaby-Mg2w.ttf");
    sf::Text title("Welcome to the Movie Matchmaker", font);
    title.setStyle(sf::Text::Bold);
    title.setCharacterSize(50);
    title.setPosition((window.getSize().x / 2) - (title.getLocalBounds().width / 2), 50);

    //create button for genre input
    sf::RectangleShape genre;
    genre.setSize(sf::Vector2f(200, 100));
    genre.setPosition(sf::Vector2f((window.getSize().x / 2) - 360, (window.getSize().y / 2) + 90));
    genre.setFillColor(sf::Color::White);
    genre.setOutlineColor(sf::Color::White);
    genre.setOutlineThickness(2);

    // Create genre button text
    sf::Text genreText("Genre", font);
    genreText.setCharacterSize(30);
    genreText.setFillColor(sf::Color::Black);
    genreText.setPosition(genre.getPosition().x + genre.getSize().x/2 - genreText.getLocalBounds().width/2,
                          genre.getPosition().y + genre.getSize().y/2 - genreText.getLocalBounds().height/2);

    bool genreSelected = false; // flag to check if genre button has been clicked
    std::string genreInput = ""; // variable to store user input for genre


    //create button for year input
    sf::RectangleShape year;
    year.setSize(sf::Vector2f(200, 100));
    year.setPosition(sf::Vector2f((window.getSize().x / 2) + 150, (window.getSize().y / 2) + 90));
    year.setFillColor(sf::Color::White);
    year.setOutlineColor(sf::Color::White);
    year.setOutlineThickness(2);

    // Create year button text
    sf::Text yearText("Year", font);
    yearText.setCharacterSize(30);
    yearText.setFillColor(sf::Color::Black);
    yearText.setPosition(year.getPosition().x + year.getSize().x/2 - yearText.getLocalBounds().width/2,
                          year.getPosition().y + year.getSize().y/2 - yearText.getLocalBounds().height/2);

    bool yearSelected = false; // flag to check if genre button has been clicked
    std::string yearInput = ""; // variable to store user input for genre


    //create instruction text
    sf::Text instructions("Here We Will Return a Sorted Selection of Movie Recommendations", font);
    instructions.setCharacterSize(20);
    instructions.setPosition((window.getSize().x / 2)/3.5, (window.getSize().y / 2)-20);
    sf::Text selection("Please Choose a Sorting Category: Year or Genre", font);
    selection.setCharacterSize(20);
    selection.setPosition((window.getSize().x / 2)/2, (window.getSize().y/2)+30);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (genre.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        genreSelected = true;
                    }
                    else if (year.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        yearSelected = true;
                    }
                }
            }
            if (event.type == sf::Event::TextEntered && genreSelected) {
                if (event.text.unicode == '\b' && genreInput.size() > 0) {
                    genreInput.pop_back(); // handle backspace
                } else if (event.text.unicode < 128 && event.text.unicode != '\r') {
                    genreInput += static_cast<char>(event.text.unicode); // handle input
                }
                genreText.setString(genreInput);
            }
            if (event.type == sf::Event::TextEntered && yearSelected) {
                if (event.text.unicode == '\b' && yearInput.size() > 0) {
                    yearInput.pop_back(); // handle backspace
                } else if (event.text.unicode < 128 && event.text.unicode != '\r') {
                    yearInput += static_cast<char>(event.text.unicode); // handle input
                }
                yearText.setString(yearInput); // update the text displayed on the year button
            }
        }

        sf::Color background(0, 0, 63);
        window.clear(background);
        window.draw(title);
        window.draw(instructions);
        window.draw(selection);
        window.draw(genre);
        window.draw(genreText);
        window.draw(year);
        window.draw(yearText);
        window.draw(sprite);
        window.display();
    }

    return 0;
}


void Interface::resetWindow(sf::RenderWindow &window) {
}