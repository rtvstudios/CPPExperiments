module;

import <iterator>;
import <ranges>;

export module view_example;

class odd_iterator {
public:
    using difference_type = std::ptrdiff_t;

    odd_iterator() = default;

    int& operator*() {
        return mVal;
    }

    const int& operator*() const {
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
    int mVal{1};
};


class odd_view_impl: public std::ranges::view_interface<odd_view_impl> {
    odd_iterator mIter;

public:
    odd_view_impl() = default;
    odd_view_impl(odd_iterator iter) : mIter{std::move(iter)} {}

    auto begin() {
        return mIter;
    }

    auto end() {
        return std::unreachable_sentinel_t{};
    }
}; 

struct odd_view_impl_fn {
    constexpr auto operator()() const {
        return odd_view_impl();
    }
};

export inline constexpr auto odd_view = odd_view_impl_fn{};

