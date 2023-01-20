#include <iostream>
#include <ranges>
#include <vector>
namespace ranges = std::ranges;
namespace views = ranges::views;

int main()
{
    const std::vector nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result = nums | views::take(5) | views::reverse;
    for (auto v : result)
        std::cout << v << ' ';
    endl(std::cout);
    
    for (auto v : nums | views::filter([](int i) { return i % 2 == 0; })) {
        std::cout << v << ' ';
    }
    endl(std::cout);

    for (auto v : nums | views::transform([](int i) { return i * i; })) {
        std::cout << v << ' ';
    }
    endl(std::cout);

    return 0;
}

