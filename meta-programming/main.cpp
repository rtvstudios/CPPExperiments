import <iostream>;
import <initializer_list>;

template<std::size_t N>
struct fixed_str {
    constexpr fixed_str(const char (&v)[N+1]) {
        std::copy_n(v, N+1, data);
    }

    auto operator<=>(const fixed_str &) const = default;

    std::size_t size() const {
        return N;
    }

    char data[N+1] = {};

    friend std::ostream& operator <<(std::ostream &out, const fixed_str &str) {
        out << str.data;
        return out;
    }
};

template<std::size_t N> fixed_str(const char (&v)[N]) -> fixed_str<N-1>;

template<fixed_str Name, typename Value>
struct member {

    constexpr static auto name() {
        return Name;
    }
    Value value;

    friend std::ostream& operator <<(std::ostream &out, const member &v) {
        out << "{\"" << v.name() << "\",\"" << v.value << "\"}";
        return out;
    }
};

template<typename... Members>
struct meta_struct: public Members... {
};

template<fixed_str tag, typename T>
decltype(auto) get_impl(const member<tag, T> &m) {
    return m;
}

template<fixed_str tag, typename meta_struct>
decltype(auto) get(meta_struct &&s) {
    return get_impl<tag>(std::forward<meta_struct>(s));
}

template<fixed_str tag, typename meta_struct>
decltype(auto) get_value(meta_struct &&s) {
    return get_impl<tag>(std::forward<meta_struct>(s)).value;
}

int main(int, char **)
{
    {
        fixed_str name{"Fixed String"};
        std::cout << name << std::endl;
    }

    {
        member<"Age", int> age1{ 50 };
        std::cout << age1 << std::endl; 
    }

    {
        meta_struct<member<"Name", std::string>, member<"Age", int>> data{"Jhon", 20};
        std::cout << get<"Name">(data) << std::endl;
        std::cout << get<"Age">(data) << std::endl;

        std::cout << get_value<"Name">(data) << std::endl;
        std::cout << get_value<"Age">(data) << std::endl;
    }
    

    return 0;
}

