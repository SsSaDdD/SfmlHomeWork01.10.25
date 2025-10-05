#include <SFML/Graphics.hpp>
#include <iostream>
#include "Class/Player/Player.h"
#include "Class/Map/Map.h"

using namespace sf;
using namespace std;

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 5;
const int MAP_TILE_SIZE = 70;

char MAP[MAP_HEIGHT][MAP_WIDTH + 1] = {
    "          ",
    "         L",
    "GGGBBG    ",
    "          ",
    "      GGGG",
};

int main() {
    RenderWindow window(VideoMode({1200, 800}), "SFML Lesson 8");

    Player player("skeletonBase.png");
    player.setScale({2.f,2.f});
    Map location(
        Vector2i({MAP_WIDTH + 1, MAP_HEIGHT}),
        Vector2i({MAP_TILE_SIZE, MAP_TILE_SIZE}),
        (char*)MAP
    );

    Clock clock;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        float time = clock.restart().asSeconds();

        window.clear(Color::Black);

        location.draw(window);

        player.update(time);
        location.checkCollisions(player.sprite);
        player.draw(window);

        window.display();
    }
    return 0;
}
