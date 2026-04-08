#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int easyfind(T* container, int arg)
{
    for(int i = 0; i < container.size(); i++)
        if (container[i] == arg) return container[i];
    return -1;
}

#endif
