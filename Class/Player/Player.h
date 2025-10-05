#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Player
{
public:
    Texture texture;
    Sprite sprite;
    Vector2i frameSize = {32, 64};

    std::map<std::string, std::vector<IntRect>> animations {
        {
            "idle", {
                IntRect({0 * 32, 0 * 64}, frameSize)
            }
        },
        {
            "walk",{
                IntRect({1 * 32, 0 * 64}, frameSize),
                IntRect({2 * 32, 0 * 64}, frameSize),
                IntRect({3 * 32, 0 * 64}, frameSize),
                IntRect({4 * 32, 0 * 64}, frameSize),
                IntRect({5 * 32, 0 * 64}, frameSize),
                IntRect({6 * 32, 0 * 64}, frameSize)
            }
        }
    };

    float speed = 0.6f;
    std::string currentAnimation = "idle";
    float frameDuration = 0.2f;
    int currentFrame = -1;
    float elapsedTime = frameDuration;

    Vector2f direction = {0.f, 0.f};
    Vector2f gravity = {0.f, 0.5f};

    Player();
    Player(const char[]);
    ~Player();

    void updateDirection();
    void updateAnimation(float);
    void update(float);
    void draw(RenderWindow&);
    Vector2f getScale();
    void setScale(Vector2f);
    void setCurrentAnimation(const char[]);
};
