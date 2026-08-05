# 05 — Embedded C

C for microcontrollers: no operating system, no `malloc`, tiny RAM, and code
that talks straight to hardware registers.

Most of this can be learned on your laptop first — bit manipulation, `volatile`,
fixed-width types and simulated registers all run fine as normal programs. Move
to real hardware (STM32, AVR, ESP32) once the fundamentals are solid.

## Folders

| Folder | What goes in it |
| --- | --- |
| `bit-manipulation/` | Set/clear/toggle/test a bit, masks, shifts, bitfields, endianness |
| `volatile-const-static/` | Why `volatile` exists, `const volatile`, `static` for internal linkage and persistent locals |
| `fixed-width-types/` | `stdint.h` (`uint8_t`, `int32_t`…), sizes, overflow, integer promotion traps |
| `memory-mapped-io/` | Registers as pointers to fixed addresses, `#define REG (*(volatile uint32_t*)0x40021000)` |
| `interrupts-and-isr/` | Interrupt vectors, writing an ISR, keeping ISRs short, shared state with `volatile` |
| `communication-protocols/` | UART, SPI, I2C — the frame formats and how to drive them |
| `rtos-basics/` | Tasks, scheduling, priorities, queues and semaphores (FreeRTOS concepts) |

## Rules of the embedded world

- No dynamic allocation. Static buffers with known sizes.
- Anything a hardware register or ISR touches is `volatile`.
- Know your integer widths — `int` is not always 32 bits here.
- Every ISR should do the minimum and get out.

## Build

Laptop-runnable exercises use the root Makefile:

```bash
make FILE=05-embedded-c/bit-manipulation/set_clear_bit.c run
```

Real hardware needs a cross toolchain (`arm-none-eabi-gcc`) and a per-project
Makefile — keep those inside the project folder.
