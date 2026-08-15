#ifndef FREESTD_CORE_TRAITS_HPP
#define FREESTD_CORE_TRAITS_HPP

namespace freestd::core {

template <typename T>
struct IsConst {
    static constexpr bool value = false;
};

template <typename T>
struct IsConst<const T> {
    static constexpr bool value = true;
};

template <typename T>
inline constexpr bool IsConstV = IsConst<T>::value;

template <typename T>
struct IsUnsigned {
    static constexpr bool value = T(-1) > T(0);
};

template<typename T>
inline constexpr bool IsUnsignedV = IsUnsigned<T>::value;

} // namespace freestd::core

#endif // FREESTD_CORE_TRAITS_HPP
