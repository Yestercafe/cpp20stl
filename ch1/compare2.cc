#include <iostream>

struct Frac {
    long n, d;
    constexpr Frac(long n, long d) : n{n}, d{d} {}
    constexpr double db1() const {
        return static_cast<double>(n) / static_cast<double>(d);
    }
    constexpr auto operator<=>(const Frac& rhs) const {
        return this->db1() <=> rhs.db1();
    } 
    constexpr bool operator==(const Frac& rhs) const {
        return this->db1() == rhs.db1();
    }
};

int main()
{
    constexpr Frac f1 {5, 3};
    constexpr Frac f2 {10, 6};
    constexpr Frac f3 {5, 4};

    static_assert(f1 == f2);
    static_assert(f1 > f3);
    static_assert(f3 <= f1);
    static_assert(f2 != f3);

    return 0;
}
