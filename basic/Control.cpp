
#include "include/Control.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Control::Control(bool scr):fullscreen(scr){
	time = sf::seconds(0);
	if (fullscreen)
		window.create(sf::VideoMode(monitor[0], monitor[1]), title, sf::Style::Fullscreen);
	else{
		window.create(sf::VideoMode(screen[0], screen[1]), title);
		center_window();
	}
}


void Control::output(){
	std::cout << "Monitor size: " << monitor[0] << ", " << monitor[1] << std::endl;
	std::cout << "Screen size: " << screen[0] << ", " << screen[1] << std::endl;
	std::cout << "Fullscreen: " << fullscreen << std::endl;
	std::cout << "Frame Time: " << time.asSeconds() << std::endl;
	std::cout << "Game Time: " << game_time.asSeconds() << std::endl;
	std::cout << "Mouse Position: " << mouse.x << " " << mouse.y << std::endl;
	std::cout << std::endl;
}

void Control::center_window(){
	window.setPosition(
		sf::Vector2i(
			(monitor[0] / 2) - (screen[0] / 2),
			(monitor[1] / 2) - (screen[1] / 2)
		)
	);
}

void Control::events(sf::Event e){
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

void Control::time_update(){
	time = clock.restart();
	game_time = game_clock.getElapsedTime();
}

void Control::update(){
	output();
	time_update();
	mouse = sf::Mouse::getPosition(window);
}

void Control::render(){
	window.clear();
	window.display();
}

void Control::run(){
	while (window.isOpen()){
		sf::Event event;
		events(event);
		update();
		render();
	}
}
