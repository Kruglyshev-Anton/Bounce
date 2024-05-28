#pragma once
#include"FullObjects.h"
class Ring:public FullObjects
{
private:
	float x, y, h=one_cell_size, w=0.3*one_cell_size;
	
public:
	bool isact = false;
	Ring(float x, float y);
	void Draw() override;
	std::string getType() override;
	void Move(unsigned char k) override;
	float getx() override;
	float gety() override;
	float getw() override;
	float geth() override;
	void setx(float val) override;
	void sety(float val) override;
	bool Col(float x1, float y1);
};

