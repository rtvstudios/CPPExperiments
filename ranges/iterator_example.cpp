module;

import <iterator>;
import <ranges>;

export module iterator_example;

export template<typename T>
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


export template<typename T>
constexpr auto even_view = std::ranges::subrange<even_iterator<T>, std::unreachable_sentinel_t>{};


