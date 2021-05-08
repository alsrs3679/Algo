#include <iostream>


#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string an = "";
    vector <string> map;
    map.push_back("zero");
    map.push_back("one");
    map.push_back("two");
    map.push_back("three");
    map.push_back("four");
    map.push_back("five");
    map.push_back("six");
    map.push_back("seven");
    map.push_back("eight");
    map.push_back("nine");

    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) >= 48 && s.at(i) <= 57)
            an += s.at(i);
        else
        {
            for (int j = 0; j < 10; j++)
            {
                if (s.find(map[j], i) == i)
                {
                    an += to_string(j);
                    i = i + map[j].length() - 1;
                    break;
                }
            }
        }
    }

    answer = stoi(an);
    return answer;
}

int main()
{
    string asd;
    cin >> asd;
    cout << solution(asd);
}