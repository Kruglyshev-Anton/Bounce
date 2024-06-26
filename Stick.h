#pragma once
#include "FullObjects.h"
class Stick:public FullObjects
{
private:
	float x, y, h=one_cell_size, w=0.4*one_cell_size;

public:
	Stick(float x, float y);
	std::string getType() override;
	void Draw()override;
	void Move(unsigned char k) override;
	float getx() override;
	float gety() override;
	float getw() override;
	float geth() override;
	void setx(float val) override;
	void sety(float val) override;
	int Col(std::vector<std::pair<float, float>>& point);
};

