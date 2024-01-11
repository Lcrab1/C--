#include"lc3.h"
#include"opcode.h"
#include"test.h"


uint16_t memory[UINT16_MAX];

uint16_t reg[R_COUNT];

//句柄初始化（伪句柄） 
HANDLE hStdin = INVALID_HANDLE_VALUE;

//存储控制台新模式和旧模式
DWORD fdwMode, fdwOldMode;

uint16_t sign_extend(uint16_t x, int bit_count)
{
    if ((x >> (bit_count - 1)) & 1) {
        x |= (0xFFFF << bit_count);
    }
    return x;
}

uint16_t swap16(uint16_t x)
{
    return (x << 8) | (x >> 8);
}

void update_flags(uint16_t r)
{
    if (reg[r] == 0)
    {
        reg[R_COND] = FL_ZRO;
    }
    else if (reg[r] >> 15) 
    {
        reg[R_COND] = FL_NEG;
    }
    else
    {
        reg[R_COND] = FL_POS;
    }
}

void read_image_file(FILE* file)
{
   
    uint16_t origin;
    fread(&origin, sizeof(origin), 1, file); 
    origin = swap16(origin);

    uint16_t max_read = UINT16_MAX - origin;
    uint16_t* p = memory + origin;
    size_t read = fread(p, sizeof(uint16_t), max_read, file);

    while (read-- > 0)
    {
        *p = swap16(*p);
        ++p;
    }
}

int read_image(const char* image_path)
{
    //rb 二进制打开文件
    FILE* file = fopen(image_path, "rb");       
    if (!file) {
        return 0;
    };
    //调用read_image_file
    read_image_file(file);
    //关闭文件
    fclose(file);
    return 1;
}

uint16_t check_key()
{
    return WaitForSingleObject(hStdin, 1000) == WAIT_OBJECT_0 && _kbhit();
}

void mem_write(uint16_t address, uint16_t val)
{
    memory[address] = val;
}

uint16_t mem_read(uint16_t address)
{
    if (address == MR_KBSR)
    {
        //检查键盘是否有输入，键盘作为外部时间来触发操作,实现对键盘输入的及时响应
        if (check_key())
        {
            memory[MR_KBSR] = (1 << 15);
            memory[MR_KBDR] = getchar();
        }
        else
        {
            memory[MR_KBSR] = 0;
        }
    }
    return memory[address];
}

//禁用输入缓冲
void disable_input_buffering()
{
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hStdin, &fdwOldMode);
    fdwMode = fdwOldMode 
    ^ ENABLE_ECHO_INPUT 
    ^ ENABLE_LINE_INPUT;  
    SetConsoleMode(hStdin, fdwMode);    
    FlushConsoleInputBuffer(hStdin);  
}

//恢复控制台初始状态
void restore_input_buffering()
{
    //printf("hello!\r\\n");
    SetConsoleMode(hStdin, fdwOldMode);
    //hStdin是控制台的输入句柄
    //fdwOldMode是在更改控制台模式之前保存的原始模式。
}

//中断处理
void handle_interrupt(int signal)
{
    restore_input_buffering();


    printf("\n");
    //-2 表示接收到中断信号
    exit(-2);
}
