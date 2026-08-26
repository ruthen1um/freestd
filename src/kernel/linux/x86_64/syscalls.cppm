export module freestd.kernel:syscalls;

import :types;

export namespace freestd::kernel {
    ssize_t read(unsigned int fd, char* buf, size_t count) noexcept;
    ssize_t write(unsigned int fd, const char* buf, size_t count) noexcept;
    ssize_t open(const char* filename, int flags, umode_t mode) noexcept;
    ssize_t close(unsigned int fd) noexcept;
    [[noreturn]] ssize_t exit(int error_code) noexcept;
} // namespace freestd::kernel
