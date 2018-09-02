#ifndef _MAP_GRID_H_
#define _MAP_GRID_H_

#include "map.h"

template<class Observation>
class MapGrid: public Map<Observation>
{
  protected:
    unsigned int m_width, m_height;
    Observation **map;

  public:
    MapGrid(unsigned int width, unsigned int height)
    :Map<Observation>()
    {
      m_width  = width;
      m_height = height;

      map = new Observation*[m_height];
      for (unsigned int j = 0; j < m_height; j++)
        map[j] = new Observation[m_width];

      this->m_min_x = 0;
      this->m_max_x = m_width - 1;

      this->m_min_y = 0;
      this->m_max_y = m_height - 1;
    }

    MapGrid(MapGrid& other)
    :Map<Observation>(other)
    {
      copy_grid(other);
    }

    MapGrid(const MapGrid& other)
    :Map<Observation>(other)
    {
      copy_grid(other);
    }

    virtual ~MapGrid()
    {
      for (unsigned int j = 0; j < m_height; j++)
        delete[] map[j];
      delete[] map;
    }

    MapGrid& operator= (MapGrid& other)
    {
      copy_grid(other);
      return *this;
    }

    MapGrid& operator= (const MapGrid& other)
    {
      copy_grid(other);
      return *this;
    }

  protected:
    void copy_grid(MapGrid& other)
    {
      this->copy(other);

      this->m_width  = other.m_width;
      this->m_height = other.m_height;

      this->m_min_x = other.m_min_x;
      this->m_max_x = other.m_max_x;
      this->m_min_y = other.m_min_y;
      this->m_max_y = other.m_max_y;

      if (map != nullptr)
      {
        for (unsigned int j = 0; j < m_height; j++)
          delete[] map[j];
        delete[] map;
      }

      map = new Observation*[m_height];
      for (unsigned int j = 0; j < m_height; j++)
      {
        map[j] = new Observation[m_width];

        for (unsigned int i = 0; i < m_width; i++)
          map[j][i] = other.map[j][i];
      }
    }

    void copy_grid(const MapGrid& other)
    {
      this->copy(other);

      this->m_width  = other.m_width;
      this->m_height = other.m_height;

      this->m_min_x = other.m_min_x;
      this->m_max_x = other.m_max_x;
      this->m_min_y = other.m_min_y;
      this->m_max_y = other.m_max_y;

      if (map != nullptr)
      {
        for (unsigned int j = 0; j < m_height; j++)
          delete[] map[j];
        delete[] map;
      }

      map = new Observation*[m_height];
      for (unsigned int j = 0; j < m_height; j++)
      {
        map[j] = new Observation[m_width];

        for (unsigned int i = 0; i < m_width; i++)
          map[j][i] = other.map[j][i];
      }
    }

  public:
    Observation& get(int x, int y)
    {
      return map[y][x];
    }

    int set(int x, int y, Observation &observation)
    {
      map[y][x] = observation;
      return 0;
    }

    int set(int x, int y, const Observation &observation)
    {
      map[y][x] = observation;
      return 0;
    }

    int compare(int x, int y, Observation &observation)
    {
      int res = map[y][x] - observation;
      if (res < 0)
        res = -res;

      return res;
    }

    int compare(int x, int y, const Observation &observation)
    {
      int res = map[y][x] - observation;
      if (res < 0)
        res = -res;

      return res;
    }

};

#endif
