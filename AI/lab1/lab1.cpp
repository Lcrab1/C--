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
    DB[1] = "����";
    DB[2] = "��ë��";
    DB[3] = "����ë";
    DB[4] = "���";
    DB[5] = "����";
    DB[6] = "��צ";
    DB[7] = "��Ȯ��";
    DB[8] = "Ŀ��ǰ��";
    DB[9] = "����";
    DB[10] = "����";
    DB[11] = "��ۻʳ��";
    DB[12] = "�ƺ�ɫ";
    DB[13] = "��ɫ����";
    DB[14] = "��ɫ�ߵ�";
    DB[15] = "����";
    DB[16] = "������";
    DB[17] = "���ߵ�";
    DB[18] = "��ɫ";
    DB[19] = "�����";
    DB[20] = "�ڰ�ɫ";
    DB[21] = "����Ӿ";
    DB[22] = "�Ʒ�";
    DB[23] = "���·���";
    DB[24] = "���鶯��";
    DB[25] = "��";
    DB[26] = "ʳ�⶯��";
    DB[27] = "���㶯��";
    DB[28] = "ż�㶯��";
    DB[29] = "����";
    DB[30] = "�ϻ�";
    DB[31] = "��Ǯ��";
    DB[32] = "����¹";
    DB[33] = "����";
    DB[34] = "����";
    DB[35] = "���";

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
            << "**********����ʶ��ϵͳ**********" << endl
            << endl;
        for (int i = 1; i <= 35; i++)
        {
            cout << i << ": " << DB[i] << "  ";
            if (!(i % 5))
                cout << endl
                     << endl;
        }
        cout << "����������������" << endl;
        cin >> cnt;
        if (!check(cnt))
        {
            cout << "�Ƿ����룬������ֹ������" << endl;
            system("pause");
            return 0;
        }
        for (int i = 1; i <= cnt; i++)
        {
            cout << "�������" << i << "���������" << endl;
            cin >> num;
            if (!check(num))
            {
                cout << "�Ƿ����룬������ֹ������" << endl;
                system("pause");
                return 0;
            }
            vis[num] = 1;
        }
        cout << "ǰ��������" << endl;
        for (int i = 1; i <= 35; i++)
        {
            if (vis[i])
                cout << DB[i] << "  ";
        }
        cout << endl
             << endl;
        cout << "����������£�" << endl;
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
        cout << "�ö���������������" << endl;
        for (int i = 1; i <= 35; i++)
            if (vis[i])
                cout << DB[i] << " ";
        cout << endl
             << endl;
        if (ans != "")
            cout << "�ö�����" << ans << endl;

        system("pause");
        system("cls");
    }
}