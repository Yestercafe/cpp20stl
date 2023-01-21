#include <regex>
#include <ranges>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

namespace ranges = std::ranges;
namespace regex_constants = std::regex_constants;

namespace bw {
constexpr const char* re {"(\\w+)"};
}

int main()
{
    std::map<std::string, int> wordmap {};
    std::vector<std::pair<std::string, int>> wordvec {};
    std::regex word_re(bw::re);
    std::size_t total_words {};

    for (std::string s {}; std::cin >> s; ) {
        auto words_begin { std::sregex_iterator(s.begin(), s.end(), word_re) };
        auto words_end { std::sregex_iterator() };

        for (auto r_it { words_begin }; r_it != words_end; ++r_it) {
            std::smatch match { *r_it };
            auto word_str { match.str() };
            ranges::transform(word_str, word_str.begin(), [](unsigned char c) { return std::tolower(c); });
            auto [map_it, result] = wordmap.try_emplace(word_str, 0);
            auto& [w, count] = *map_it;
            ++total_words;
            ++count;
        }
    }

    auto unique_words = wordmap.size();
    wordvec.reserve(unique_words);
    ranges::move(wordmap, back_inserter(wordvec));
    ranges::sort(wordvec, [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    std::cout << "total word count: " << total_words << std::endl;
    std::cout << "unique word count: " << unique_words << std::endl;

    for (int limit {20}; auto& [w, count] : wordvec) {
        std::cout << count << ", " << w << std::endl;
        if (--limit == 0) break;
    }

    return 0;
}
