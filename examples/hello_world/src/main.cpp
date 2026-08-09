#include "freestd/kernel/syscalls.hpp"

constexpr const unsigned int STDOUT_FD = 1;

extern "C" int main() noexcept {
    freestd::kernel::write(STDOUT_FD, "Hello, world\n", 13);
    return 0;
}
