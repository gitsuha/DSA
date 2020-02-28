package com.suha.dsa;

import java.math.BigInteger;

public class climbStairs {
    public static BigInteger [] dp;
    public static BigInteger solve(BigInteger [] dp, int n) {
        if (n == 1) return BigInteger.valueOf(1);
        if (n == 2) return BigInteger.valueOf(2);

        if (dp[n - 1] == null)
            dp[n - 1] = solve(dp, n - 1).add(solve(dp, n - 2));

        return dp[n - 1];
    }
    public static BigInteger climbStairs(int n) {
        dp = new BigInteger[n];
        dp[0] = BigInteger.valueOf(1);
        dp[1] = BigInteger.valueOf(2);
        return solve(dp, n);
    }
    public static void main(String[] args) {
        System.out.println(climbStairs(50));
    }
}
