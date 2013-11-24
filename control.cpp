
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Control{
    public:
        sf::RenderWindow window;
        int screen[2] = {800,600};
        unsigned int monitor[2] = {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height};
        bool fullscreen;
        std::string title = "SFML test";
        
        Control(bool fullscr):fullscreen(fullscr){
            if (fullscreen)
                window.create(sf::VideoMode(screen[0], screen[1]), title, sf::Style::Fullscreen);
            else{
                window.create(sf::VideoMode(screen[0], screen[1]), title);
                center_window();
            }
            output();
        }

        
        void output(){
            std::cout << "Monitor size: " << monitor[0] << ", " << monitor[1] << std::endl;
            std::cout << "Screen size: " << screen[0] << ", " << screen[1] << std::endl;
            std::cout << "Fullscreen: " << fullscreen << std::endl;
        }
        
        void center_window(){
            window.setPosition(
                sf::Vector2i(
                    (monitor[0] / 2) - (screen[0] / 2),
                    (monitor[1] / 2) - (screen[1] / 2)
                )
            );
        }
        
        void events(sf::Event e){
            while(window.pollEvent(e)){
                if (e.type == sf::Event::Closed){
                    window.close();
                }
                else if (e.type == sf::Event::KeyPressed){
                    if (e.key.code == sf::Keyboard::Escape){
                        window.close();
                    }
                }
            }
        }
        
        void update(){
            
        }
        
        void render(){
            window.clear();
            window.display();
        }
        
        void run(){
            while (window.isOpen()){
                sf::Event event;
                events(event);
                update();
                render();
            }
        }
};

int main(){
    bool fullscreen = false;
    Control app(fullscreen);
    app.run();
}
