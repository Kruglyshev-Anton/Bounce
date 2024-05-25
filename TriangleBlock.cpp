#include "TriangleBlock.h"

TriangleBlock::TriangleBlock(float x, float y, int config):x(x), y(y),config(config)
{
}

void TriangleBlock::Draw()
{
}

std::string TriangleBlock::getType()
{
	return "t_block";
}
