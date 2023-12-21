#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <stdint.h>
#define NS_BEGIN( X )                                                          \
    namespace X                                                                \
    {

#define NS_END( X ) }

NS_BEGIN( my )
using size_t = uint64_t;
NS_END( my )
#endif // CONFIG_HPP
