module;

import <iterator>;
import <ranges>;

export module view_example;

export template<typename T>
class odd_iterator {
public:
    using difference_type = std::ptrdiff_t;

    odd_iterator() = default;

    T& operator*() {
        return mVal;
    }

    const T& operator*() const {
        return mVal;
    }

    odd_iterator& operator++() {
        mVal += 2;
        return *this;
    }

    odd_iterator operator++(int) {
        auto res = *this;
        ++(*this);
        return res;
    }

    bool operator==(const odd_iterator&) const = default;

private:
    T mVal{1};
};


template<typename T>
class odd_view_impl: public std::ranges::view_interface<odd_view_impl<T>> {
    odd_iterator<T> mIter;

public:
    odd_view_impl() = default;
    odd_view_impl(odd_iterator<T> iter) : mIter{std::move(iter)} {}

    auto begin() {
        return mIter;
    }

    auto end() {
        return std::unreachable_sentinel_t{};
    }
}; 

struct odd_view_impl_fn {
    template<typename T>
    constexpr auto operator()() {
        return odd_view_impl<T>();
    }
};

export inline constexpr auto odd_view = odd_view_impl_fn{};

