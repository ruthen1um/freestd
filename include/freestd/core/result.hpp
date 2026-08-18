#ifndef FREESTD_CORE_RESULT_HPP
#define FREESTD_CORE_RESULT_HPP

namespace freestd::core {
    template <typename T, typename E>
    class Result {
    public:
        Result() = delete;

        constexpr static Result ok(T value) noexcept {
            return Result{Storage::ok(value), State::Ok};
        }

        constexpr static Result err(E err) noexcept {
            return Result{Storage::err(err), State::Err};
        }

        // TODO: figure out what to do with those constructors and assignment operators
        constexpr Result(const Result<T, E>& other) noexcept = delete;
        constexpr Result& operator=(const Result<T, E>& other) noexcept = delete;
        constexpr Result(Result<T, E>&& other) noexcept = delete;
        constexpr Result& operator=(Result<T, E>&& other) noexcept = delete;

        [[nodiscard]] constexpr T unwrap(this auto&& self) noexcept {
            return self.storage.value;
        }

        [[nodiscard]] constexpr E unwrap_err(this auto&& self) noexcept {
            return self.storage.error;
        }

        [[nodiscard]] constexpr bool is_ok(this auto&& self) noexcept {
            return self.state == State::Ok;
        }

        [[nodiscard]] constexpr bool is_err(this auto&& self) noexcept {
            return self.state == State::Err;
        }

    private:
        union Storage {
            T value;
            E error;

            constexpr static Storage ok(T value) noexcept {
                auto s = Storage{};
                s.value = value;
                return s;
            }

            constexpr static Storage err(E err) noexcept {
                auto s = Storage{};
                s.error = err;
                return s;
            }
        };

        enum class State {
            Ok,
            Err,
        };

        Storage storage;
        State state;

        constexpr explicit Result(Storage storage, State state) noexcept
            : storage{storage}, state{state} {}
    };
} // namespace freestd::core

#endif // FREESTD_CORE_RESULT_HPP
