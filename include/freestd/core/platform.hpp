#ifndef FREESTD_CORE_PLATFORM_HPP
#define FREESTD_CORE_PLATFORM_HPP

#if defined(__x86_64__)
    #define FREESTD_ARCH_X86_64 1
#else
    #error "Unsupported architecture for freestd (only x86-64 is supported)"
#endif

#if defined(__linux__)
    #define FREESTD_OS_LINUX 1
#else
    #error "Unsupported OS for freestd (only Linux is supported)"
#endif

#endif // FREESTD_CORE_PLATFORM_HPP
