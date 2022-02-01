import <iostream>;
import <initializer_list>;

template<std::size_t N>
struct FixedString {
    constexpr FixedString(const char (&v)[N+1]) {
        std::copy_n(v, N+1, data);
    }

    auto operator<=>(const FixedString &) const = default;

    std::size_t size() const {
        return N;
    }

    char data[N+1] = {};

    friend std::ostream& operator <<(std::ostream &out, const FixedString &str) {
        out << str.data;
        return out;
    }
};

template<std::size_t N> FixedString(const char (&v)[N]) -> FixedString<N-1>;

template<FixedString Name, typename Value>
struct Member {
    constexpr static auto name() {
        return Name;
    }
    Value value;

    friend std::ostream& operator <<(std::ostream &out, const Member &v) {
        out << "{\"" << v.name() << "\",\"" << v.value << "\"}";
        return out;
    }
};

template<typename... Members>
struct MetaStruct: public Members... {
};

template<FixedString tag, typename T>
decltype(auto) getImpl(const Member<tag, T> &m) {
    return m;
}

template<FixedString tag, typename MetaStruct>
decltype(auto) get(MetaStruct &&s) {
    return getImpl<tag>(std::forward<MetaStruct>(s));
}

template<FixedString tag, typename MetaStruct>
decltype(auto) get_value(MetaStruct &&s) {
    return getImpl<tag>(std::forward<MetaStruct>(s)).value;
}

int main(int, char **)
{
    {
        FixedString name{"Fixed String"};
        std::cout << name << std::endl;
    }

    {
        Member<"Age", int> age1{ 50 };
        std::cout << age1 << std::endl; 
    }

    {
        using Person = MetaStruct<Member<"Name", std::string>, Member<"Age", int>>;
        Person data{"Jhon", 20};
        std::cout << get<"Name">(data) << std::endl;
        std::cout << get<"Age">(data) << std::endl;

        std::cout << get_value<"Name">(data) << std::endl;
        std::cout << get_value<"Age">(data) << std::endl;
    }

    return 0;
}

