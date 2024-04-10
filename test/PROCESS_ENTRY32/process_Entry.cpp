#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

int main()
{
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    int processCount = 0;
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(pe);
        if (Process32First(hSnap, &pe))
        {
            do
            {
                printf("Process ID: %d, Threads: %d, Executable: %s\\r\n", pe.th32ProcessID, pe.cntThreads, pe.szExeFile);
                processCount++;
            } while (Process32Next(hSnap, &pe));
        }
        CloseHandle(hSnap);
    }
    std::cout <<"进程总数"<< processCount<<std::endl;
    system("pause");
}
