#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>

using input_it = std::istream_iterator<std::string>;

int main()
{
    std::set<std::string> words;
    input_it it { std::cin };
    input_it end {};
    std::copy(it, end, std::inserter(words, words.end()));

    for (const std::string& w : words) {
        std::cout << w << ' ';
    }
    endl(std::cout);

    return 0;
}
