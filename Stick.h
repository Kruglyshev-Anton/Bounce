#pragma once
#include "FullObjects.h"
class Stick:public FullObjects
{
private:
	float x, y, h=one_cell_size*2, w=one_cell_size;

public:
	Stick(float x, float y);
	std::string getType() override;
	void Draw()override;
	void Move(unsigned char k) override;
};

