#include <memory>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <ranges>
#include <iterator>
namespace ranges = std::ranges;

template<typename T>
class Container {
    std::unique_ptr<T[]> c_ {};
    std::size_t n_elements_ {};
    class iterator {
        T* ptr_;
    public:
        using iterator_concept  = std::contiguous_iterator_tag;
        using iterator_category = std::contiguous_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        iterator(T* ptr = nullptr) : ptr_{ptr} {}
        const auto operator<=>(const iterator& rhs) const {
            return ptr_ <=> rhs.ptr_;
        }
        const bool operator==(const iterator& rhs) const {
            return ptr_ == rhs.ptr_;
        }
        T& operator*() const {
            return *ptr_;
        }
        iterator operator+(const std::size_t n) const {
            std::cout << "Container::operator+(size_t)" << std::endl;
            return iterator(ptr_ + n);
        }
        friend const iterator operator+(const std::size_t n, const iterator& rhs) {
            return iterator(rhs.ptr_ + n);
        }
        const iterator operator-(const size_t n) {
            return iterator(ptr_ - n);
        }
        const std::size_t operator-(const iterator& rhs) {
            return ptr_ - rhs.ptr_;
        }
        iterator& operator++() {
            ++ptr_;
            return *this;
        }
        iterator operator++(int) {
            auto ret = *this;
            ++ptr_;
            return ret;
        }
        iterator& operator--() {
            --ptr_;
            return *this;
        }
        iterator operator--(int) {
            auto ret = *this;
            --ptr_;
            return ret;
        }
    };

public:
    Container(std::initializer_list<T> l) : n_elements_{l.size()} {
        c_ = std::make_unique<T[]>(n_elements_);
        std::size_t index {};
        for (T e : l) {
            c_[index++] = e;
        }
    }
    Container(std::size_t sz) : n_elements_{sz} {
        c_ = std::make_unique<T[]>(n_elements_);
    }

    std::size_t size() const { return n_elements_; }
    const T& operator[](const size_t index) const {
        return c_[index];
    }
    T& at(const std::size_t index) const {
        if (index > n_elements_ - 1) {
            throw std::out_of_range("Container::at(): index out of range");
        }
        return c_[index];
    }
    iterator begin() const { return iterator(c_.get()); }
    iterator end() const { return iterator(c_.get() + n_elements_); }
};

int main()
{
    Container<int> c {4, 2, 5, 1, 3};
    std::cout << c.at(3) << std::endl;
    for (auto e : c | std::ranges::views::reverse) {
        std::cout << e << ' ';
    }
    endl(std::cout);

    auto it1 = c.begin();
    ranges::advance(it1, 3);
    std::cout << "*it1(c[3]) = " << *it1 << std::endl;
    
    auto it2 = c.begin();
    it2 = it2 + 3;
    std::cout << "*it2(c[3]) = " << *it2 << std::endl;

    return 0;
}
