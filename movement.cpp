#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Rect{
    public:
        int speed = 100;
        sf::Vector2f position;
        sf::RectangleShape rect;
        bool moving_up = false, 
            moving_down = false,
            moving_right = false,
            moving_left = false; 
            
        Rect(){
            position = {100,100};
            rect.setSize(sf::Vector2f(100,100));
            rect.setPosition(position);
            rect.setFillColor(sf::Color::Red);
        }
        
        void update(sf::Time delta){
            
            sf::Vector2f movement(0,0);
            if (moving_up)
                movement.y -= speed;
            if (moving_down)
                movement.y += speed;
            if (moving_left)
                movement.x -= speed;
            if (moving_right)
                movement.x += speed;
            move(movement * delta.asSeconds());
            rect.setPosition(position);
        }
        
        void move(sf::Vector2f movement){
            position += movement;
        }
};

class Control{
    public:
        sf::RenderWindow window;
        sf::Clock clock;
        sf::Time frame_time = sf::seconds(1.f/60.f);
        sf::Time time = sf::Time::Zero, update_time = sf::Time::Zero;
        Rect obj;
        
        Control(){
            window.create(sf::VideoMode(600,400), "Title");
            //window.setKeyRepeatEnabled(false);
        }
        
        void update(){
            time = clock.restart();
            update_time += time;

            while(update_time > frame_time){
                update_time -= frame_time;
                obj.update(frame_time);
            }
            render();
        }
        
        void render(){
            window.clear(sf::Color::Black);
            window.draw(obj.rect);
            window.display();
        }
        
        void input_handler(sf::Keyboard::Key key, bool is_pressed){
            if (key == sf::Keyboard::W)
                obj.moving_up = is_pressed;
            else if (key == sf::Keyboard::S)
                obj.moving_down = is_pressed;
            else if (key == sf::Keyboard::D)
                obj.moving_right = is_pressed;
            else if (key == sf::Keyboard::A)
                obj.moving_left = is_pressed;
        }
        
        void event_handler(sf::Event event){
            while(window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed)
                    input_handler(event.key.code, true);
                else if (event.type == sf::Event::KeyReleased)
                    input_handler(event.key.code, false);
            }
        }
        
        void run(){
            while (window.isOpen()){
                sf::Event event;
                event_handler(event);
                update();
            }
        }
};

int main(){
    Control app;
    app.run();
}

