#pragma once
class Player
{
public:
	Player(int x = 1, int y = 1);
	~Player();
	int GetX();
	int GetY();
	void SetX(int);
	void SetY(int);
private:
	int x;
	int y;
	int hp;
	int score;
	int ammo;
};

