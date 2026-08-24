module freestd.kernel.linux;

namespace freestd::kernel::linux {
    extern "C" {
        ssize_t
        __freestd_asm_linux_x86_64_syscall_read(unsigned int fd, char* buf, size_t count) noexcept;

        ssize_t __freestd_asm_linux_x86_64_syscall_write(
            unsigned int fd, const char* buf, size_t count
        ) noexcept;

        ssize_t __freestd_asm_linux_x86_64_syscall_open(
            const char* filename, int flags, umode_t mode
        ) noexcept;

        ssize_t __freestd_asm_linux_x86_64_syscall_close(unsigned int fd) noexcept;

        [[noreturn]] ssize_t __freestd_asm_linux_x86_64_syscall_exit(int error_code) noexcept;
    }

    ssize_t read(unsigned int fd, char* buf, size_t count) noexcept {
        return __freestd_asm_linux_x86_64_syscall_read(fd, buf, count);
    }
    ssize_t write(unsigned int fd, const char* buf, size_t count) noexcept {
        return __freestd_asm_linux_x86_64_syscall_write(fd, buf, count);
    }
    ssize_t open(const char* filename, int flags, umode_t mode) noexcept {
        return __freestd_asm_linux_x86_64_syscall_open(filename, flags, mode);
    }
    ssize_t close(unsigned int fd) noexcept {
        return __freestd_asm_linux_x86_64_syscall_close(fd);
    }
    [[noreturn]] ssize_t exit(int error_code) noexcept {
        __freestd_asm_linux_x86_64_syscall_exit(error_code);
    }
} // namespace freestd::kernel::linux
