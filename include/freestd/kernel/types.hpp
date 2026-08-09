#ifndef FREESTD_KERNEL_TYPES_HPP
#define FREESTD_KERNEL_TYPES_HPP

#include "freestd/core/platform.hpp"

namespace freestd::kernel {
#if defined(FREESTD_ARCH_X86_64) && defined(FREESTD_OS_LINUX)
    using size_t = unsigned long;
    using umode_t = unsigned short;
#endif
} // namespace freestd::kernel

#endif // FREESTD_KERNEL_TYPES_HPP
