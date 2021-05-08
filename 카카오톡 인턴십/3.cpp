#include <iostream>


#include <string>
#include <vector>
#include <stack>

using namespace std;
// �ѹ�Ž��
// Z��ɾ� ����� ���� ���õ� ���� �ε��� ������ �ƴ��� ����
// ���� ������ 100�� ��ɾ�� 20��
// ������ɾ� ����� ������ ������ ���ÿ� ����, ���� ��ɾ� �����Ҷ� ���ÿ��� ��������
//      �ε��� ��ȣ�� �����ϸ� �ɵ�
// erase, insert����ؼ� ���� ���� ����

string solution(int n, int k, vector <string> cmd) {
    string answer = "";

    vector <int> v, for_ans;
    stack <vector <int> > st;
    int num = 0;
    for (int i = 0; i < n; i++)
        v.push_back(num++);
    for_ans.assign(n, 0);
    int now = k;
    int move;
    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i].at(0) == 'U')
        {
            move = stoi(cmd[i].substr(2));
            now = now - move;
        }

        else if (cmd[i].at(0) == 'D')
        {
            move = stoi(cmd[i].substr(2));
            now = now + move;
        }
        else if (cmd[i].at(0) == 'C')
        {
            vector <int> temp;
            temp.push_back(now);
            temp.push_back(v[now]);
            st.push(temp);
            v.erase(v.begin() + now);
            if (now == v.size())
                now--;
        }

        else if (cmd[i].at(0) == 'Z')
        {
            int ind = st.top()[0];
            int val = st.top()[1];
            st.pop();

            if (ind >= v.size())
                v.push_back(val);
            else if (ind <= now)
            {
                v.insert(v.begin() + ind, val);
                now++;
            }
            else
                v.insert(v.begin() + ind, val);
        }
    }

    for (int i = 0; i < st.size(); i++)
    {
        int ind = st.top()[0];
        int val = st.top()[1];
        st.pop();
        i--;
        for_ans[val] = 1;
    }

    for (int i = 0; i < for_ans.size(); i++)
    {
        if (for_ans[i] == 0)
            answer += "O";
        else
            answer += "X";
    }

    return answer;
}

int main()
{
    vector <string> cmd;
    //cmd.push_back("D 2");
    //cmd.push_back("C");
    //cmd.push_back("U 3");
    //cmd.push_back("C");
    //cmd.push_back("D 4");
    //cmd.push_back("C");
    //cmd.push_back("U 2");
    //cmd.push_back("Z");
    //cmd.push_back("Z");
    //cmd.push_back("U 1");
    //cmd.push_back("C");
    cmd.push_back("C");
    cmd.push_back("D 2");
    cmd.push_back("C");
    cmd.push_back("D 2");
    cmd.push_back("Z");
    cmd.push_back("Z");

    string an;
    an = solution(8, 0, cmd);
    cout << an;
}