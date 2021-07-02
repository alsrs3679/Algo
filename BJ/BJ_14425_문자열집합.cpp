#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
	int N, M;
	int ans = 0;
	cin >> N >> M;

	vector <string> s;
	string str;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		s.push_back(str);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
	
		for (int j = 0; j < N; j++)
		{
			if (s[j] == str)
			{
				ans++;
				break;
			}
		}
	}

	cout << ans;
}



//int main() {
//    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//    int n, m; cin >> n; cin >> m;
//
//    vector<string> s(n); // S집합 문자열
//    vector<string> arr(m); // 검사해야할 문자열
//    for (int i = 0; i < n; ++i) cin >> s[i];
//    for (int i = 0; i < m; ++i) cin >> arr[i];
//
//    unordered_set<string> hash_set; // 해시셋
//    for (int i = 0; i < n; ++i) // 해시셋에 S집합 문자열들 저장
//        hash_set.insert(s[i]);
//
//    int count = 0;
//    for (int i = 0; i < m; ++i)
//        if (hash_set.find(arr[i]) != hash_set.end()) // 집합 S 에 있다면 
//            ++count;
//
//    cout << count;
//}