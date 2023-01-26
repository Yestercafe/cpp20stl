#include <string_view>
#include <iostream>
#include <ranges>
#include <cstddef>
#include <type_traits>

void printc(const auto& v, const std::string_view s = "") {
    if (s.size()) std::cout << s << ": ";
    for (auto e : v) std::cout << e << ' ';
    endl(std::cout);
}

class fib_generator {
    using fib_t = unsigned long;
    fib_t stop_ {};
    fib_t count_ {};
    fib_t a_ {0};
    fib_t b_ {1};

    constexpr void do_fib() {
        const fib_t old_b = b_;
        b_ += a_;
        a_ = old_b;
    }

public:
    // to make the generator work with the algorithm library (include C++20 range versions)
    using iterator_concept  = std::forward_iterator_tag;
    using iterator_category = std::forward_iterator_tag;
    using value_type        = std::remove_cv_t<fib_t>;
    using difference_type   = std::ptrdiff_t;
    using pointer           = const fib_t*;
    using reference         = const fib_t&;

public:
    explicit fib_generator(fib_t stop = 0) : stop_{stop} {}

    fib_t operator*() const {
        return b_;
    }
    constexpr fib_generator& operator++() {
        do_fib();
        ++count_;
        return *this;
    }
    fib_generator operator++(int) {
        auto temp {*this};
        ++*this;
        return temp;
    }
    bool operator!=(const fib_generator& rhs) const {
        return count_ != rhs.count_;
    }
    bool operator==(const fib_generator& rhs) const {
        return !this->operator!=(rhs);
    }
    const fib_generator& begin() const { return *this; }
    const fib_generator end() const {
        auto sentinel = fib_generator();
        sentinel.count_ = stop_;
        return sentinel;
    }
    fib_t size() { return stop_; }
};

int main()
{
    printc(fib_generator(10) | std::ranges::views::transform([](const auto a) { return a * a; }));
    return 0;
}
