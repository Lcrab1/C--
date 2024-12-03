#include <windows.h>
#include <iostream>

// 线程函数
DWORD WINAPI ThreadProc(LPVOID lpParam)
{
    std::cout << "Thread is running..." << std::endl;
    Sleep(2000); // 模拟一些工作
    std::cout << "Thread is exiting..." << std::endl;
    return 42; // 线程退出代码
}

int main()
{
    // 创建线程
    HANDLE hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    if (hThread == NULL)
    {
        std::cerr << "CreateThread failed: " << GetLastError() << std::endl;
        return 1;
    }

    // 等待线程终止
    WaitForSingleObject(hThread, INFINITE);

    // 获取线程的退出代码
    DWORD exitCode;
    if (GetExitCodeThread(hThread, &exitCode))
    {
        std::cout << "Thread exited with code: " << exitCode << std::endl;
    }
    else
    {
        std::cerr << "GetExitCodeThread failed: " << GetLastError() << std::endl;
    }

    // 关闭线程句柄
    CloseHandle(hThread);
    system("pause");
    return 0;
}