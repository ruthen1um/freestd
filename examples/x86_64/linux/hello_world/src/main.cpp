import freestd.kernel.linux;

constexpr const unsigned int STDOUT_FD = 1;
constexpr const int EXIT_SUCCESS = 0;

extern "C" int main() noexcept {
    using namespace freestd::kernel::linux;
    write(STDOUT_FD, "Hello, world\n", 13);
    return EXIT_SUCCESS;
}
