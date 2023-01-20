#include <iostream>

template <typename T>
class Sum {
    T v{};
public:
    template<typename... Ts>
    Sum(Ts&&... values) : v{ (values + ...) } {}
    const T& value() const { return v; }
};

template<typename... Ts>
Sum(Ts&&... values) -> Sum<std::common_type_t<Ts...>>;

int main()
{
    Sum s {1u, 2.0, 3, 4.0f};
    return 0;
}
