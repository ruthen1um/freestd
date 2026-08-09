#ifndef FREESTD_KERNEL_SYSCALLS_HPP
#define FREESTD_KERNEL_SYSCALLS_HPP

#include "freestd/core/platform.hpp"
#include "freestd/kernel/types.hpp"

namespace freestd::kernel {
#if defined(FREESTD_ARCH_X86_64) && defined(FREESTD_OS_LINUX)
    extern "C" long __freestd_asm_syscall_read(unsigned int fd, char* buf, freestd::kernel::size_t count) noexcept;
    extern "C" long __freestd_asm_syscall_write(unsigned int fd, const char* buf, freestd::kernel::size_t count) noexcept;
    extern "C" long __freestd_asm_syscall_open(const char* filename, int flags, freestd::kernel::umode_t mode) noexcept;
    extern "C" long __freestd_asm_syscall_close(unsigned int fd) noexcept;
    extern "C" [[noreturn]] long __freestd_asm_syscall_exit(int error_code) noexcept;

    inline long read(unsigned int fd, char* buf, size_t count) noexcept {
        return __freestd_asm_syscall_read(fd, buf, count);
    }
    inline long write(unsigned int fd, const char* buf, size_t count) noexcept {
        return __freestd_asm_syscall_write(fd, buf, count);
    }
    inline long open(const char* filename, int flags, umode_t mode) noexcept {
        return __freestd_asm_syscall_open(filename, flags, mode);
    }
    inline long close(unsigned int fd) noexcept {
        return __freestd_asm_syscall_close(fd);
    }
    [[noreturn]] static inline long exit(int error_code) noexcept {
        __freestd_asm_syscall_exit(error_code);
    }
#endif
} // namespace freestd::kernel

#endif // FREESTD_KERNEL_SYSCALLS_HPP
