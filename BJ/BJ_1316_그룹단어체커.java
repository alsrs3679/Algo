import java.util.Scanner;

public class BJ_1316_그룹단어체커 {

    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int input = sc.nextInt();

        System.out.println(checkerNum(input));
    }

    public static int checkerNum(int N){
        String[] words = new String[N];
        int total = 0;
        int checking = 0;

        for (int i = 0; i < words.length; i++) {
            words[i] = sc.next();
            char[] wordsArr = words[i].toCharArray();

            for (int j = 0; j < words[i].length(); j++)
            {
                for (int j2 = j+1; j2 < words[i].length(); j2++)
                {
                    if(wordsArr[j] != wordsArr[j+1] && wordsArr[j] == wordsArr[j2])
                    {
                        checking = 1;
                    }
                }
            }
            if(checking == 0)
            {
                total++;
            }
            checking = 0;
        }
        return total;

    }
}