package BaekJoon;

import java.util.Scanner;

public class BJ_14888_연산자끼워넣기 {

	static int N;
	static int arr[], cal[];
	static int maxx = -1000000000, minn = 1000000000;
	
	public static int sub_cal(int a, int b, int ind)
	{
		if(ind == 0)
			return a + b;
		else if(ind == 1)
			return a - b;
		else if(ind == 2)
			return a * b;
		else
			return a / b;
	}
	
	public static void dfs(int sum, int depth)
	{
		if(depth == N)
		{
			if(sum > maxx)
				maxx = sum;
			if(sum < minn)
				minn = sum;
			return;
		}
		
		for(int i = 0; i < 4; i++)
		{
			if(cal[i] == 0)
				continue;
			
			int now = sub_cal(sum, arr[depth], i);
			cal[i]--;
			dfs(now, depth + 1);
			cal[i]++;
		}
	}
	
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		arr = new int[N];
		cal = new int[4];
		
		for(int i = 0; i < N; i++) 
			arr[i] = sc.nextInt();


		for(int i = 0; i < 4; i++) 
			cal[i] = sc.nextInt();
		
		dfs(arr[0], 1);
		
		System.out.println(maxx);
		System.out.println(minn);
	}

}
