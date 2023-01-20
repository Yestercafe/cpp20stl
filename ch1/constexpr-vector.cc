#include <iostream>
#include <vector>

constexpr std::vector<int> make_vector() {
    return {1, 2, 3, 4};
}

int main()
{
    constexpr std::size_t s = ::make_vector().size();
    std::cout << s << std::endl;
    return 0;
}
