#include <iostream>

#include <map_grid_test.h>
#include <particle_filter.h>


int main()
{
  unsigned int width  = 32;
  unsigned int height = 32;

  MapGridTest<int> map(width, height, time(NULL));

  map.print();

  ParticleFilter<int> filter(map, 256);


  std::cout << "program done\n";
  return 0;
}
