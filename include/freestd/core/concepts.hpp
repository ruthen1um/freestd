#ifndef FREESTD_CORE_CONCEPTS_HPP
#define FREESTD_CORE_CONCEPTS_HPP

#include <freestd/core/traits.hpp>

namespace freestd::core {
    template <typename T, typename U>
    concept Same = IsSameV<T, U>;

    template <typename T>
    concept Collection = requires(T c) {
        typename T::ValueType;
        typename T::SizeType;
        requires core::IsUnsignedV<typename T::SizeType>;
        { c.get_size() } noexcept -> Same<typename T::SizeType>;
    };
} // namespace freestd::core

#endif // FREESTD_CORE_CONCEPTS_HPP
