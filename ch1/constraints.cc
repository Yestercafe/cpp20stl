#include <iostream>
#include <type_traits>
#include <concepts>
using std::cout, std::endl;

template<typename T>
constexpr bool is_gt_byte {sizeof(T) > 1};

template<typename T>
concept Number = is_gt_byte<T> && (std::integral<T> || std::floating_point<T>);

template<Number T>
T add(const T& r) {
    return 42 + r;
}

int main()
{
    cout << add(7) << endl;
    return 0;
}
