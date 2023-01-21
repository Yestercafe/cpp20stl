#include <unordered_map>
#include <iostream>

struct Coord {
    int x {};
    int y {};
};

bool operator==(const Coord& lhs, const Coord& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

namespace std {
template<>
struct hash<Coord> {
    std::size_t operator()(const Coord& c) const {
        return static_cast<size_t>(c.x) + static_cast<size_t>(c.y);
    }
};
}

using Coordmap = std::unordered_map<Coord, int>;

void print_cm(Coordmap& cm) {
    for (const auto& [key, value] : cm) {
        std::cout << "{(" << key.x << ", " << key.y << "), " << value << "} ";
    }
    endl(std::cout);
}

int main()
{
    Coordmap m {
        {{0, 0}, 1},
        {{0, 1}, 2},
        {{2, 1}, 3}
    };

    print_cm(m);

    return 0;
}
