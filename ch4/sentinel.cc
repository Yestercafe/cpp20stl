#include <iostream>

class cstr_itr {
    using sentinel_t = const char;
    constexpr static sentinel_t nullchar = '\0';
    const char* s_ {};
public:
    explicit cstr_itr(const char* str) : s_{str} {}
    char operator*() const { return *s_; }
    cstr_itr& operator++() {
        ++s_;
        return *this;
    }
    bool operator!=(sentinel_t) const {
        return s_ != nullptr && *s_ != nullchar;
    }
    cstr_itr begin() const { return *this; }
    sentinel_t end() const { return nullchar; }
};

void print_cstr(const char* s) {
    std::cout << s << ": ";
    for (char c : cstr_itr(s)) {
        std::printf("%02x ", c);
    }
    endl(std::cout);
}

int main()
{
    const char carray[] {"array"};
    print_cstr(carray);

    const char* cstr {"c-string"};
    print_cstr(cstr);

    return 0;
}
