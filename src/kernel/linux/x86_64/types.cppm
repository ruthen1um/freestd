export module freestd.kernel:types;

export namespace freestd::kernel {
    // ssize_t and size_t are from
    // https://github.com/torvalds/linux/blob/master/include/uapi/asm-generic/posix_types.h
    using ssize_t = long;
    using size_t = unsigned long;

    // Other types are from https://github.com/torvalds/linux/blob/master/include/linux/types.h
    using umode_t = unsigned short;
} // namespace freestd::kernel
