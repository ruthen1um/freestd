#ifndef FREESTD_CORE_RESULT_HPP
#define FREESTD_CORE_RESULT_HPP

namespace freestd::core {
    template <typename T, typename E>
    class Result {
    public:
        Result() = delete;

        constexpr static Result ok(T val) noexcept {
            return Result(Storage::ok(val), State::Ok);
        }

        constexpr static Result err(E err) noexcept {
            return Result(Storage::err(err), State::Err);
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

            struct OkTag {};
            struct ErrTag {};

            constexpr explicit Storage(OkTag, T val) noexcept: value(val) {}
            constexpr explicit Storage(ErrTag, E err) noexcept: error(err) {}

            constexpr static Storage ok(T val) noexcept {
                return Storage(OkTag(), val);
            }

            constexpr static Storage err(E err) noexcept {
                return Storage(ErrTag(), err);
            }
        };

        enum class State {
            Ok,
            Err,
        };

        Storage storage;
        State state;

        constexpr explicit Result(Storage storage, State state) noexcept
            : storage(storage), state(state) {}
    };
} // namespace freestd::core

#endif // FREESTD_CORE_RESULT_HPP
