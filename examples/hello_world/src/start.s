    .section .text

/* simple entrypoint which just calls exit syscall with return value from main() */
    .global _start
_start:
    call main
    mov %rax, %rdi
    mov $60, %rax
    syscall
