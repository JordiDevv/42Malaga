#include <cstddef>

template <typename T, typename Func>
void iter(T* Array, size_t length, Func f)
{
    for (int i = 0; i < length; i++) f(Array[i]);
}
