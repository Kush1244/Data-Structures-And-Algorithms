#ifndef STATIC_ARRAY_HPP
#define STATIC_ARRAY_HPP 1

#include "../config.hpp"
#include <cstdlib>
#include <iostream>
NS_BEGIN( my )


template <typename T>
class iterator
{
  public:
    explicit iterator( T *ptr ) : m_Ptr( ptr )
    {
    }

    iterator &operator++( int )
    {
        m_Ptr++;
        return *this;
    }

    iterator &operator++()
    {
        m_Ptr++;
        return *this;
    }

    T &operator*()
    {
        return *m_Ptr;
    }
    T *&get_pointer()
    {
        return m_Ptr;
    }

  private:
    T *m_Ptr;
};

template <typename T>
bool operator!=( iterator<T> &first, iterator<T> &second )
{
    return first.get_pointer() != second.get_pointer();
}

/**
 * @brief Fixed Length Array
 *
 * @tparam T Data Type
 * @tparam N Fix Size Length (Known at compile Time)
 */
template <class T, my::size_t N>
class static_array
{
  public:
    static_array();
    explicit static_array( T t_initVal );
    my::size_t size();
    T &operator[]( my::size_t index );
    T &at( my::size_t index );
    T *&data();
    bool is_empty();
    void fill( T fillValue );
    iterator<T> begin();
    iterator<T> end();

  private:
    T mArr[N];
};

NS_END( my )

template <class T, my::size_t N>
std::ostream &operator<<( std::ostream &os, my::static_array<T, N> &arr );

/////////// IMPLEMENTATION ///////////////

template <class T, my::size_t N>
my::static_array<T, N>::static_array() = default;

template <class T, my::size_t N>
my::static_array<T, N>::static_array( T t_initVal )
{
    for ( my::size_t i = 0; i < N; i++ )
    {
        mArr[i] = t_initVal;
    }
}
template <class T, my::size_t N>
my::size_t my::static_array<T, N>::size()
{
    return N;
}

template <class T, my::size_t N>
T &my::static_array<T, N>::operator[]( my::size_t index )
{
    return mArr[index];
}

template <class T, my::size_t N>
T &my::static_array<T, N>::at( my::size_t index )
{
    if ( index >= N )
    {
        std::cout << "Index out of range" << std::endl; // TO REMOVE
        exit( 1 ); // TODO assertion "access out of range"
    }
    return mArr[index];
}


template <class T, my::size_t N>
T *&my::static_array<T, N>::data()
{
    return mArr;
}

template <class T, my::size_t N>
bool my::static_array<T, N>::is_empty()
{
    return N == 0;
}

template <class T, my::size_t N>
void my::static_array<T, N>::fill( T fillValue )
{
    for ( my::size_t i = 0; i < N; i++ )
    {
        mArr[i] = fillValue;
    }
}
//////////////////////////// std::cout implementation ///////////////
template <class T, my::size_t N>
std::ostream &operator<<( std::ostream &os, my::static_array<T, N> &arr )
{
    for ( my::size_t i = 0; i < N; i++ )
    {
        std::cout << arr[i] << " ";
    }
    return os;
}

//////////////////////////////// Iterator Implementation ////////////////////
template <class T, my::size_t N>
my::iterator<T> my::static_array<T, N>::begin()
{
    return my::iterator<T>( mArr );
}

template <class T, my::size_t N>
my::iterator<T> my::static_array<T, N>::end()
{
    return my::iterator<T>( mArr + N );
}

#endif // STATIC_ARRAY_HPP
