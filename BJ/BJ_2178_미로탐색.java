import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class BJ_2178_미로탐색 {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();
        int map[][] = new int[N + 1][M + 1];
        int road[][] = new int[N + 1][M + 1];

        for(int i = 1; i <= N; i++)
        {
            String str = sc.nextLine();

            for(int j = 1; j <= M; j++)
                map[i][j] = str.charAt(j - 1) - 48;
        }

        Queue<Integer> que = new LinkedList<>();
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        int ans = 0;

        que.add(1);
        que.add(1);
        que.add(1);
        road[1][1] = 1;

        while(true)
        {
            if(que.size() == 0)
                break;

            int x = que.poll();
            int y = que.poll();
            int cnt = que.poll();

            if(x == N && y == M)
            {
                ans = cnt;
                break;
            }

            for(int i = 0; i < 4; i++)
            {
                int next_x = x + di[i];
                int next_y = y + dj[i];

                if(next_x < 0 || next_x > N || next_y < 0 || next_y > M)
                    continue;

                if(map[next_x][next_y] == 1 && road[next_x][next_y] == 0)
                {
                    que.add(next_x);
                    que.add(next_y);
                    que.add(cnt + 1);
                    road[next_x][next_y] = 1;
                }
            }
        }

        System.out.println(ans);

    }

}
