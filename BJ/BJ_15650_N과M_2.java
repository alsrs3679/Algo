import java.util.Scanner;

public class BJ_15650_N과M_2 {

    static int N, M;
    static int[] arr, v;
    public static void combi(int depth, int r) {
        if(depth == M) {
            for(int i = 0; i < M; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }

        for(int i = r; i < N; i++) {
            if(v[i] == 0) {
                v[i] = 1;
                arr[depth] = i + 1;
                combi(depth + 1, i + 1);
                v[i] = 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        arr = new int[M];
        v = new int[N];

        combi(0, 0);
    }

}
