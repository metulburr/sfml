#ifndef CONTROL_H
#define CONTROL_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Control{
    public:
        sf::RenderWindow window;
        unsigned int monitor[2] = {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height},
            screen[2] = {800,600};
        bool fullscreen;
        std::string title = "SFML test";
        sf::Time time, game_time;
        sf::Clock clock, game_clock;
        sf::Vector2i mouse;
        
        Control(bool);
        void output();
        void center_window();
        void events(sf::Event);
        void time_update();
        void update();
        void render();
        void run();
};   
#endif
