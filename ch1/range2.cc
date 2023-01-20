#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <iterator>
namespace ranges = std::ranges;
namespace views = ranges::views;

int main()
{
    std::vector v {2, 5, 3, 1, 4};
    ranges::sort(views::take(v, 4));
    ranges::copy(v, std::ostream_iterator<int>(std::cout, ", "));

    auto _ = views::take(v, 5);         // pass
    ranges::take_view(v, 5);   // pass
    auto _2 = v | views::take(5);        // pass
    for (auto a : _2) {
        std::cout << a << std::endl;
    }
    // v | ranges::take_view(5);  // dame!!

    return 0;
}
