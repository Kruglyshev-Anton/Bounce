#pragma once
#include"FullObjects.h"
class Ring:public FullObjects
{
private:
	float x, y, h=1.5*one_cell_size, w=0.3*one_cell_size;
	bool isact = false;
public:
	Ring(float x, float y);
	void Draw() override;
	std::string getType() override;
	void Move(unsigned char k) override;
	float getx() override;
	float gety() override;
	float getw() override;
	float geth() override;
};

