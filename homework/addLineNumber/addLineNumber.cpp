#include <fstream>
#include <string>

int main()
{
    std::ifstream inputFile("input.txt");   // 打开已存在的文件
    std::ofstream outputFile("output.txt"); // 创建一个新的文件
    std::string line;
    int lineNumber = 1;

    while (std::getline(inputFile, line))
    {                                                    // 读取每一行
        outputFile << lineNumber << " " << line << "\n"; // 在每一行前加上行号，并写入新的文件
        lineNumber++;                                    // 行号递增
    }

    inputFile.close();  // 关闭输入文件
    outputFile.close(); // 关闭输出文件

    return 0;
}