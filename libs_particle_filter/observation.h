#ifndef _OBSERVATION_H_
#define _OBSERVATION_H_

template<class t_type> class Observation
{
  private:
    unsigned int m_w, m_h, m_d;
    unsigned int m_size;
    t_type *m_observation;

  public:
    // Default constructor
    Observation(unsigned int w = 0, unsigned int h = 0, unsigned int d = 0)
    {
      m_observation = nullptr;
      m_size = 0;
      m_w = 0;
      m_h = 0;
      m_d = 0;
      init(w, h, d);
    }

    // Copy constructor
    Observation(Observation& other)
    {
      copy(other);
    }

    // Copy constructor
    Observation(const Observation& other)
    {
      copy(other);
    }

    // Destructor
    virtual ~Observation()
    {
      if (m_observation != nullptr)
        delete[] m_observation;
    }

    // Copy assignment operator
    Observation& operator= (Observation& other)
    {
      copy(other);
      return *this;
    }

    // Copy assignment operator
    Observation& operator= (const Observation& other)
    {
      copy(other);
      return *this;
    }

    void init(unsigned int w, unsigned int h = 0, unsigned int d = 0)
    {
      m_w = w;
      m_h = h;
      m_d = d;

      unsigned int size = m_w*m_h*m_d;

      if (m_size != size)
      {
        m_size = size;

        if (m_observation != nullptr)
        {
          delete m_observation;
        }

        m_observation = new t_type[m_size];
      }

      for (unsigned int i = 0; i < m_size; i++)
        m_observation[i] = 0;
    }

  protected:
    void copy(Observation& other)
    {
      init(other.m_w, other.m_h, other.m_d);

      for (unsigned int i = 0; i < m_size; i++)
        m_observation[i] = other.m_observation[i];

    }

    void copy(const Observation& other)
    {
      init(other.m_w, other.m_h, other.m_d);

      for (unsigned int i = 0; i < m_size; i++)
        m_observation[i] = other.m_observation[i];
    }

  public:
    unsigned int w()
    {
      return m_w;
    }

    unsigned int h()
    {
      return m_h;
    }

    unsigned int d()
    {
      return m_d;
    }

    unsigned int size()
    {
      return size;
    }

    t_type get(unsigned int x, unsigned int y = 0, unsigned int z = 0)
    {
      unsigned int idx = (z*m_h + y)*m_w + x;
      return m_observation[idx];
    }

    void set(t_type value, unsigned int x, unsigned int y = 0, unsigned int z = 0)
    {
      unsigned int idx = (z*m_h + y)*m_w + x;
      m_observation[idx] = value;
    }
};

#endif
