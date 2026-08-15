#ifndef FREESTD_CORE_REF_HPP
#define FREESTD_CORE_REF_HPP

namespace freestd::core {
    template <typename T>
    class Ref {
    public:
        constexpr explicit Ref(T& value) noexcept
            : ptr{&value} {}

        constexpr Ref(const Ref<T>& other) noexcept = default;
        constexpr Ref& operator=(const Ref<T>& other) noexcept = default;

        // TODO: figure out what to do with move constructor and move assignment operator
        constexpr Ref(Ref<T>&& other) noexcept = delete;
        constexpr Ref& operator=(Ref<T>&& other) noexcept = delete;

        [[nodiscard]] constexpr auto& get(this auto&& self) noexcept {
            return *self.ptr;
        }

    private:
        T* const ptr;
    };
} // namespace freestd::core

#endif // FREESTD_CORE_REF_HPP
