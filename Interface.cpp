#include "Interface.h"
#include <chrono>

void Interface::createWindow(MoviesList &Movies) {
    Interface interface;
    sf::RenderWindow window(sf::VideoMode(900, 700), "Movie Matchmaker!", sf::Style::Titlebar | sf::Style::Close);

    //save image as a sprite and size correctly
    sf::Texture texture;
    texture.loadFromFile("../movies.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();
    //calculate scale factor to fit window size
    float scaleFactor = std::min((float)windowSize.x / textureSize.x, (float)windowSize.y / textureSize.y);
    //scale sprite to fit entire image in window
    sprite.setScale(scaleFactor, scaleFactor);
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
    string genreInput = ""; // variable to store user input for genre


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
    string yearInput = ""; // variable to store user input for genre


    //create instruction text
    sf::Text instructions("Here We Will Return a Sorted Selection of Movie Recommendations", font);
    instructions.setCharacterSize(20);
    instructions.setPosition((window.getSize().x / 2)/3.5, (window.getSize().y / 2)-20);
    sf::Text selection("Please Choose a Sorting Category", font);
    selection.setCharacterSize(20);
    selection.setPosition((window.getSize().x / 2)/1.5, (window.getSize().y/2)+30);

    //create shellSort text
    bool shellSelected = false;
    sf::Text shellText("Shell Sort", font);
    shellText.setCharacterSize(30);
    shellText.setFillColor(sf::Color::Black);
    shellText.setPosition(box1.getPosition().x + box1.getSize().x/2 - shellText.getLocalBounds().width/2,
                          box1.getPosition().y + box1.getSize().y/2 - shellText.getLocalBounds().height/2);

    //create quickSort text
    bool quickSelected = false;
    sf::Text quickText("Quick Sort", font);
    quickText.setCharacterSize(30);
    quickText.setFillColor(sf::Color::Black);
    quickText.setPosition(box2.getPosition().x + box2.getSize().x/2 - quickText.getLocalBounds().width/2,
                          box2.getPosition().y + box2.getSize().y/2 - quickText.getLocalBounds().height/2);

    //sort represents if the movies have been sorted yet
    bool sort = false;
    //first represents if the user is on the first or second input
    bool first = true;

    //draw continue button
    sf::RectangleShape continueButton;
    continueButton.setSize(sf::Vector2f(200, 100));
    continueButton.setPosition(sf::Vector2f(window.getSize().x/2.5 , window.getSize().y - 110));
    continueButton.setFillColor(sf::Color::White);

    //create continue button text
    sf::Text continueText("continue...", font);
    continueText.setCharacterSize(30);
    continueText.setFillColor(sf::Color::Black);
    continueText.setPosition(continueButton.getPosition().x + box1.getSize().x/2 - continueText.getLocalBounds().width/2,
                             continueButton.getPosition().y + box1.getSize().y/2 - continueText.getLocalBounds().height/2);
    bool continueSelected = false; // flag to check if continue button has been clicked


    // draw the close button
    sf::RectangleShape closeButton;
    closeButton.setSize(sf::Vector2f(200, 100));
    closeButton.setPosition(sf::Vector2f(window.getSize().x/2.5 , window.getSize().y - 110));
    closeButton.setFillColor(sf::Color::White);

    //create close button text
    sf::Text closeText("done", font);
    closeText.setCharacterSize(30);
    closeText.setFillColor(sf::Color::Black);
    closeText.setPosition(closeButton.getPosition().x + box1.getSize().x/2 - closeText.getLocalBounds().width/2,
                          closeButton.getPosition().y + box1.getSize().y/2 - closeText.getLocalBounds().height/2);
    bool closeSelected = false; //checks if close button was clicked

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (box1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        genreSelected = true;
                    } else if (box2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        yearSelected = true;
                    } else if (continueButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        continueSelected = true;
                    }
                }
            }
            if (genreSelected && first) {
                if (event.type == sf::Event::TextEntered && genreSelected) {
                    if (event.text.unicode == '\b' && genreInput.size() > 0) {
                        genreInput.pop_back(); // handles backspace
                    } else if (event.text.unicode < 128 && event.text.unicode != '\r') {
                        genreInput += static_cast<char>(event.text.unicode); //takes in user input
                    }
                    genreText.setString(genreInput);

                }
                if (event.type == sf::Event::MouseButtonPressed && continueSelected) {
                    Movies.addMovies(genreInput, "");
                    cout << "Genre: " << genreInput << endl;
                    cout << "genre selected" << endl;
                    selection.setString("Please Choose a Sorting Algorithm");
                    genreText.setString("");
                    yearText.setString("");
                    genreSelected = false; // reset genreSelected flag
                    yearSelected = false; // reset yearSelected flag
                    sort = true;
                    first = false;
                }
            }
            if (yearSelected && first) {
                if (event.type == sf::Event::TextEntered && yearSelected) {
                    if (event.text.unicode == '\b' && yearInput.size() > 0) {
                        yearInput.pop_back(); // handle backspace
                    } else if (event.text.unicode < 128 && event.text.unicode != '\r') {
                        yearInput += static_cast<char>(event.text.unicode); // handle input
                    }
                    yearText.setString(yearInput);

                }
                if (event.type == sf::Event::MouseButtonPressed && continueSelected) {
                    Movies.addMovies("", yearInput); // sara addition
                    cout << "Year: " << yearInput << endl;
                    if (interface.category == "") {
                        cout << "year selected" << endl;
                    }
                    selection.setString("Please Choose a Sorting Algorithm");
                    genreText.setString("");
                    yearText.setString("");
                    genreSelected = false; // reset genreSelected flag
                    yearSelected = false; // reset yearSelected flag
                    sort = true;
                    first = false;
                }
            }
            if(event.type == sf::Event::MouseButtonPressed && sort && !first){
                if (box1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    auto start = chrono::high_resolution_clock::now(); // get current time
                    Movies.shellSort(Movies.getSize());
                    auto end = chrono::high_resolution_clock::now(); // get current time
                    auto durationTime = chrono::duration_cast<chrono::microseconds>(end - start); // calculate the duration in microseconds
                    cout << "Time taken by Shell Sort: " << durationTime.count() << " microseconds" << endl; // print the duration
                    string dur = to_string(durationTime.count());
                    duration = dur;
                    shellSelected = true;
                    cout << "shell sort selected " << endl;
                    closeSelected = true;
                }
                else if (box2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    auto start = chrono::high_resolution_clock::now(); // get current time
                    Movies.quickSort(0, Movies.getSize() - 1);
                    auto end = chrono::high_resolution_clock::now(); // get current time
                    auto durationTime = chrono::duration_cast<chrono::microseconds>(end - start); // calculate the duration in microseconds
                    cout << "Time taken by Quick Sort: " << durationTime.count() << " microseconds" << endl; // print the duration
                    string dur = to_string(durationTime.count());
                    duration = dur;
                    quickSelected = true;
                    cout << "quick sort selected " << endl;
                    closeSelected = true;
                }
            }
            if (closeButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && closeSelected) {
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
        if(!continueSelected){
            window.draw(continueButton);
            window.draw(continueText);
        }
        else{
            window.draw(closeButton);
            window.draw(closeText);
        }
        if(sort){
            window.draw(shellText);
            window.draw(quickText);
            first = false;
        }
        window.display();
    }
}

