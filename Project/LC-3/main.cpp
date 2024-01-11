#include"lc3.h"
#include"opcode.h"
#include"test.h"

int main(int argc, const char* argv[])  //argc 本身程序+外部传入的参数个数  argv表示本身程序的路径和 外部传入的参数的路径
{
    //test_unit04();
    //if (argc < 2)
    //{
    //    printf("lc3 [image-file1] ...\n");
    //    exit(2);
    //}

    //for (int j = 1; j < argc; ++j)  //从1开始 也就是从外部传入的路径开始
    //{
    //    if (!read_image(argv[j]))   //读外部文件
    //    {
    //        printf("failed to load image: %s\n", argv[j]);
    //        exit(1);
    //    }
    //}
    read_image("rogue.obj");

    //退出游戏
    signal(SIGINT, handle_interrupt);//ctrl +c

    disable_input_buffering();


    //测试禁用行输入 输入回显是否成功
    //char a;
    //cin >> a;
    //cout << a << endl;

    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;
    int running = 1;

 /*   MessageBox(NULL, 0, 0, 0);*/
    while (running)
    {
        /* FETCH */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op)
        {
        case OP_ADD:
        {
            op_add(instr);
        }
        break;
        case OP_AND:
        {
            op_and(instr);
        }
        break;

        case OP_NOT:
        {
            op_not(instr);
        }

        break;
        case OP_BR:
            /* BR */
        {
            uint16_t pc_offset = sign_extend((instr) & 0x1ff, 9);
            uint16_t cond_flag = (instr >> 9) & 0x7;
            if (cond_flag & reg[R_COND])
            {
                reg[R_PC] += pc_offset;
            }
        }

        break;
        case OP_JMP:
            /* JMP */
        {
            /* Also handles RET */
            uint16_t r1 = (instr >> 6) & 0x7;
            reg[R_PC] = reg[r1];    
        }

        break;
        case OP_JSR:
            /* JSR */
        {
            uint16_t r1 = (instr >> 6) & 0x7;
            uint16_t long_pc_offset = sign_extend(instr & 0x7ff, 11);
            uint16_t long_flag = (instr >> 11) & 1;

            reg[R_R7] = reg[R_PC];
            if (long_flag)
            {
                reg[R_PC] += long_pc_offset;  
            }
            else
            {
                reg[R_PC] = reg[r1]; /* JSRR */
            }
            break;
        }

        break;
        case OP_LD:
            /* LD */
        {
            uint16_t r0 = (instr >> 9) & 0x7;
            uint16_t pc_offset = sign_extend(instr & 0x1ff, 9);
            reg[r0] = mem_read(reg[R_PC] + pc_offset);
            update_flags(r0);
        }

        break;
        case OP_LDI:
        {
            uint16_t r0 = (instr >> 9) & 0x7;
            uint16_t pc_offset = sign_extend(instr & 0x1ff, 9);
            reg[r0] = mem_read(mem_read(reg[R_PC] + pc_offset));
            update_flags(r0);
        }

        break;
        case OP_LDR:
            /* LDR */
        {
            uint16_t r0 = (instr >> 9) & 0x7;
            uint16_t r1 = (instr >> 6) & 0x7;
            uint16_t offset = sign_extend(instr & 0x3F, 6);
            reg[r0] = mem_read(reg[r1] + offset);
            update_flags(r0);
        }

        break;
        case OP_LEA:
        {
            uint16_t r0 = (instr >> 9) & 0x7;
            uint16_t pc_offset = sign_extend(instr & 0x1ff, 9);
            reg[r0] = reg[R_PC] + pc_offset;
            update_flags(r0);
        }

        break;
        case OP_ST:
        {
            uint16_t r0 = (instr >> 9) & 0x7;
            uint16_t pc_offset = sign_extend(instr & 0x1ff, 9);
            mem_write(reg[R_PC] + pc_offset, reg[r0]);
        }

        break;
        case OP_STI:
        {
            uint16_t r0 = (instr >> 9) & 0x7;
            uint16_t pc_offset = sign_extend(instr & 0x1ff, 9);
            mem_write(mem_read(reg[R_PC] + pc_offset), reg[r0]);
        }

        break;
        case OP_STR:
        {
            uint16_t r0 = (instr >> 9) & 0x7;
            uint16_t r1 = (instr >> 6) & 0x7;
            uint16_t offset = sign_extend(instr & 0x3F, 6);
            mem_write(reg[r1] + offset, reg[r0]);
        }

        break;
        case OP_TRAP:
            switch (instr & 0xFF)
            {
            case TRAP_GETC:
                trap_getc();
                break;
            case TRAP_OUT:
                trap_out();
                break;
            case TRAP_PUTS:
                trap_puts();
                break;
            case TRAP_IN:
                trap_in();
                break;
            case TRAP_PUTSP:
                trap_putsp();
                break;
            case TRAP_HALT:
            {
                trap_halt();
                running = 0;
            }
                break;
            }

            break;
        case OP_RES:
        case OP_RTI:
        default:
            abort();

            break;
        }
    }
    cout << reg[R_R1] << endl;
    restore_input_buffering();

}

