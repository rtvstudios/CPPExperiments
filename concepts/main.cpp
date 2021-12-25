
#include <iostream>

#include "array_sorter.h"

void print(const auto &v) {
    for (const auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

struct Data {
    int i;
    int j;
    
    constexpr bool operator<(const Data &oth) const {
        return i<oth.i;
    }
    
    friend std::ostream & operator<<(std::ostream &str, const Data &data) {
        str << "(" << data.i << ", " << data.j << ")";
        return str;
    }
};

int main(int, char **) {
    
    std::cout << "Welcome to Concepts Examples" << std::endl;
    
    print(sort({1, 5, 2, 4}));
    
    print(sort({Data{1, 2}, Data{10, 20},Data{3, 4}}));

    return 0;
}
