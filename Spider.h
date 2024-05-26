#pragma once
#include "FullObjects.h"
class Spider:public FullObjects
{
private:
	float x, y, h=one_cell_size*2, w=one_cell_size*2;

public:
	Spider(float x, float y);
	std::string getType() override;
	void Draw()override;
	void Move(unsigned char k) override;
	float getx() override;
	float gety() override;
	float getw() override;
	float geth() override;
	void setx(float val) override;
	void sety(float val) override;
};

