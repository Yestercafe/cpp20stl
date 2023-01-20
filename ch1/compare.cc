#include <iostream>
#include <utility>

struct Num {
    int n;
    constexpr Num() : n{} {}
    constexpr Num(int n) : n{n} {}
    auto operator<=>(const Num& rhs) const = default;
};

int main()
{
    int a {-3};
    unsigned b {7};
    if (a < b) {
        std::puts("YES");
    } else {
        std::puts("NO");
    }

    if (std::cmp_less(a, b)) {
        std::puts("YES");
    } else {
        std::puts("NO");
    }

    return 0;
}