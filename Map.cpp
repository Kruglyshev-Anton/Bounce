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
			else if (x == 9) {
				map[i].push_back(new Ball(j * one_cell_size, i * one_cell_size));
				BallI = i;
				BallJ = j;
			}
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
			if(i==BallI&&j==BallJ)Collision();
			//std::cout << (map[i][j])->getType();
		}
	}
}

std::string Map::getType()
{
	return "map";
}

void Map::Move(unsigned char k)
{
	map[BallI][BallJ]->Move(k);
	
	
}

void Map::Collision()
{
	Ball* b1 = dynamic_cast<Ball*>(map[BallI][BallJ]);
	std::vector<std::pair<float, float>> vec = b1->getColl();
	//for (int i = 0; i < 8; ++i)std::cout << vec[i].first << ' ' << vec[i].second << '\n';
	//std::cout << '\n';
	float r = (b1->getw()) / 2;
	for (int i = 0; i < pointhmap; ++i) {
		for (int j = 0; j < pointwmap; ++j) {
			
			if (map[i][j]->getType() == "block") {
				Block* bl = dynamic_cast<Block*>(map[i][j]);
				
				int nk = bl->Col(vec);
				
				if (nk==1) {
					b1->setx(bl->getx() - r);
				}
				
				else if (nk == 2) {
					
					b1->sety(bl->gety() + bl->geth() + 1.1*r);
				}
				
				else if (nk == 3) {
					b1->setx(bl->getx() + bl->getw() + r);
					
				}
				
				else if (nk == 4) {
					b1->setJ(true);
					b1->sety(bl->gety() - r);
				}
				
			}
			//std::cout << (map[i][j])->getType();
		}
	}
	
}

float Map::getx()
{
	return 0.0f;
}

float Map::gety()
{
	return 0.0f;
}

float Map::getw()
{
	return 0.0f;
}

float Map::geth()
{
	return 0.0f;
}


