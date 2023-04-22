#include "Interface.h"
#include "MoviesList.h"

Interface Interface::interface() {
    this->category = "";
    this->algorithm = "";
}

void Interface::setCategory(string category) {
    this->category = category;
}

void Interface::setAlgorithm(string algorithm) {
    this->algorithm = algorithm;
}

//sf::RenderWindow*
string Interface::createWindow() {
    Interface interface;
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
    sf::RectangleShape box1;
    box1.setSize(sf::Vector2f(200, 100));
    box1.setPosition(sf::Vector2f((window.getSize().x / 2) - 360, (window.getSize().y / 2) + 90));
    box1.setFillColor(sf::Color::White);
    box1.setOutlineColor(sf::Color::White);
    box1.setOutlineThickness(2);

    // Create genre button text
    sf::Text genreText("Genre", font);
    genreText.setCharacterSize(30);
    genreText.setFillColor(sf::Color::Black);
    genreText.setPosition(box1.getPosition().x + box1.getSize().x/2 - genreText.getLocalBounds().width/2,
                          box1.getPosition().y + box1.getSize().y/2 - genreText.getLocalBounds().height/2);

    bool genreSelected = false; // flag to check if genre button has been clicked


    //create button for year input
    sf::RectangleShape box2;
    box2.setSize(sf::Vector2f(200, 100));
    box2.setPosition(sf::Vector2f((window.getSize().x / 2) + 150, (window.getSize().y / 2) + 90));
    box2.setFillColor(sf::Color::White);
    box2.setOutlineColor(sf::Color::White);
    box2.setOutlineThickness(2);

    // Create year button text
    sf::Text yearText("Year", font);
    yearText.setCharacterSize(30);
    yearText.setFillColor(sf::Color::Black);
    yearText.setPosition(box2.getPosition().x + box2.getSize().x/2 - yearText.getLocalBounds().width/2,
                         box2.getPosition().y + box2.getSize().y/2 - yearText.getLocalBounds().height/2);

    bool yearSelected = false; // flag to check if genre button has been clicked


    //create instruction text
    sf::Text instructions("Here We Will Return a Sorted Selection of Movie Recommendations", font);
    instructions.setCharacterSize(20);
    instructions.setPosition((window.getSize().x / 2)/3.5, (window.getSize().y / 2)-20);
    sf::Text selection("Please Choose a Sorting Category", font);
    selection.setCharacterSize(20);
    selection.setPosition((window.getSize().x / 2)/1.5, (window.getSize().y/2)+30);

    bool shellSelected = false;
    sf::Text shellText("Shell Sort", font);
    shellText.setCharacterSize(30);
    shellText.setFillColor(sf::Color::Black);
    shellText.setPosition(box1.getPosition().x + box1.getSize().x/2 - shellText.getLocalBounds().width/2,
                          box1.getPosition().y + box1.getSize().y/2 - shellText.getLocalBounds().height/2);

    bool quickSelected = false;
    sf::Text quickText("Quick Sort", font);
    quickText.setCharacterSize(30);
    quickText.setFillColor(sf::Color::Black);
    quickText.setPosition(box2.getPosition().x + box2.getSize().x/2 - quickText.getLocalBounds().width/2,
                          box2.getPosition().y + box2.getSize().y/2 - quickText.getLocalBounds().height/2);

    bool sort = false;
    bool first = true;

    // draw the close button
    sf::RectangleShape closeButton;
    closeButton.setSize(sf::Vector2f(200, 100));
    closeButton.setPosition(sf::Vector2f(window.getSize().x/2.5 , window.getSize().y - 110));
    closeButton.setFillColor(sf::Color::White);

    //create close button text
    sf::Text closeText("continue...", font);
    closeText.setCharacterSize(30);
    closeText.setFillColor(sf::Color::Black);
    closeText.setPosition(closeButton.getPosition().x + box1.getSize().x/2 - closeText.getLocalBounds().width/2,
                          closeButton.getPosition().y + box1.getSize().y/2 - closeText.getLocalBounds().height/2);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (box1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        genreSelected = true;
                    }
                    else if (box2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        yearSelected = true;
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && genreSelected) {
                //save genre in a variable
                if(interface.category == "") {
                    interface.setCategory("genre");
                    cout << "genre selected" << endl;
                }
                selection.setString("Please Choose a Sorting Algorithm");
                genreText.setString("");
                yearText.setString("");
                genreSelected = false; // reset genreSelected flag
                yearSelected = false; // reset yearSelected flag
                sort = true;
            }
            else if (event.type == sf::Event::MouseButtonPressed && yearSelected) {
                //save year in a variable
                if(interface.category == ""){
                    interface.setCategory("year");
                    cout << "year selected" << endl;
                }
                selection.setString("Please Choose a Sorting Algorithm");
                genreText.setString("");
                yearText.setString("");
                genreSelected = false; // reset genreSelected flag
                yearSelected = false; // reset yearSelected flag
                sort = true;
            }
            if(event.type == sf::Event::MouseButtonPressed && sort && !first){
                if (box1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    shellSelected = true;
                    interface.setAlgorithm("shell");
                    cout << "shell sort selected " << endl;
                }
                else if (box2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    quickSelected = true;
                    interface.setAlgorithm("quick");
                    cout << "quick sort selected " << endl;
                }
            }
            if (closeButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                window.close();
            }


        }

        sf::Color background(0, 0, 63);
        window.clear(background);
        window.draw(title);
        window.draw(instructions);
        window.draw(selection);
        window.draw(box1);
        window.draw(genreText);
        window.draw(box2);
        window.draw(yearText);
        window.draw(sprite);
        window.draw(closeButton);
        window.draw(closeText);
        if(sort){
            window.draw(shellText);
            window.draw(quickText);
            first = false;
        }
        window.display();
    }
    return interface.category + " " + interface.algorithm;
}

void Interface::resultsWindow(string category, string algorithm){
    sf::RenderWindow window(sf::VideoMode(900, 700), "Movie Matchmaker!", sf::Style::Titlebar | sf::Style::Close);

    //create title
    sf::Font font;
    font.loadFromFile("../short-baby-font/ShortBaby-Mg2w.ttf");
    sf::Text title("Your sorted movies", font);  //TODO: change title
    title.setStyle(sf::Text::Bold);
    title.setCharacterSize(50);
    title.setPosition((window.getSize().x / 2) - (title.getLocalBounds().width / 2), 50);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Color background(0, 0, 63);
        window.clear(background);
        window.draw(title);
        window.display();
    }
}

void Interface::resetWindow(sf::RenderWindow &window) {
}