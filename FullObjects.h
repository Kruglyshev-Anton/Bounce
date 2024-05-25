#pragma once
#include<vector>
#include<string>
#include "glut.h"
#include<iostream>
class FullObjects
{
public:
	int one_cell_size = 20;
	virtual void Draw()=0;
	virtual std::string getType() = 0;
	virtual void Move(unsigned char k) = 0;
};

