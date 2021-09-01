import java.util.Scanner;

public class BJ_2630_색종이만들기 {






    static int color[] = new int[2];


    private static void div(int[][] v, int len)
    {
        if(len == 1)
        {
            color[v[0][0]]++;
            return;
        }
        int now = 3, check = 0;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(now == 3)
                    now = v[i][j];
                else if(now != v[i][j])
                {
                    check = 1;
                    break;
                }
            }
            if(check == 1)
                break;
        }

        if(check == 0)
        {
            color[now]++;
            return;
        }
        else
        {
            int temp_v[][]= new int[len / 2][len / 2];
            for(int q = 0; q < 4; q++)
            {
                for(int i = 0 + (q / 2) * (len / 2); i < len / 2 + (q / 2) * (len / 2); i++)
                {
                    for(int j = 0 + (q % 2) * (len / 2); j < len / 2 + (q % 2) * (len / 2); j++)
                        temp_v[i - (q / 2) * (len / 2)][j - (q % 2) * (len / 2)] = v[i][j];
                }
                div(temp_v, len / 2);

            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int map[][] = new int[N][N];
        int temp;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                temp = sc.nextInt();
                map[i][j] = temp;
            }
        }

        div(map, N);

        System.out.println(color[0]);
        System.out.println(color[1]);

    }

}