import <iostream>;
import <vector>;
import <ranges>;
import <initializer_list>;
import <iterator>;
import iterator_example;

//using namespace rtv;

int main(int argc, char **argv) {
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };

    for (int i : std::views::iota(0, 6)
               | std::views::filter(even)
               | std::views::transform(square)) {

        std::cout << i << ' ';
    }
    std::cout << std::endl;

    // iterator
    for (auto i: even_view<int> |
                 std::views::take(5)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}

