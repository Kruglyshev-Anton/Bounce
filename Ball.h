#pragma once
#include"FullObjects.h"
class Ball:public FullObjects
{
private:
	float x, y, r=one_cell_size*0.5,vx=0, vy = one_cell_size * 0.01, jump=0;
	bool isJ = false;
public:
	Ball(float x, float y);
	std::string getType() override;
	void Move(unsigned char k)override;
	void Draw()override;
	void Phisycs();
};

