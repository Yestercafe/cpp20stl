#include <iostream>
#include <string>
using std::string;

constexpr string make_string() {
    return "abc";
}

int main()
{
    constexpr auto s {make_string().length()};
    std::cout << s << std::endl;
    return 0;
}
