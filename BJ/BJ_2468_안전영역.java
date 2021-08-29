
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class BJ_2468_안전영역 {



    public static class Point{
        int x;
        int y;
        Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int map[][] = new int[N][N];
        boolean mche[][] = new boolean[N][N];
        int check = 1, max = 0;
        int ans = 0;
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                map[i][j] = sc.nextInt();
                if(max < map[i][j])
                    max = map[i][j];
            }
        }

        for(int k = 0; k <= max; k++)
        {
            Queue<Point> que = new LinkedList<Point>();
            mche = new boolean[N][N];
            check = 1;
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    if(map[i][j] - k > 0 && mche[i][j] == false)
                    {
                        que.add(new Point(i, j));
                        mche[i][j] = true;
                        while(!que.isEmpty())
                        {
                            Point p = que.poll();
                            for(int t = 0; t < 4; t++)
                            {
                                int nexti = p.x + di[t];
                                int nextj = p.y + dj[t];

                                if(nexti < 0 || nexti >= N || nextj < 0 || nextj >= N)
                                    continue;

                                if(map[nexti][nextj] - k > 0 && mche[nexti][nextj] == false)
                                {
                                    que.add(new Point(nexti, nextj));
                                    mche[nexti][nextj] = true;
                                }
                            }
                        }
                        check++;
                    }
                }
            }

            if(ans < check)
                ans = check;

        }

        System.out.println(ans - 1);

    }

}
