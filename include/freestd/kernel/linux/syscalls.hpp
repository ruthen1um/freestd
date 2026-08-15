#ifndef FREESTD_KERNEL_LINUX_SYSCALLS_HPP
#define FREESTD_KERNEL_LINUX_SYSCALLS_HPP

#include <freestd/core/platform.hpp>

#if !(defined(FREESTD_ARCH_X86_64) && defined(FREESTD_OS_LINUX))
#error "Header only available for linux on x86-64 arch"
#endif

#include <freestd/kernel/linux/types.hpp>

namespace freestd::kernel::linux {
    extern "C" ssize_t __freestd_asm_linux_syscall_read(unsigned int fd, char* buf, size_t count) noexcept;

    extern "C" ssize_t
    __freestd_asm_linux_syscall_write(unsigned int fd, const char* buf, size_t count) noexcept;

    extern "C" ssize_t
    __freestd_asm_linux_syscall_open(const char* filename, int flags, umode_t mode) noexcept;

    extern "C" ssize_t __freestd_asm_linux_syscall_close(unsigned int fd) noexcept;

    extern "C" [[noreturn]] ssize_t __freestd_asm_linux_syscall_exit(int error_code) noexcept;

    inline ssize_t read(unsigned int fd, char* buf, size_t count) noexcept {
        return __freestd_asm_linux_syscall_read(fd, buf, count);
    }
    inline ssize_t write(unsigned int fd, const char* buf, size_t count) noexcept {
        return __freestd_asm_linux_syscall_write(fd, buf, count);
    }
    inline ssize_t open(const char* filename, int flags, umode_t mode) noexcept {
        return __freestd_asm_linux_syscall_open(filename, flags, mode);
    }
    inline ssize_t close(unsigned int fd) noexcept {
        return __freestd_asm_linux_syscall_close(fd);
    }
    [[noreturn]] inline ssize_t exit(int error_code) noexcept {
        __freestd_asm_linux_syscall_exit(error_code);
    }
} // namespace freestd::kernel::linux

#endif // FREESTD_KERNEL_LINUX_SYSCALLS_HPP
