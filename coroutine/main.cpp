#include <iostream>
#include <coroutine>

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/n4861.pdf
struct generator {
    struct promise_type;

    using handle = std::coroutine_handle < promise_type >;

    struct promise_type {
        int current_value;

        static auto get_return_object_on_allocation_failure() {
            return generator {
            nullptr};
        }

        auto get_return_object() {
            return generator {
            handle::from_promise(*this)};
        }

        auto initial_suspend() {
            return std::suspend_always {
            };
        }

        auto final_suspend() noexcept(true) {
            return std::suspend_always {
            };
        }

        void unhandled_exception() {
            std::terminate();
        }

        void return_void() {
        }

        auto yield_value(int value) {
            current_value = value;
            return std::suspend_always {
            };
        }
    };

    bool move_next() {
        return coro ? (coro.resume(), !coro.done()) : false;
    }

    int current_value() {
        return coro.promise().current_value;
    }

    generator(generator const &) = delete;

    generator(generator && rhs):coro(rhs.coro) {
        rhs.coro = nullptr;
    }

    ~generator() {
        if (coro) {
            coro.destroy();
        }
    }

private:
    generator(handle h):coro(h) {
    }

    handle coro;
};

generator f() {
    for (int i=0; i<10; ++i) {
        co_yield i;
    }
}

int main() {
    auto g = f();

    while (g.move_next()) {
        std::cout << g.current_value() << std::endl;
    }
}

