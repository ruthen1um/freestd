#ifndef FREESTD_CORE_PLATFORM_HPP
#define FREESTD_CORE_PLATFORM_HPP

#if defined(__x86_64__)
#define FREESTD_ARCH_X86_64 1
#endif

#if defined(__linux__)
#define FREESTD_OS_LINUX 1
#endif

#if defined(FREESTD_OS_LINUX)
#define FREESTD_CURRENT_OS_NAME "linux"
#endif

#if defined(FREESTD_ARCH_X86_64)
#define FREESTD_CURRENT_ARCH_NAME "x86-64"
#endif

#endif // FREESTD_CORE_PLATFORM_HPP
