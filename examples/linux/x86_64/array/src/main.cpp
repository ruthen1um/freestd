import freestd.collections;
import freestd.core;
import freestd.kernel;

constexpr const unsigned int STDOUT_FD = 1;
constexpr const int EXIT_SUCCESS = 0;

extern "C" int main() noexcept {
    // check program output with xxd

    using namespace freestd::collections;
    using namespace freestd::core;
    using namespace freestd::kernel;

    constexpr auto array = Array<i8, u64, 10>();
    for (auto i = u64(0); i < array.get_size(); ++i) {
        write(STDOUT_FD, reinterpret_cast<const char*>(&i), sizeof(i));
    }

    return EXIT_SUCCESS;
}
