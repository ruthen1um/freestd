#ifndef FREESTD_CORE_TRAITS_HPP
#define FREESTD_CORE_TRAITS_HPP

namespace freestd::core {
    template <typename T>
    struct IsConst {
        constexpr static bool value = false;
    };

    template <typename T>
    struct IsConst<const T> {
        constexpr static bool value = true;
    };

    template <typename T>
    constexpr inline bool IsConstV = IsConst<T>::value;

    template <typename T>
    struct IsUnsigned {
        constexpr static bool value = T(-1) > T(0);
    };

    template <typename T>
    constexpr inline bool IsUnsignedV = IsUnsigned<T>::value;

    template <typename T, typename U>
    struct IsSame {
        constexpr static bool value = false;
    };

    template <typename T>
    struct IsSame<T, T> {
        constexpr static bool value = true;
    };

    template <typename T, typename U>
    constexpr inline bool IsSameV = IsSame<T, U>::value;
} // namespace freestd::core

#endif // FREESTD_CORE_TRAITS_HPP
