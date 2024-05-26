#pragma once
#include"FullObjects.h"
class Block:public FullObjects
{
private:
	float x, y, h=one_cell_size, w=one_cell_size;
	

public:
	Block(float x, float y);
	void Draw() override;
	void Move(unsigned char k) override;
	std::string getType();

	int Col(std::vector<std::pair<float, float>>& point);
	float getx() override;
	float gety() override;
	float getw() override;
	float geth() override;
	void setx(float val) override;
	void sety(float val) override;
};

