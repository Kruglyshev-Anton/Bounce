#pragma once
#include"FullObjects.h"
class Ball:public FullObjects
{
private:
	float x, y, r=one_cell_size*0.5,vx=0, vy = one_cell_size * 0.01, jump=0;
	bool isJ = false, isMove = false;
	float a;
	std::vector<std::pair<float, float>> pois;
public:
	bool isMoveR = true, isMoveL = true, isMoveD = true, isMoveU = true;
	Ball(float x, float y);
	std::string getType() override;
	void Move(unsigned char k)override;
	void Draw()override;
	void Phisycs();
	std::vector<std::pair<float, float>>& getColl();
	
	void setJ(bool val);
	
	float getx() override;
	float gety() override;
	float getw() override;
	float geth() override;
	void setx(float val) override;
	void sety(float val) override;
};

