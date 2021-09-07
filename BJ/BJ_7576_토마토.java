
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class BJ_7576_토마토 {

    public static class POINT{
        int i;
        int j;
        int count;

        public POINT() { }
        public POINT(int i, int j, int count)
        {
            this.i = i;
            this.j = j;
            this.count = count;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

//		Scanner sc = new Scanner(System.in);
//		int M = sc.nextInt();
//		int N = sc.nextInt();

        int map[][] = new int[N][M];
        int map_level[][] = new int[N][M];
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        Queue<POINT> s = new LinkedList<POINT>();

        int temp = 0;

        for(int i = 0; i < N; i++)
        {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++)
            {
                temp = Integer.parseInt(st.nextToken());
                map[i][j] = temp;
                map_level[i][j] = 99999;

            }
        }

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(map[i][j] == 1)
                {
                    s.offer(new POINT(i, j, 1));
                    map_level[i][j] = 0;
                }
            }
        }

        int nowi, nowj, nexti, nextj, cnt;

        while(!s.isEmpty())
        {
            nowi = s.peek().i;
            nowj = s.peek().j;
            cnt = s.peek().count;

            s.poll();

            for(int k = 0; k < 4; k++)
            {
                nexti = nowi + di[k];
                nextj = nowj + dj[k];

                if (nexti < 0 || nexti >= N || nextj < 0 || nextj >= M)
                    continue;

                if(map[nexti][nextj] == 0)
                {
                    map[nexti][nextj] = cnt + 1;
                    s.offer(new POINT(nexti, nextj, cnt + 1));
                }
            }
        }

        int check = 0;
        int max = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(map[i][j] == 0)
                {
                    check = 1;
                    break;
                }
                if(max < map[i][j])
                    max = map[i][j];
            }
        }

        if(check == 1)
            System.out.println(-1);
        else
            System.out.println(max - 1);


    } // eom

} //eoc
