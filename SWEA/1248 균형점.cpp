//#include <iostream>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//
//vector <vector <int> > v;
//vector <int> temp_v, ans;
//int N;
//
//void binary_search(double mid, double left, double right)
//{
//	double power_left = 0;
//	double power_right = 0;
//	long long a, b;
//	for (int i = 0; i <= left; i++)
//	{
//		power_left += v[1][i] / pow(mid - v[0][i], 2);
//	}
//
//	for (int i = right; i < v[0].size(); i++)
//	{
//		power_right += v[1][i] / pow(mid - v[0][i], 2);
//	}
//	//a = power_left * 10000000000;
//	//b = power_right * 10000000000;
//	//power_left = (double)a / 10000000000;
//	//power_right = (double)b / 10000000000;
//
//
//	if (power_left == power_right)
//	{
//		ans.push_back(mid);
//		return;
//	}
//	else if (power_left > power_right)
//	{
//		binary_search((v[0][right] + mid) / 2, left, right);
//	}
//	else
//		binary_search((mid + v[0][left]) / 2, left, right);
//}
//
//
//int main()
//{
//	int T, testcase;
//
//	cin >> testcase;
//
//	for (T = 1; T <= testcase; T++)
//	{
//		v.clear();
//		temp_v.clear();s
//
//		int temp, a;
//
//		cin >> N;
//
//		for (int i = 0; i < 2; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				cin >> temp;
//				temp_v.push_back(temp);
//			}
//			v.push_back(temp_v);
//			temp_v.clear();
//		}
//
//		cout << "#" << T << " ";
//
//		for (int i = 0; i < N - 1; i++)
//		{
//			int asd = i;
//			binary_search((v[0][asd] + v[0][asd + 1]) / 2, asd, asd + 1);
//			cout << fixed;
//			cout.precision(10);
//			cout << ans[i] << " ";
//		}
//
//		cout << endl;
//		ans.clear();
//	}
//}