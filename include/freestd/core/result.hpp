#ifndef FREESTD_CORE_RESULT_HPP
#define FREESTD_CORE_RESULT_HPP

namespace freestd::core {
    template <typename T, typename E>
    class Result {
    public:
        constexpr explicit Result(T ok) noexcept
            : value{ok}, state{State::Ok} {}

        constexpr explicit Result(E err) noexcept
            : value{err}, state{State::Err} {}

        // TODO: figure out what to do with those constructors and assignment operators
        constexpr Result(const Result<T, E>& other) noexcept = delete;
        constexpr Result& operator=(const Result<T, E>& other) noexcept = delete;
        constexpr Result(Result<T, E>&& other) noexcept = delete;
        constexpr Result& operator=(Result<T, E>&& other) noexcept = delete;

        [[nodiscard]] constexpr T unwrap(this auto&& self) noexcept {
            return self.value.ok;
        }

        [[nodiscard]] constexpr E unwrap_err(this auto&& self) noexcept {
            return self.value.err;
        }

        [[nodiscard]] constexpr bool is_ok(this auto&& self) noexcept {
            return self.state == State::Ok;
        }

        [[nodiscard]] constexpr bool is_err(this auto&& self) noexcept {
            return self.state == State::Err;
        }

    private:
        enum class State {
            Ok,
            Err,
        };

        union Value {
            T ok;
            E err;

            constexpr Value(T value) noexcept
                : ok{value} {}

            constexpr Value(E value) noexcept
                : err{value} {}
        };

        State state;
        Value value;
    };
} // namespace freestd::core

#endif // FREESTD_CORE_RESULT_HPP
