#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	int GetX();
	int GetY();
	int GetHP();
	void SetX(int);
	void SetY(int);
	void SetHP(int);
private:
	int x;
	int y;
	int hp;
};

