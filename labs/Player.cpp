#include "Player.h"

Player::Player(int x, int y) : x(x), y(y)
{
    this->hp = 3;
    this->ammo = 10;
    this->score = 0;
}

Player::~Player()
{
}

int Player::GetX()
{
    return this->x;
}

int Player::GetY()
{
    return this->y;
}

void Player::SetX(int x_new)
{
    x = x_new;
}

void Player::SetY(int y_new)
{
    y = y_new;
}
