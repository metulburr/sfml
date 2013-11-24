
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Control{
    public:
        sf::RenderWindow window;
        int screen[2] = {800,600};
        unsigned int monitor[2] = {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height};
        std::string title;
        
        Control(std::string t):title(t){
            window.create(sf::VideoMode(screen[0], screen[1]), title);
            center_window();
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
            test();
        }
        
        void test(){
            std::cout << monitor[0] << std::endl;
            std::cout << monitor[1] << std::endl;
        }
};

int main(){
    Control app("SFML Win");
    app.run();
}
