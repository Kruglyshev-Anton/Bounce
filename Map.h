#pragma once
#include "FullObjects.h"
#include<fstream>
#include"Block.h"
#include"TriangleBlock.h"
#include"Ball.h"
#include"Spider.h"
#include"Stick.h"
#include"Ring.h"
#include"Fict.h"
class Map:public FullObjects
{
private:
	int pointwmap, pointhmap;
	std::vector<std::vector<FullObjects*>> map;
public:
	Map(const char* f);
	void Draw() override;
	std::string getType() override;
};

