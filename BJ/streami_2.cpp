#include <iostream>
#include <vector>

using namespace std;

// Ȧ���� 1�� ����, ¦���� 2�� ������
// ������ ��Ʈ���� 1�̸� 0���� �ٲٱ�
// ������ ��Ʈ���� 0�϶�
    //1. �ε������� ��ǥ�̸� ����
    //2. �ε������� ��ǥ�� �ƴϸ� -1

int solution(string& S) {
    int target_ind = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (S.at(i) == '1')
        {
            target_ind = i;
            break;
        }
    }

    int now_ind = S.length() - 1;
    int ans = 0;
    while (1)
    {
        if (S.at(now_ind) == '1')
        {
            S.at(now_ind) = '0';
            ans++;
        }
        else
        {
            if (now_ind == target_ind)
                break;
            else
            {
                now_ind--;
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    string s = "011100";
    cout << solution(s);

}