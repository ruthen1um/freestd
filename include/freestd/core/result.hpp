#ifndef FREESTD_CORE_RESULT_HPP
#define FREESTD_CORE_RESULT_HPP

namespace freestd::core {
    template <typename T, typename E>
    class Result {
    public:
        constexpr explicit Result(T ok) noexcept
            : m_value(ok), m_state(State::Ok) {}

        constexpr explicit Result(E err) noexcept
            : m_value(err), m_state(State::Err) {}

        constexpr Result(const Result<T, E>& other) noexcept = delete;
        constexpr Result& operator=(const Result<T, E>& other) noexcept = delete;

        constexpr Result(Result<T, E>&& other) noexcept = delete;
        constexpr Result& operator=(Result<T, E>&& other) noexcept = delete;

        [[nodiscard]] constexpr T unwrap() const noexcept {
            return m_value.ok;
        }

        [[nodiscard]] constexpr E unwrap_err() const noexcept {
            return m_value.err;
        }

        [[nodiscard]] constexpr bool is_ok() const noexcept {
            return m_state == State::Ok;
        }

        [[nodiscard]] constexpr bool is_err() const noexcept {
            return m_state == State::Err;
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
                : ok(value) {}

            constexpr Value(E value) noexcept
                : err(value) {}
        };

        State m_state;
        Value m_value;
    };

    template <typename T, typename E>
    class Result<T&, E> {
    public:
        constexpr explicit Result(T& ok) noexcept
            : m_value(ok), m_state(State::Ok) {}

        constexpr explicit Result(E err) noexcept
            : m_value(err), m_state(State::Err) {}

        constexpr Result(const Result<T&, E>& other) noexcept = delete;
        constexpr Result& operator=(const Result<T&, E>& other) noexcept = delete;

        constexpr Result(Result<T&, E>&& other) noexcept = delete;
        constexpr Result& operator=(Result<T&, E>&& other) noexcept = delete;

        [[nodiscard]] constexpr const T& unwrap() const noexcept {
            return *m_value.ok;
        }

        [[nodiscard]] constexpr T& unwrap() noexcept {
            return *m_value.ok;
        }

        [[nodiscard]] constexpr E unwrap_err() const noexcept {
            return m_value.err;
        }

        [[nodiscard]] constexpr bool is_ok() const noexcept {
            return m_state == State::Ok;
        }

        [[nodiscard]] constexpr bool is_err() const noexcept {
            return m_state == State::Err;
        }

    private:
        enum class State {
            Ok,
            Err,
        };

        union Value {
            T* ok;
            E err;

            constexpr Value(T& value) noexcept
                : ok(&value) {}

            constexpr Value(E value) noexcept
                : err(value) {}
        };

        State m_state;
        Value m_value;
    };

    template <typename T, typename E>
    class Result<T, E&> {
    public:
        constexpr explicit Result(T ok) noexcept
            : m_value(ok), m_state(State::Ok) {}

        constexpr explicit Result(E& err) noexcept
            : m_value(err), m_state(State::Err) {}

        constexpr Result(const Result<T, E&>& other) noexcept = delete;
        constexpr Result& operator=(const Result<T, E&>& other) noexcept = delete;

        constexpr Result(Result<T, E&>&& other) noexcept = delete;
        constexpr Result& operator=(Result<T, E&>&& other) noexcept = delete;

        [[nodiscard]] constexpr T unwrap() const noexcept {
            return m_value.ok;
        }

        [[nodiscard]] constexpr const E& unwrap_err() const noexcept {
            return *m_value.err;
        }

        [[nodiscard]] constexpr E& unwrap_err() const noexcept {
            return *m_value.err;
        }

        [[nodiscard]] constexpr bool is_ok() const noexcept {
            return m_state == State::Ok;
        }

        [[nodiscard]] constexpr bool is_err() const noexcept {
            return m_state == State::Err;
        }

    private:
        enum class State {
            Ok,
            Err,
        };

        union Value {
            T ok;
            E* err;

            constexpr Value(T value) noexcept
                : ok(value) {}

            constexpr Value(E& value) noexcept
                : err(&value) {}
        };

        State m_state;
        Value m_value;
    };

    template <typename T, typename E>
    class Result<T&, E&> {
    public:
        constexpr explicit Result(T& ok) noexcept
            : m_value(ok), m_state(State::Ok) {}

        constexpr explicit Result(E& err) noexcept
            : m_value(err), m_state(State::Err) {}

        constexpr Result(const Result<T&, E&>& other) noexcept = delete;
        constexpr Result& operator=(const Result<T&, E&>& other) noexcept = delete;

        constexpr Result(Result<T&, E&>&& other) noexcept = delete;
        constexpr Result& operator=(Result<T&, E&>&& other) noexcept = delete;

        [[nodiscard]] constexpr const T& unwrap() const noexcept {
            return *m_value.ok;
        }

        [[nodiscard]] constexpr T& unwrap() noexcept {
            return *m_value.ok;
        }

        [[nodiscard]] constexpr const E& unwrap_err() const noexcept {
            return *m_value.err;
        }

        [[nodiscard]] constexpr E& unwrap_err() const noexcept {
            return *m_value.err;
        }

        [[nodiscard]] constexpr bool is_ok() const noexcept {
            return m_state == State::Ok;
        }

        [[nodiscard]] constexpr bool is_err() const noexcept {
            return m_state == State::Err;
        }

    private:
        enum class State {
            Ok,
            Err,
        };

        union Value {
            T* ok;
            E* err;

            constexpr Value(T& value) noexcept
                : ok(&value) {}

            constexpr Value(E& value) noexcept
                : err(&value) {}
        };

        State m_state;
        Value m_value;
    };
} // namespace freestd::core

#endif // FREESTD_CORE_RESULT_HPP
