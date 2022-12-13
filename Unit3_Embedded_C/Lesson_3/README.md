# Toggle LED on STM32F103C6

The linker script and startup code is implemented from scratch.

As Cortex-M3 can intialize the Stack Pointer (SP) with the first 4 bytes, so we can write the startup in C.
<br>
The startup code is implemented in two approaches:
- [startup.s](STM32F103C6_startup.s/startup.s) with Assembly code
- [startup.c](STM32F103C6_startup.c/startup.c) with C code

Tools:
- ARM Toolchain
- Make
- Protues