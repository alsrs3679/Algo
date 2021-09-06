

import java.util.Scanner;

public class BJ_6987_월드컵 {



    static int play1[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    static int play2[] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};		//15번의 경기내용
    static int res[][];	//입력값 저장
    static int ans;
    static int once;
    public static void dfs(int index)
    {
        if(index == 15)
        {
            once = 1;
            int check = 0;
            for(int i = 0; i < 6; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(res[i][j] != 0)
                        ans = 0;
                }
            }
            return;
        }


        //play1 승 play2 패
        res[play1[index]][0]--;
        res[play2[index]][2]--;

        if(res[play1[index]][0] >= 0 && res[play2[index]][2] >= 0)
            dfs(index + 1);

        res[play1[index]][0]++;
        res[play2[index]][2]++;



        //play1 무 play2 무
        res[play1[index]][1]--;
        res[play2[index]][1]--;

        if(res[play1[index]][1] >= 0 && res[play2[index]][1] >= 0)
            dfs(index + 1);

        res[play1[index]][1]++;
        res[play2[index]][1]++;



        //play1 패 play2 승
        res[play1[index]][2]--;
        res[play2[index]][0]--;

        if(res[play1[index]][2] >= 0 && res[play2[index]][0] >= 0)
            dfs(index + 1);

        res[play1[index]][2]++;
        res[play2[index]][0]++;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for(int T = 1; T <= 4; T++)
        {
            res = new int[6][3];

            for(int i = 0; i < 6; i++)
            {
                for(int j = 0; j < 3; j++)
                    res[i][j] = sc.nextInt();
            }

            ans = 1;
            once = 0;
            //1. 한 나라의 승,무,패 합이 5인지 확인
            int temp = 0;
            for(int i = 0; i < 6; i++)
            {
                temp = 0;
                for(int j = 0; j < 3; j++)
                    temp += res[i][j];

                if(temp != 5)
                    ans = 0;
            }

            if(ans == 0)
            {
                System.out.print(ans + " ");
                continue;
            }

            //2. 전체 나라의 승, 패의 갯수가 동일한지 확인
            int win = 0;
            int lose = 0;

            for(int i = 0; i < 6; i++)
            {
                win += res[i][0];
                lose += res[i][2];
            }

            if(win != lose)
                ans = 0;

            if(ans == 0)
            {
                System.out.print(ans + " ");
                continue;
            }

            dfs(0);
            if(once == 0)
                ans = 0;
            System.out.print(ans + " ");

        }
    }
}
