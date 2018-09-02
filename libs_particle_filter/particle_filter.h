#ifndef _PARTICLE_FILTER_H_
#define _PARTICLE_FILTER_H_

#include "map.h"
#include <iostream>

struct sParticle
{
  int x, y, theta;
};

#define ParticleFilter_THETA_MAX  ((int)360)

template<class Observation>
class ParticleFilter
{
  protected:
    unsigned int particles_count;
    Map<Observation> *map;

    sParticle *particles;

  public:
    ParticleFilter(Map<Observation> &map, unsigned int particles_count)
    {
      __rnd = 0;

      this->map = &map;
      this->particles_count = particles_count;
      this->particles = new sParticle[this->particles_count];

      random_particles();
    }

    virtual ~ParticleFilter()
    {
      delete[] particles;
    }

    void set_particles(int x, int y, int theta, int spread)
    {
      for (unsigned int i = 0; i < particles_count; i++)
      {
        particles[i].x      = limit(x + rnd(-spread, spread), map->min_x(), map->max_x());
        particles[i].y      = limit(y + rnd(-spread, spread), map->min_y(), map->max_y());
        particles[i].theta  = theta + rnd(-spread, spread);
      }
    }


    void print_particles()
    {
      for (unsigned int i = 0; i < particles_count; i++)
      {
        std::cout << particles[i].x << " " << particles[i].y << " " << particles[i].theta << "\n";
      }

      std::cout << "\n";
    }

  private:
    void random_particles()
    {
      for (unsigned int i = 0; i < particles_count; i++)
      {
        particles[i].x      = rnd(map->min_x(), map->max_x()+1);
        particles[i].y      = rnd(map->min_y(), map->max_y()+1);
        particles[i].theta  = rnd(-ParticleFilter_THETA_MAX/2, ParticleFilter_THETA_MAX/2);
      }
    }

  private:
    unsigned int __rnd;

    int rnd(int min, int max)
    {
      __rnd = 1103515245*__rnd + 12345;
      int result = 0;

      if (max > min)
        result = (int)(__rnd%(max - min)) + min;

      return result;
    }

    int limit(int value, int min, int max)
    {
      if (value > max)
        value = max;
      if (value < min)
        value = min;

      return value;
    }

};

#endif
