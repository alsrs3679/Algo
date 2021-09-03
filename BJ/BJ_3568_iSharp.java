import java.util.Scanner;
import java.util.Stack;



public class BJ_3568_iSharp {




    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();
        String arr[] = str.split(" ");

        String type = arr[0];

        for(int i = 1; i < arr.length; i++)
        {
            String temp = type;
            String val = arr[i];
            String name = "";
            Stack<String> stack = new Stack<>();
            for(int j = 0; j < val.length() - 1; j++)
            {
                if(val.charAt(j) != '*' && val.charAt(j) != '&' && val.charAt(j) != '[' )
                {
                    name += val.charAt(j);
                    continue;
                }
                if(val.charAt(j) == '[')
                {
                    stack.push("[]");
                    j++;
                }
                else
                    stack.push(String.valueOf(val.charAt(j)));
            }

            int n = stack.size();
            for(int j = 0; j < n; j++)
                temp += stack.pop();

            System.out.println(temp + " " + name + ";");
        }

    }


}
