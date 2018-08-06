#ifndef PS4
	#include <stdio.h>
#endif

#include "platform.h"

#include "registers.h"
#include "memory.h"
#include "cpu.h"
#include "interrupts.h"

#include "debug.h"

unsigned char realtimeDebugEnable = 0;

void realtimeDebug(void) {
	unsigned char instruction = readByte(registers.pc);
	// unsigned short operand = 0;

	printf("PC: %04X, AF: %04X, BC: %04X, DE: %04X, HL: %04X, SP: %04X, (SP16): %04X, (HL16): %04X - %s\n",
			registers.pc,
			registers.af,
			registers.bc,
			registers.de,
			registers.hl,
			registers.sp,
			readShort(registers.sp),
			readShort(registers.hl),
			instructions[instruction].disassembly
	);
}

void printRegisters() {
	printf("A: 0x%02x\n", registers.a);
	printf("F: 0x%02x\n", registers.f);
	printf("B: 0x%02x\n", registers.b);
	printf("C: 0x%02x\n", registers.c);
	printf("D: 0x%02x\n", registers.d);
	printf("E: 0x%02x\n", registers.e);
	printf("H: 0x%02x\n", registers.h);
	printf("L: 0x%02x\n", registers.l);
	printf("SP: 0x%04x\n", registers.sp);
	printf("PC: 0x%04x\n", registers.pc);
	printf("IME: 0x%02x\n", interrupt.master);
	printf("IE: 0x%02x\n", interrupt.enable);
	printf("IF: 0x%02x\n", interrupt.flags);
}
