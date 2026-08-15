#ifndef FREESTD_KERNEL_LINUX_TYPES_HPP
#define FREESTD_KERNEL_LINUX_TYPES_HPP

#include <freestd/core/platform.hpp>

#if !(defined(FREESTD_ARCH_X86_64) && defined(FREESTD_OS_LINUX))
#error "Header only available for linux on x86-64 arch"
#endif

namespace freestd::kernel::linux {
    // ssize_t and size_t are from
    // https://github.com/torvalds/linux/blob/master/include/uapi/asm-generic/posix_types.h
    using ssize_t = long;
    using size_t = unsigned long;

    // Other types are from https://github.com/torvalds/linux/blob/master/include/linux/types.h
    using umode_t = unsigned short;
} // namespace freestd::kernel::linux

#endif // FREESTD_KERNEL_LINUX_TYPES_HPP
