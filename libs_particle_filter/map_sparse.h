#ifndef _MAP_SPARSE_H_
#define _MAP_SPARSE_H_

#include "map.h"
#include "qtree.h"

template<class Observation>
class MapSparse: public Map<Observation>
{
  protected:
    QTree<Observation> map;

  public:
    MapSparse(int threashold)
    :Map<Observation>()
    {

    }

    MapSparse(MapSparse& other)
    :Map<Observation>(other)
    {
      copy(other);
    }

    MapSparse(const MapSparse& other)
    :Map<Observation>(other)
    {
      copy(other);
    }

    virtual ~MapSparse()
    {

    }

    MapSparse& operator= (MapSparse& other)
    {
      copy_sparse(other);
      return *this;
    }

    MapSparse& operator= (const MapSparse& other)
    {
      copy_sparse(other);
      return *this;
    }

  protected:
    void copy_sparse(MapSparse& other)
    {
      Map<Observation>::copy(other);
    }

    void copy_sparse(const MapSparse& other)
    {
      Map<Observation>::copy(other);
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
      return 0;
    }

    int compare(int x, int y, const Observation &observation)
    {
      return 0;
    }

};

#endif
