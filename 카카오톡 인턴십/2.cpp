#include <iostream>


#include <string>
#include <vector>
#include <queue>

using namespace std;

//깊이가 2인 dfs
//1. 한개의 대기실마다 배열정보를 불러와서 2차원 배열에 저장
//   벽:5 사람:1 빈공간:0
//2. 각 대기실마다 bfs를 진행 (깊이가 2까지만)
//   단, 배열 전체를 탐색하며 각 P마다 bfs진행
//3. O면 지나가고 X면 못지나가는데 P를 만나면 거리두기를 지키지 않은것
//   그때 반복문을 종료하고 0을 저장 

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int di[4] = { 0, 1, 0, -1 };
    int dj[4] = { 1, 0, -1, 0 };

    for (int T = 0; T < 5; T++)
    {
        vector <vector <int> > map;
        vector <int> map_temp;
        string temp_s;

        for (int i = 0; i < 5; i++)
        {
            temp_s = places[T][i];

            for (int j = 0; j < 5; j++)
            {
                if (temp_s.at(j) == 'P')
                    map_temp.push_back(1);
                else if (temp_s.at(j) == 'O')
                    map_temp.push_back(0);
                else if (temp_s.at(j) == 'X')
                    map_temp.push_back(5);
            }
            map.push_back(map_temp);
            map_temp.clear();
        }

        //거리두기 안지키면 1이됨
        int check = 0;
        
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (check == 1)
                    break;
                if (map[i][j] == 1)
                {
                    vector <vector <int> > road;
                    vector <int> temp_road;
                    temp_road.assign(5, 0);
                    road.assign(5, temp_road);

                    queue <int> que;
                    int depth = 0;
                    int now_i = i;
                    int now_j = j;

                    que.push(now_i);
                    que.push(now_j);
                    que.push(depth);
                    road[now_i][now_j] = 1;

                    while (!que.empty())
                    {
                        if (check == 1)
                            break;

                        now_i = que.front();
                        que.pop();
                        now_j = que.front();
                        que.pop();
                        depth = que.front();
                        que.pop();

                        if (depth >= 2)
                            break;

                        for (int k = 0; k < 4; k++)
                        {
                            int next_i = now_i + di[k];
                            int next_j = now_j + dj[k];

                            if (next_i < 0 || next_i >= 5 || next_j < 0 || next_j >= 5)
                                continue;
                            
                            if (road[next_i][next_j] == 1)
                                continue;
                            
                            if (map[next_i][next_j] == 5)
                                continue;
                            
                            else if (map[next_i][next_j] == 0)
                            {
                                que.push(next_i);
                                que.push(next_j);
                                que.push(depth + 1);
                                road[next_i][next_j] = 1;
                            }
                            else if (map[next_i][next_j] == 1)
                            {
                                check = 1;
                                break;
                            }
                        }
                    }

                }
            }
        }

        // 여기까지 check가 0이면 모두 거리두기 잘지킨것, 1이면 반대
        if (check == 0)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}

int main()
{
    vector <int> answer;
    vector<vector<string>> places;
    vector <string> temp;

    temp.push_back("POOOP");
    temp.push_back("OXXOX");
    temp.push_back("OPXPX");
    temp.push_back("OOXOX");
    temp.push_back("POXXP");
    places.push_back(temp);
    temp.clear();

    temp.push_back("POOPX");
    temp.push_back("OXPXP");
    temp.push_back("PXXXO");
    temp.push_back("OXXXO");
    temp.push_back("OOOPP");
    places.push_back(temp);
    temp.clear();

    temp.push_back("PXOPX");
    temp.push_back("OXOXP");
    temp.push_back("OXPXX");
    temp.push_back("OXXXP");
    temp.push_back("POOXX");
    places.push_back(temp);
    temp.clear();

    temp.push_back("OOOXX");
    temp.push_back("XOOOX");
    temp.push_back("OOOXX");
    temp.push_back("OXOOX");
    temp.push_back("OOOOO");
    places.push_back(temp);
    temp.clear();

    temp.push_back("PXPXP");
    temp.push_back("XPXPX");
    temp.push_back("PXPXP");
    temp.push_back("XPXPX");
    temp.push_back("PXPXP");
    places.push_back(temp);
    temp.clear();

    answer = solution(places);


}