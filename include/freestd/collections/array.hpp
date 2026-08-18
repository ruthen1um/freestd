#ifndef FREESTD_COLLECTIONS_ARRAY_HPP
#define FREESTD_COLLECTIONS_ARRAY_HPP

#include <freestd/core/ref.hpp>
#include <freestd/core/result.hpp>
#include <freestd/core/traits.hpp>

namespace freestd::collections {
    enum class ArrayError {
        OutOfBoundsAccess,
    };

    template <typename T, typename Size, Size N>
    class Array {
        static_assert(core::IsUnsignedV<Size>, "Size must be an unsigned type");
        static_assert(N > 0, "N must be positive integer");

    public:
        using ValueType = T;
        using SizeType = Size;
        using ErrorType = ArrayError;

        constexpr explicit Array() noexcept = default;

        constexpr Array(const Array<T, Size, N>& other) noexcept = default;
        constexpr Array& operator=(const Array<T, Size, N>& other) noexcept = default;

        // Move operations are deleted to prevent confusion. Array type has its elements
        // stored in itself so move operations essentially do the same thing as copy operations
        Array(Array<T, Size, N>&& other) = delete;
        Array& operator=(Array<T, Size, N>&& other) = delete;

        [[nodiscard]] constexpr core::Result<core::Ref<ValueType>, ErrorType>
        at(this auto&& self, SizeType idx) noexcept {
            using namespace core;
            if (idx >= self.get_size()) {
                return Result<Ref<ValueType>, ErrorType>::err(ArrayError::OutOfBoundsAccess);
            }
            return Result<Ref<ValueType>, ErrorType>::ok(Ref(self.elements[idx]));
        }

        [[nodiscard]] constexpr auto& operator[](this auto&& self, SizeType idx) noexcept {
            return self.elements[idx];
        }

        [[nodiscard]] constexpr auto get_raw(this auto&& self) noexcept {
            return self.elements;
        }

        [[nodiscard]] constexpr SizeType get_size(this const auto&) noexcept {
            return N;
        }

    private:
        T elements[N];
    };
} // namespace freestd::collections

#endif // FREESTD_COLLECTIONS_ARRAY_HPP
