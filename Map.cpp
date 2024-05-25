#include "Map.h"

Map::Map(const char* f)
{
	std::ifstream fin;
	(fin).open(f);
	int x;
	char c;
	fin >> pointwmap >> pointhmap;
	//std::cout << pointhmap;
	for (int i = 0; i < pointhmap; ++i) {
		map.push_back(std::vector<FullObjects*>());
		for (int j = 0; j < pointwmap; ++j) {
			fin.get(c);
			
			x = static_cast<int>(c)-48;
			//std::cout <<  << '\n';
			if (x == 1)map[i].push_back(new Block(j * one_cell_size, i * one_cell_size));
			else if (x == 2)map[i].push_back(new TriangleBlock(j * one_cell_size, i * one_cell_size, 1));
			else if (x == 3)map[i].push_back(new TriangleBlock(j * one_cell_size, i * one_cell_size, 2));
			else if (x == 4)map[i].push_back(new TriangleBlock(j * one_cell_size, i * one_cell_size, 3));
			else if (x == 5)map[i].push_back(new TriangleBlock(j * one_cell_size, i * one_cell_size, 4));
			else if (x == 6)map[i].push_back(new Stick(j * one_cell_size, i * one_cell_size));
			else if (x == 7)map[i].push_back(new Spider(j * one_cell_size, i * one_cell_size));
			else if (x == 8)map[i].push_back(new Ring(j * one_cell_size, i * one_cell_size));
			else if (x == 9)map[i].push_back(new Ball(j * one_cell_size, i * one_cell_size));
			else {
				map[i].push_back(new Fict());
			}
			
		}
	}
	fin.close();

}

void Map::Draw()
{
	for (int i = 0; i < pointhmap; ++i) {
		for (int j = 0; j < pointwmap; ++j) {
			map[i][j]->Draw();
			//std::cout << (map[i][j])->getType();
		}
	}
}

std::string Map::getType()
{
	return "map";
}
