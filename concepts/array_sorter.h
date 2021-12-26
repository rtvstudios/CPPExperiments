
#ifndef ARRAY_SORTER_H
#define ARRAY_SORTER_H

#include <algorithm>
#include <array>
#include <concepts>

template<class T>
concept Sortable = requires(T a, T b) {
        { a < b } -> std::convertible_to<bool>;
};

template <Sortable T, int n>
consteval auto sort(const T(&arr)[n]) {
    std::array<T, n> res;
    std::copy(std::begin(arr), std::end(arr), std::begin(res));
    std::sort(std::begin(res), std::end(res));
    return res;
}


#endif
