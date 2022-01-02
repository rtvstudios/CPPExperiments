import <iostream>;
import <vector>;
import <algorithm>;

class Data {
    int mI;
public:
    Data(int i) : mI{i}{}
    auto operator<=>(const Data &rhs) const {
        return mI <=> rhs.mI;
    }

    friend std::ostream& operator<<(std::ostream& os, const Data &d)
    {
        os << d.mI;
            return os;
    }
};


int main(int argc, char **argv) {
    std::vector ints = {Data{1}, Data{10}, Data{2}, Data{3}, Data{0}};

    std::sort(ints.begin(), ints.end());

    for (auto i: ints) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}

