#pragma once
#include "FullObjects.h"
#include<fstream>
#include"Block.h"
#include"TriangleBlock.h"
#include"Ball.h"
#include"Spider.h"
#include"Stick.h"
#include"Ring.h"
#include"Fict.h"
class Map:public FullObjects
{
private:
	int pointwmap, pointhmap, countRings, lives=3;
	int countActRings = 0;
	std::vector<std::vector<FullObjects*>> map;
	int BallI, BallJ;
	float X, Y, dx=0,dy=0;
	int isGame = 0;
	float Windoww = 700;

public:
	Map(const char* f);
	void Draw() override;
	std::string getType() override;
	void Move(unsigned char k) override;
	void Collision();
	float getx() override;
	float gety() override;
	float getw() override;
	float geth() override;
	void setx(float val) override;
	void sety(float val) override;
	int getGame();
	float getSizeW();
	float getSizeH();
	void drawTxt(std::string& text, float x, float y, float h);
	~Map();
	//void actions_keyboard(unsigned char k);
};

