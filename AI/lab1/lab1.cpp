#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 55;

string DB[MAXN];
vector<int> R[MAXN];
bool vis[MAXN];
int cnt, num;
string ans;

void Pretreat()
{
    DB[1] = "有奶";
    DB[2] = "有毛发";
    DB[3] = "有羽毛";
    DB[4] = "会飞";
    DB[5] = "生蛋";
    DB[6] = "有爪";
    DB[7] = "有犬齿";
    DB[8] = "目盯前方";
    DB[9] = "吃肉";
    DB[10] = "有蹄";
    DB[11] = "反刍食物";
    DB[12] = "黄褐色";
    DB[13] = "黑色条纹";
    DB[14] = "黑色斑点";
    DB[15] = "长腿";
    DB[16] = "长脖子";
    DB[17] = "暗斑点";
    DB[18] = "白色";
    DB[19] = "不会飞";
    DB[20] = "黑白色";
    DB[21] = "会游泳";
    DB[22] = "善飞";
    DB[23] = "不怕风浪";
    DB[24] = "哺乳动物";
    DB[25] = "鸟";
    DB[26] = "食肉动物";
    DB[27] = "有蹄动物";
    DB[28] = "偶蹄动物";
    DB[29] = "海燕";
    DB[30] = "老虎";
    DB[31] = "金钱豹";
    DB[32] = "长颈鹿";
    DB[33] = "斑马";
    DB[34] = "鸵鸟";
    DB[35] = "企鹅";

    R[1].push_back(24);
    R[1].push_back(1);
    R[2].push_back(24);
    R[2].push_back(2);
    R[3].push_back(25);
    R[3].push_back(3);
    R[4].push_back(25);
    R[4].push_back(4);
    R[4].push_back(5);
    R[5].push_back(26);
    R[5].push_back(9);
    R[5].push_back(24);
    R[6].push_back(26);
    R[6].push_back(6);
    R[6].push_back(7);
    R[6].push_back(8);
    R[6].push_back(24);
    R[7].push_back(27);
    R[7].push_back(10);
    R[7].push_back(24);
    R[8].push_back(28);
    R[8].push_back(10);
    R[8].push_back(11);
    R[9].push_back(30);
    R[9].push_back(12);
    R[9].push_back(13);
    R[9].push_back(26);
    R[10].push_back(31);
    R[10].push_back(12);
    R[10].push_back(14);
    R[10].push_back(26);
    R[11].push_back(32);
    R[11].push_back(10);
    R[11].push_back(12);
    R[11].push_back(15);
    R[11].push_back(16);
    R[11].push_back(17);
    R[12].push_back(33);
    R[12].push_back(10);
    R[12].push_back(13);
    R[12].push_back(18);
    R[13].push_back(34);
    R[13].push_back(15);
    R[13].push_back(16);
    R[13].push_back(19);
    R[13].push_back(25);
    R[14].push_back(35);
    R[14].push_back(19);
    R[14].push_back(20);
    R[14].push_back(21);
    R[14].push_back(25);
    R[15].push_back(29);
    R[15].push_back(22);
    R[15].push_back(23);
    R[15].push_back(25);
}

bool check(int x)
{
    return (x >= 1 && x <= 35);
}
void emptyAll()
{
    for (int i = 0; i < MAXN; i++)
    {
        vis[i] = 0;
    }
}

int main()
{
    //	ios::sync_with_stdio(false);
    //	cin.tie(0); cout.tie(0);
    Pretreat();
    while (1)
    {
        emptyAll();
        cout
            << "**********动物识别系统**********" << endl
            << endl;
        for (int i = 1; i <= 35; i++)
        {
            cout << i << ": " << DB[i] << "  ";
            if (!(i % 5))
                cout << endl
                     << endl;
        }
        cout << "请输入特征数量：" << endl;
        cin >> cnt;
        if (!check(cnt))
        {
            cout << "非法输入，程序终止！！！" << endl;
            system("pause");
            return 0;
        }
        for (int i = 1; i <= cnt; i++)
        {
            cout << "请输入第" << i << "个特征编号" << endl;
            cin >> num;
            if (!check(num))
            {
                cout << "非法输入，程序终止！！！" << endl;
                system("pause");
                return 0;
            }
            vis[num] = 1;
        }
        cout << "前提条件：" << endl;
        for (int i = 1; i <= 35; i++)
        {
            if (vis[i])
                cout << DB[i] << "  ";
        }
        cout << endl
             << endl;
        cout << "推理过程如下：" << endl;
        for (int i = 1; i <= 15; i++)
        {
            bool is = 1;
            for (int j = 1; j < R[i].size(); j++)
            {
                if (!vis[R[i][j]])
                {
                    is = 0;
                    break;
                }
            }
            if (is && vis[R[i][0]] != 1)
            {
                for (int j = 1; j < R[i].size(); j++)
                    cout << DB[R[i][j]] << " ";
                cout << "--> " << DB[R[i][0]] << endl;
                vis[R[i][0]] = 1;
                ans = DB[R[i][0]];
            }
        }
        cout << endl;
        cout << "该动物有如下特征：" << endl;
        for (int i = 1; i <= 35; i++)
            if (vis[i])
                cout << DB[i] << " ";
        cout << endl
             << endl;
        if (ans != "")
            cout << "该动物是" << ans << endl;

        system("pause");
        system("cls");
    }
}