package com.suha.app;

public class StepClimbingRecurrDP {

	static int solve_recurr(int n) {
		if (n == 0 || n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else
			return solve_recurr(n - 3) + solve_recurr(n - 2) + solve_recurr(n - 1);
	}
	
    static int solve_dp(int n) 
    { 
        int[] res = new int[n + 1]; 
        res[0] = 1; 
        res[1] = 1; 
        res[2] = 2; 
  
        for (int i = 3; i <= n; i++) 
            res[i] = res[i - 1] + res[i - 2] 
                                + res[i - 3]; 
  
        return res[n]; 
    }
    
	public static void main(String[] args) {
		System.out.println(solve_recurr(4));
		System.out.println(solve_dp(4));
	}

}
