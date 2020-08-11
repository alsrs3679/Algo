package Algo0810;

import java.util.Scanner;

public class BJ_2444_º°Âï±â7 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		for(int i = 1; i <= 2 * N - 1; i++)
		{
			for(int j = 1; j <= 2 * N - 1; j++)
			{
				if(i <= N)
				{
					if(j <= Math.abs(N - i))
						System.out.print(' ');
					else if(j >= Math.abs(N + i))
						break;
					else
						System.out.print('*');
				}
				else
				{
					if(j <= Math.abs(i - N))
						System.out.print(' ');
					else if(j >= Math.abs(3 * N - i))
						break;
					else
						System.out.print('*');
				}
			}
			System.out.println();
		}
	}

}
