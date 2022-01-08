import <iostream>;
import <vector>;
import <ranges>;
import <initializer_list>;
import <iterator>;

template<typename T>
class even_iterator {
public:
    using difference_type = std::ptrdiff_t;

    even_iterator() = default;

    T& operator*() {
        return mVal;
    }

    const T& operator*() const {
        return mVal;
    }

    even_iterator& operator++() {
        mVal += 2;
        return *this;
    }

    even_iterator operator++(int) {
        auto res = *this;
        ++(*this);
        return res;
    }

    bool operator==(const even_iterator&) const = default;

private:
    T mVal{0};
};

template<typename T>
constexpr auto even_view = std::ranges::subrange<even_iterator<T>, std::unreachable_sentinel_t>{};

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

