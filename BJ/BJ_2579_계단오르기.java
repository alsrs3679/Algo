import java.util.Scanner;


public class BJ_2579_계단오르기 {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int v[] = new int[n + 1];
        for(int i = 1; i <= n; i++)
            v[i] = sc.nextInt();

        int dpv[] = new int[n + 1];

        dpv[0] = 0;
        dpv[1] = v[1];

        if(n > 1)
            dpv[2] = v[2] + v[1];

        for(int i = 3; i <= n; i++)
        {
            int a = dpv[i - 2] + v[i];
            int b = dpv[i - 3] + v[i] + v[i - 1];
            if(a > b)
                dpv[i] = a;
            else
                dpv[i] = b;
        }

        System.out.println(dpv[n]);

    }

}
