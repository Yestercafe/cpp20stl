#include <iostream>
#include <span>

template<typename T>
void pspan(std::span<T> s) {
    std::cout << "number of elements: " << s.size() << std::endl;
    std::cout << "size of span: " << s.size_bytes() << std::endl;
    for (auto e : s)
        std::cout << e << ' ';
    endl(std::cout);
}

int main()
{
    int carray[] {1, 2, 3, 4, 5};
    pspan<int>(carray);
    return 0;
}
