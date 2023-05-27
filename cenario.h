#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

extern std::vector<std::string> cenario0;
extern std::vector<std::string> cenario1;
extern std::vector<std::string> cenario2;

std::vector<std::string>& getCenario(int index);
sf::Vector2f getDestinoPortal(int idCenario, int idPortal);


