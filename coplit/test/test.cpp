#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void test()
{

    string fname = "test.csv";
    //以读入方式打开文件
    ifstream csv_data(fname, ios::in);

    if (!csv_data.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    else
    {
        string line;

        vector<string> words; //声明一个字符串向量
        string word;
        // ------------读取数据-----------------
        // 读取标题行
        getline(csv_data, line);

        istringstream sin;
        // 按行读取数据
        while (getline(csv_data, line))
        {
            // 清空vector及字符串流,只存当前行的数据
            words.clear();
            sin.clear();

            sin.str(line);
            //将字符串流sin中的字符读到字符串数组words中，以逗号为分隔符
            while (getline(sin, word, ','))
            {
                cout << word << "   ";
                words.push_back(word); //将每一格中的数据逐个push
            }
            cout << endl;
        }
        csv_data.close();
    }
}

int main()
{
    test();
    system("pause");
    return 0;
}