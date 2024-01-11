#pragma once
/* lc3-win.c */
/* Windows Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include<iostream>
/* _WIN32 */
#include <Windows.h>
#include <conio.h> // _kbhit
#include"opcode.h"
#pragma warning(disable : 4996)

/* Registers */
enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, 
    R_COND,
    R_COUNT
};



enum
{
    FL_POS = 1 << 0, /* 正数 */
    FL_ZRO = 1 << 1, /* 零 */
    FL_NEG = 1 << 2, /* 负数 */
};


enum
{
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

//内存映射寄存器
enum
{
    MR_KBSR = 0xFE00, //键盘状态寄存器 是否有按键被按下
    MR_KBDR = 0xFE02  //键盘数据寄存器 被按下的具体键的信息
};

enum
{
    //捕获键盘输入的字符，不在控制台回显
    TRAP_GETC = 0x20,  
    //输出一个字符
    TRAP_OUT = 0x21,   
    //输出Unicode字符
    TRAP_PUTS = 0x22,
    //捕获键盘输入的字符并在控制台上回显
    TRAP_IN = 0x23,    
    //输出ASCII字符
    TRAP_PUTSP = 0x24, 
    //停止运行程序
    TRAP_HALT = 0x25   
};





extern uint16_t memory[UINT16_MAX];

extern uint16_t reg[R_COUNT];


extern DWORD fdwMode, fdwOldMode;


uint16_t sign_extend(uint16_t x, int bit_count);

uint16_t swap16(uint16_t x);

void update_flags(uint16_t r);

void read_image_file(FILE* file);

int read_image(const char* image_path);

//等待键盘响应 1000ms
uint16_t check_key();

void mem_write(uint16_t address, uint16_t val);

uint16_t mem_read(uint16_t address);

void disable_input_buffering();

void restore_input_buffering();

void handle_interrupt(int signal);