void Interface::resultsWindow(MoviesList &Movies){
    sf::RenderWindow window(sf::VideoMode(900, 700), "Movie Matchmaker!", sf::Style::Titlebar | sf::Style::Close);

    //load fonts
    sf::Font font;
    font.loadFromFile("../short-baby-font/ShortBaby-Mg2w.ttf");
    sf::Font font2;
    font2.loadFromFile("../hangar-nine-font/HangarNine-eW1e.ttf");

    //create title
    sf::Text title("Top 5 Movies Based on Input", font);
    title.setStyle(sf::Text::Bold);
    title.setCharacterSize(50);
    title.setPosition((window.getSize().x / 2) - (title.getLocalBounds().width / 2), 50);

    sf::Text durationText("Duration of Sort: " + duration + " microseconds", font2);
    //durationText.setStyle(sf::Text::Bold);
    durationText.setCharacterSize(30);
    durationText.setPosition((window.getSize().x / 4),120);

    sf::Text movie1(Movies.getMovieRecTitle(Movies.getSize() - 1) + " " + Movies.getMovieRecRating(Movies.getSize()-1), font);
    movie1.setCharacterSize(30);
    movie1.setPosition((window.getSize().x / 2) - (title.getLocalBounds().width / 2), 180);

    sf::Text movie2(Movies.getMovieRecTitle(Movies.getSize() - 2) + " " + Movies.getMovieRecRating(Movies.getSize()-2), font);
    movie2.setCharacterSize(30);
    movie2.setPosition((window.getSize().x / 2) - (title.getLocalBounds().width / 2), 280);

    sf::Text movie3(Movies.getMovieRecTitle(Movies.getSize() - 3) + " " + Movies.getMovieRecRating(Movies.getSize()-3), font);
    movie3.setCharacterSize(30);
    movie3.setPosition((window.getSize().x / 2) - (title.getLocalBounds().width / 2), 380);

    sf::Text movie4(Movies.getMovieRecTitle(Movies.getSize() - 4) + " " + Movies.getMovieRecRating(Movies.getSize()-4), font);
    movie4.setCharacterSize(30);
    movie4.setPosition((window.getSize().x / 2) - (title.getLocalBounds().width / 2), 480);

    sf::Text movie5(Movies.getMovieRecTitle(Movies.getSize() - 5) + " " + Movies.getMovieRecRating(Movies.getSize()-5), font);
    movie5.setCharacterSize(30);
    movie5.setPosition((window.getSize().x / 2) - (title.getLocalBounds().width / 2), 580);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Color background(0, 0, 63);
        window.clear(background);
        window.draw(title);
        window.draw(durationText);
        window.draw(movie1);
        window.draw(movie2);
        window.draw(movie3);
        window.draw(movie4);
        window.draw(movie5);
        window.display();
    }
}