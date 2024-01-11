#pragma once
#include"lc3.h"
//请把所有opcode写到此文件与opcode.cpp中

void op_add(uint16_t instr);

void op_and(uint16_t instr);

void op_not(uint16_t instr);

void trap_getc();

void trap_out();

void trap_puts();

void trap_in();

void trap_putsp();

void trap_halt();