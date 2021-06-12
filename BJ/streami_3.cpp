#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& A, vector<int>& B) 
{
    int ans = 0;
    vector <int> C;
    C.assign(100001, 0);

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] <= B[i])
            C[B[i]] = 1;
        else
            C[A[i]] = 1;
    }

    for (int i = 1; i < 100001; i++)
    {
        if (C[i] == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{

}