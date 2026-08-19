#ifndef FREESTD_CORE_REF_HPP
#define FREESTD_CORE_REF_HPP

namespace freestd::core {
    template <typename T>
    class Ref {
    public:
        constexpr explicit Ref(T& value) noexcept
            : ptr(&value) {}

        // Copying Ref does not change ownership
        constexpr Ref(const Ref<T>& other) noexcept = default;
        constexpr Ref& operator=(const Ref<T>& other) noexcept = default;

        Ref(Ref<T>&& other) = delete;
        Ref& operator=(Ref<T>&& other) = delete;

        [[nodiscard]] constexpr auto& get(this auto&& self) noexcept {
            return *self.ptr;
        }

    private:
        T* const ptr;
    };
} // namespace freestd::core

#endif // FREESTD_CORE_REF_HPP
