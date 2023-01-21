#include <cctype>
#include <deque>
#include <limits>
#include <sstream>
#include <utility>
#include <functional>
#include <map>
#include <cmath>
#include <iostream>

bool is_numeric(const std::string& s) {
    for (const char c : s) {
        if (c != '.' && !std::isdigit(c)) return false;
    }
    return true;
}

class RPN {
    std::deque<double> deq_ {};
    constexpr static double zero_ { 0.0 };
    constexpr static double inf_ { std::numeric_limits<double>::infinity() };
public:
    double op(const std::string& s) {
        if (::is_numeric(s)) {
            auto v { std::stod(s, nullptr) };
            deq_.push_front(v);
            return v;
        }
        else return optor(s);
    }

    void clear() {
        deq_.clear();
    }

    std::string get_stack_string() const {
        std::stringstream ss;
        for (auto v : deq_) {
            ss << v << ' ';
        }
        return ss.str();
    }

    std::pair<double, double> pop_get2() {
        if (deq_.size() < 2) return {zero_, zero_};
        auto v1 { deq_.front() };
        deq_.pop_front();
        auto v2 { deq_.front() };
        deq_.pop_front();
        return {v2, v1};
    }

    double optor(const std::string& op) {
        static std::map<std::string, std::function<double(double, double)>> opmap {
            {"+", [](double l, double r) { return l + r; }},
            {"-", [](double l, double r) { return l - r; }},
            {"*", [](double l, double r) { return l * r; }},
            {"/", [](double l, double r) { return l / r; }},
            {"^", [](double l, double r) { return std::pow(l, r); }},
            {"%", [](double l, double r) { return std::fmod(l, r); }},
        };
        if (!opmap.contains(op)) return zero_;
        auto [l, r] = pop_get2();
        if (op == "/" && r == zero_) deq_.push_front(inf_);
        else deq_.push_front(opmap.at(op)(l, r));
        return deq_.front();
    }
};

int main()
{
    RPN rpn;

    for (std::string o {}; std::cin >> o; ) {
        rpn.op(o);
        auto stack_str { rpn.get_stack_string() };
        std::cout << o << ": " << stack_str << std::endl;
    }

    return 0;
}
