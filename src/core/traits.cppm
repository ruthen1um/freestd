export module freestd.core:traits;

export namespace freestd::core {
    template <typename T>
    struct IsConst {
        constexpr static auto value = false;
    };

    template <typename T>
    struct IsConst<const T> {
        constexpr static auto value = true;
    };

    template <typename T>
    constexpr inline auto IsConstV = IsConst<T>::value;

    template <typename T>
    struct IsUnsigned {
        constexpr static auto value = T(-1) > T(0);
    };

    template <typename T>
    constexpr inline auto IsUnsignedV = IsUnsigned<T>::value;

    template <typename T, typename U>
    struct IsSame {
        constexpr static auto value = false;
    };

    template <typename T>
    struct IsSame<T, T> {
        constexpr static auto value = true;
    };

    template <typename T, typename U>
    constexpr inline auto IsSameV = IsSame<T, U>::value;
} // namespace freestd::core
