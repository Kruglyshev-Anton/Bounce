#pragma once
#include "Block.h"
class TriangleBlock:public FullObjects
{
private:
	float x, y, h=one_cell_size, w=one_cell_size;
	int config;

public:
	TriangleBlock(float x, float y, int config);
	void Draw() override;
	std::string getType() override;
	void Move(unsigned char k) override;
	float getx() override;
	float gety() override;
	float getw() override;
	float geth() override;
	void setx(float val) override;
	void sety(float val) override;
};

