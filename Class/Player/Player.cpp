#include "Player.h"
#include <iostream>

using namespace sf;
using namespace std;

Player::Player() : texture(), sprite(texture)
{
    if (!texture.loadFromFile("p1_spritesheet.png"))
        cout << "Texture not loaded!" << endl;

    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect({0 * 70, 2 * 96}, {66, 92}));
}

Player::Player(const char _texturePath[])
    : texture(_texturePath), sprite(texture)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect({0 * 70, 2 * 96}, {66, 92}));
}

Player::~Player() {}

void Player::updateDirection()
{
    direction = {0.f, 0.f};

    if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
        direction.x -= 1.f;
        // Разворот влево
        sprite.setScale({-abs(sprite.getScale().x), sprite.getScale().y});
        // Чтобы позиция не скакала при зеркальном отражении
        sprite.setOrigin({frameSize.x / 2.f, 0});
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
        direction.x += 1.f;
        // Разворот вправо
        sprite.setScale({abs(sprite.getScale().x), sprite.getScale().y});
        sprite.setOrigin({0, 0});
    }
}

void Player::updateAnimation(float time)
{
    if (direction.length()) setCurrentAnimation("walk");
    else setCurrentAnimation("idle");

    elapsedTime += time;
    while (elapsedTime >= frameDuration) {
        elapsedTime -= frameDuration;
        currentFrame = (++currentFrame) % animations[currentAnimation].size();
        sprite.setTextureRect(animations[currentAnimation][currentFrame]);
    }
}

void Player::update(float time)
{
    updateDirection();
    updateAnimation(time);

    sprite.move(gravity + direction * speed);
}

void Player::draw(RenderWindow& window)
{
    window.draw(sprite);
}

Vector2f Player::getScale() {
    return sprite.getScale();
}

void Player::setScale(Vector2f _scale) {
    sprite.setScale(_scale);
}

void Player::setCurrentAnimation(const char _aniName[]) {
    if (currentAnimation != _aniName && animations.count(_aniName)) {
        currentAnimation = _aniName;
        currentFrame = 0;
        elapsedTime = 0;
        sprite.setTextureRect(animations[currentAnimation][currentFrame]);
    }
}