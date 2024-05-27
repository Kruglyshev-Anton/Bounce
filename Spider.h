#pragma once
#include "FullObjects.h"
class Spider:public FullObjects
{
private:
	float x, y, h=one_cell_size*2, w=one_cell_size*2, speed=0.05*one_cell_size, moveheig=0;

	bool U = true, D = false;
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
	int Col(std::vector<std::pair<float, float>>& point);
};

