#include"opcode.h"


void op_add(uint16_t instr) {
    /* destination register (DR) */
    uint16_t r0 = (instr >> 9) & 0x7;
    /* first operand (SR1) */
    uint16_t r1 = (instr >> 6) & 0x7;
    /* whether we are in immediate mode */
    uint16_t imm_flag = (instr >> 5) & 0x1;

    if (imm_flag)
    {
        uint16_t imm5 = sign_extend(instr & 0x1F, 5);
        reg[r0] = reg[r1] + imm5;
    }
    else
    {
        uint16_t r2 = instr & 0x7;
        reg[r0] = reg[r1] + reg[r2];
    }

    update_flags(r0);
}

void op_and(uint16_t instr) {
    uint16_t r0 = (instr >> 9) & 0x7;
    uint16_t r1 = (instr >> 6) & 0x7;
    uint16_t imm_flag = (instr >> 5) & 0x1;

    if (imm_flag)
    {
        uint16_t imm5 = sign_extend(instr & 0x1F, 5);
        reg[r0] = reg[r1] & imm5;
    }
    else
    {
        uint16_t r2 = instr & 0x7;
        reg[r0] = reg[r1] & reg[r2];
    }
    update_flags(r0);
}

void op_not(uint16_t instr) {
    uint16_t r0 = (instr >> 9) & 0x7;
    uint16_t r1 = (instr >> 6) & 0x7;

    reg[r0] = ~reg[r1];
    update_flags(r0);
}


//��ȡ�����ź�wasd
void trap_getc() {
    reg[R_R0] = (uint16_t)getchar();
}


void trap_out() {
    putc((char)reg[R_R0], stdout);
    fflush(stdout);
}

//���Unicode���͵��ַ���
void trap_puts() {
    uint16_t* c = memory + reg[R_R0];
    while (*c)
    {
        putc((char)*c, stdout);
        ++c;
    }
    fflush(stdout);
}

// ���y/n? ���û��ܹ������Լ���������,����ʾ���������

void trap_in() {
    printf("������һ���ַ�: ");
    //�����ַ������ַ����������������
    char c = getchar();
    putc(c, stdout);
    //�޸ģ��������������������Ĵ���
    fflush(stdout);
    reg[R_R0] = (uint16_t)c;
}


void trap_putsp() {
    uint16_t* c = memory + reg[R_R0];
    while (*c)
    {
        char char1 = (*c) & 0xFF;
        putc(char1, stdout);
        char char2 = (*c) >> 8;
        if (char2) { 
            putc(char2, stdout); 
        }
        ++c;
    }
    fflush(stdout);
}

void trap_halt() {
    puts("HALT");
    fflush(stdout);
}