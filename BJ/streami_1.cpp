#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& A) {
    int ans = 2000; for (int i = 0; i < A.size(); i++) {
        if (ans > A[i]) {
            ans = A[i];
        }
    }
    return ans;
}


int main()
{
    vector <int> a;
    a.push_back(1);
    a.push_back(11);
    a.push_back(32);
    a.push_back(2);
    
    cout << solution(a);
}