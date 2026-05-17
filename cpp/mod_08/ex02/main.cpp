#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
      // **************************************************** //
     //                 MUTANTSTACK TEST                     //
    // **************************************************** //

    std::cout << "MUTANTSTACK TEST" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "MS top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "MS size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    std::cout << "LOOP FOR MS ELEMENTS" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

      // **************************************************** //
     //                     LIST TEST                        //
    // **************************************************** //

    std::cout << "\nLIST TEST" << std::endl;

    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << "LIST back: " << list.back() << std::endl;

    list.pop_back();

    std::cout << "LIST size: " << list.size() << std::endl;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator l_it = list.begin();
    std::list<int>::iterator l_ite = list.end();
    ++l_it;
    --l_it;

    std::cout << "LOOP FOR LIST ELEMENTS" << std::endl;
    while (l_it != l_ite)
    {
        std::cout << *l_it << std::endl;
        ++l_it;
    }

    std::list<int> l(list);
    return 0;
}
