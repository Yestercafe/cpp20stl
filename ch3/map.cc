#include <iostream>
#include <map>
#include <string>

template<typename Map, typename Key>
bool swap_key(Map& m, const Key& k1, const Key& k2) {
    auto n1 { m.extract(k1) };
    auto n2 { m.extract(k2) };
    if (!n1 || !n2) return false;
    std::swap(n1.key(), n2.key());
    std::cout << n1.mapped() << " " << n2.mapped() << std::endl;
    m.insert(std::move(n1));
    m.insert(std::move(n2));
    return true;
}

template<typename Map>
void printm(const Map& m) {
    std::cout << "Rank: " << std::endl;
    for (const auto& [k, v] : m) {
        std::cout << k << ": " << v << std::endl;
    }
}

int main()
{

    std::map<int, std::string> m {
        {1, "Mario"}, {2, "Luigi"}, {3, "Bowser"}, 
        {4, "Peach"}, {5, "Donkey Kong Jr"}
    };
    printm(m);
    swap_key(m, 3, 5);
    printm(m);

    std::multimap<int, std::string> mm {
        {1, "a"}, {1, "b"}, {2, "c"}, {2, "d"}, {2, "e"}
    };
    printm(mm);
    swap_key(mm, 1, 2);
    printm(mm);

    return 0;
}
