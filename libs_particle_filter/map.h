#ifndef _MAP_H_
#define _MAP_H_

template<class Observation>
class Map
{
  protected:
    int m_min_x, m_max_x, m_min_y, m_max_y;
    Observation m_observation;

  public:
    Map()
    {
      m_min_x = 0;
      m_max_x = 0;
      m_min_y = 0;
      m_max_y = 0;
    }

    Map(Map& other)
    {
      copy(other);
    }

    Map(const Map& other)
    {
      copy(other);
    }

    virtual ~Map()
    {

    }

    virtual Map& operator= (Map& other)
    {
      copy(other);
      return *this;
    }

    virtual Map& operator= (const Map& other)
    {
      copy(other);
      return *this;
    }

  protected:
    void copy(Map& other)
    {
      m_min_x = other.m_min_x;
      m_max_x = other.m_max_x;
      m_min_y = other.m_min_y;
      m_max_y = other.m_max_y;
      m_observation = other.m_observation;
    }

    void copy(const Map& other)
    {
      m_min_x = other.m_min_x;
      m_max_x = other.m_max_x;
      m_min_y = other.m_min_y;
      m_max_y = other.m_max_y;
      m_observation = other.m_observation;
    }

  public:
    virtual Observation& get(int x, int y)
    {
      (void)(x);
      (void)(y);
      return m_observation;
    }

    virtual int set(int x, int y, Observation &observation)
    {
      (void)(x);
      (void)(y);
      (void)(observation);
      return 0;
    }

    virtual int set(int x, int y, const Observation &observation)
    {
      (void)(x);
      (void)(y);
      (void)(observation);
      return 0;
    }

    virtual int compare(int x, int y, Observation &observation)
    {
      (void)(x);
      (void)(y);
      (void)(observation);
      return -1;
    }

    virtual int compare(int x, int y, const Observation &observation)
    {
      (void)(x);
      (void)(y);
      (void)(observation);
      return -1;
    }

  public:
    int min_x()
    {
      return m_min_x;
    }

    int max_x()
    {
      return m_max_x;
    }


    int min_y()
    {
      return m_min_y;
    }

    int max_y()
    {
      return m_max_y;
    }


};

#endif
