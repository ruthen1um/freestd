#include <freestd/kernel/syscalls.hpp>

constexpr const unsigned int STDOUT_FD = 1;
constexpr const int EXIT_SUCCESS = 0;

extern "C" [[noreturn]] void _start() noexcept {
    freestd::kernel::write(STDOUT_FD, "Hello, world\n", 13);
    freestd::kernel::exit(EXIT_SUCCESS);
}
