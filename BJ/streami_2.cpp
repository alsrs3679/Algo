#include <iostream>
#include <vector>

using namespace std;

// 홀수면 1을 빼기, 짝수면 2로 나누기
// 마지막 비트값이 1이면 0으로 바꾸기
// 마지막 비트값이 0일때
    //1. 인덱스값이 목표이면 종료
    //2. 인덱스값이 목표가 아니면 -1

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