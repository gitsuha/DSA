package com.suha.app;


class Solution {
    public int titleToNumber(String A) {
        int n = A.length();
        int val = 0;
        int a = (int)'A';
        for (int i = 0; i < n; i++)
        {
        	int c = A.charAt(i);
        	int m = (int)(c - a) + 1;
        	int p = (int)Math.pow(26, (n - i - 1));
        	val += m*p;        	
        }
        return val;
    }
}

public class ExcelColumnNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Solution s = new Solution();
		System.out.println(s.titleToNumber("AAA"));
	}
}
