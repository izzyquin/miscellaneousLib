 .syntax unified
    .cpu cortex-m3
    .thumb

    .section .isr_vector, "a", %progbits
    .word _estack          /* initial stack pointer */
    .word Reset_Handler    /* reset vector */

    .section .text.Reset_Handler
    .thumb_func
Reset_Handler:
    bl main
    b .
    
    .section .stack
    .space 1024
_estack:
