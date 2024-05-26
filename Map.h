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
	int pointwmap, pointhmap;
	std::vector<std::vector<FullObjects*>> map;
	float BallI, BallJ;
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
	//void actions_keyboard(unsigned char k);
};

