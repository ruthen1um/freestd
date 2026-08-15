    .section .text

    .global __freestd_asm_linux_syscall_read
__freestd_asm_linux_syscall_read:
    mov $0, %rax
    syscall
    ret

    .global __freestd_asm_linux_syscall_write
__freestd_asm_linux_syscall_write:
    mov $1, %rax
    syscall
    ret

    .global __freestd_asm_linux_syscall_open
__freestd_asm_linux_syscall_open:
    mov $2, %rax
    syscall
    ret

    .global __freestd_asm_linux_syscall_close
__freestd_asm_linux_syscall_close:
    mov $3, %rax
    syscall
    ret

    .global __freestd_asm_linux_syscall_exit
__freestd_asm_linux_syscall_exit:
    mov $60, %rax
    syscall
    ret
