#include <iostream>
#include <algorithm>
#include <cstddef>
#include <type_traits>

template<typename T>
class Seq {
    T start_ {};
    T end_ {};
public:
    Seq(T start, T end) : start_{start}, end_{end} {}
    class iterator {
    public:
        using iterator_concept  = std::forward_iterator_tag;
        using iterator_category = std::forward_iterator_tag;
        using value_type        = std::remove_cv_t<T>;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const T*;
        using reference         = const T&;
    private:
        T value_ {};
    public:
        explicit iterator(T position = 0) : value_{position} {}
        T operator*() const { return value_; }
        iterator& operator++() {
            ++value_;
            return *this;
        }
        bool operator!=(const iterator& rhs) const {
            return value_ != rhs.value_;
        }
        bool operator==(const iterator& rhs) const {
            return value_ == rhs.value_;
        }
    };

    iterator begin() const {
        return iterator{start_};
    }
    iterator end() const {
        return iterator{end_};
    }
};

int main()
{
    Seq<int> r {100, 110};
    for (auto v : r) {
        std::cout << v << ' ';
    }
    endl(std::cout);

    auto [min_it, max_it] = std::minmax_element(r.begin(), r.end());
    std::cout << *min_it << " - " << *max_it << std::endl;

    return 0;
}
