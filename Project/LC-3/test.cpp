#include"test.h"
//测试opcode 

//1.OP_ADD
void test_unit01() {

	reg[1] = 1;
	reg[0] = 3;
	cout << reg[1] << endl;
	cout << reg[0] << endl;
	uint16_t instr = 0b0001010001000000;
	op_add(instr);
	cout << reg[2] << endl;

	//立即数 +8
	instr = 0b0001010001101000;
	reg[1] = 1;
	cout << reg[1] << endl;
	op_add(instr);
	cout << reg[2] << endl;
}

//2.OP_AND
void test_unit02() {
	reg[1] = 0b0110;
	reg[0] = 0b0100;
	//与运算结果应该是0100 4
	uint16_t instr = 0b0101010001000000;
	op_and(instr);
	cout << reg[2] << endl;;
	//立即数 
	instr = 0b0101010001000100;
	cout << reg[2] << endl;
}
//3.OP_NOT
void test_unit03() {
	//reg[0] = 0b0000000000000000;
	//reg[0] = 0b1111111111111111;
	reg[0] = 0b1001111010011100;
			//0110 0001 0110 0011 0x6163	24931
	//非运算	应变为1011 11
	uint16_t instr = 0b1001001000111111;
	op_not(instr);
	cout << reg[1] << endl;;
}

//4. OP_TRAP
void test_unit04() {
	//在ASCII码中对应字符 2 3
	reg[R_R0] = 0x3233;
	mem_write(reg[R_R0], 0x3233);
	trap_putsp();
}



