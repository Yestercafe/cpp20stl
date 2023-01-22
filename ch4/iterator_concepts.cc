#include <iostream>
#include <iterator>
#include <list>

template<std::random_access_iterator T>
void printc(const T& c) {
    for (auto e : c) {
        std::cout << e << ' ';
    }
    endl(std::cout);
    std::cout << "element 0: " << c[0] << std::endl;
}

int main()
{
    std::list<int> c {1, 2, 3, 4, 5};
    printc(c);
    return 0;
}
