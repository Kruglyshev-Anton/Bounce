#pragma once
#include"FullObjects.h"
class Fict:public FullObjects
{
public:
	Fict() = default;
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

