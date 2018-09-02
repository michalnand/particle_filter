#ifndef _MAP_GRID_TEST_H_
#define _MAP_GRID_TEST_H_

#include "map_grid.h"

#include <iostream>

template<class Observation>
class MapGridTest: public MapGrid<Observation>
{
  public:
    MapGridTest(unsigned int width, unsigned int height, unsigned int seed = 0)
    :MapGrid<Observation>(width, height)
    {
      srand(seed);
      
      for (int y = this->min_y(); y < this->max_y(); y++)
      {
        for (int x = this->min_x(); x < this->max_x(); x++)
        {
          auto v = rand()%2;
          this->set(x, y, v);
        }
      }
    }

    virtual ~MapGridTest()
    {

    }

  public:
    void print()
    {
      for (int y = this->min_y(); y < this->max_y(); y++)
      {
        for (int x = this->min_x(); x < this->max_x(); x++)
          std::cout << this->map[y][x] << " ";
        std::cout << "\n";
      }
      std::cout << "\n";
    }


};

#endif
