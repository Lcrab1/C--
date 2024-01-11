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
    FL_POS = 1 << 0, /* ���� */
    FL_ZRO = 1 << 1, /* �� */
    FL_NEG = 1 << 2, /* ���� */
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

//�ڴ�ӳ��Ĵ���
enum
{
    MR_KBSR = 0xFE00, //����״̬�Ĵ��� �Ƿ��а���������
    MR_KBDR = 0xFE02  //�������ݼĴ��� �����µľ��������Ϣ
};

enum
{
    //�������������ַ������ڿ���̨����
    TRAP_GETC = 0x20,  
    //���һ���ַ�
    TRAP_OUT = 0x21,   
    //���Unicode�ַ�
    TRAP_PUTS = 0x22,
    //�������������ַ����ڿ���̨�ϻ���
    TRAP_IN = 0x23,    
    //���ASCII�ַ�
    TRAP_PUTSP = 0x24, 
    //ֹͣ���г���
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

//�ȴ�������Ӧ 1000ms
uint16_t check_key();

void mem_write(uint16_t address, uint16_t val);

uint16_t mem_read(uint16_t address);

void disable_input_buffering();

void restore_input_buffering();

void handle_interrupt(int signal);