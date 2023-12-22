#ifndef STATIC_ARRAY_HPP
#define STATIC_ARRAY_HPP 1
// TODO Create static array similar to std::array -> Done
// TODO overload the std::ostream for the class -> Done
// TODO Create Iterator support for static_array

#include "../config.hpp"
#include <cstdlib>
#include <iostream>
NS_BEGIN( my )

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
        exit( 0 ); // TODO assertion "access out of range"
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

template <class T, my::size_t N>
std::ostream &operator<<( std::ostream &os, my::static_array<T, N> &arr )
{
    for ( my::size_t i = 0; i < N; i++ )
    {
        std::cout << arr[i] << " ";
    }
    return os;
}

#endif // STATIC_ARRAY_HPP
