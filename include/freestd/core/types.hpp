#ifndef FREESTD_CORE_TYPES_HPP
#define FREESTD_CORE_TYPES_HPP

#include "freestd/core/platform.hpp"

namespace freestd::core {
#if defined(FREESTD_ARCH_X86_64) && defined(FREESTD_OS_LINUX)
    using i8 = signed char;
    using i16 = signed short;
    using i32 = signed int;
    using i64 = signed long;

    using u8 = unsigned char;
    using u16 = unsigned short;
    using u32 = unsigned int;
    using u64 = unsigned long;

    using f32 = float;
    using f64 = double;
    using f128 = long double;
#endif
} // namespace freestd::core

#endif // FREESTD_CORE_TYPES_HPP
