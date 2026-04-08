#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>
#include <iostream>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(v, 4);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(l, 2);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(l, 4);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }

    std::set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);

    try
    {
        std::set<int>::iterator it = easyfind(s, 2);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }

    try
    {
        std::set<int>::iterator it = easyfind(s, 4);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not found" << std::endl;
    }
}
