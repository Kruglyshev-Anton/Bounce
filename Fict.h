#pragma once
#include"FullObjects.h"
class Fict:public FullObjects
{
public:
	Fict() = default;
	void Draw() override;
	std::string getType() override;
	void Move(unsigned char k) override;

};

