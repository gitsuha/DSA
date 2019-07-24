package com.suha.app;

import java.util.*;

class Solution
{
	List<Integer> primeNumberList(int n) {
		List<Integer> primes = new ArrayList<Integer>();
		boolean[] marks = new boolean[n + 1];
		Arrays.fill(marks, true);
		for (int i=2; i*i<=n; i++)
		{
			if (marks[i] == true)
			{
				for (int j=i*i; j<=n; j+=i)
				{
					marks[j] = false;
				}
			}
		}
		
		for (int i=2; i <= n; i++)
		{
			if (marks[i] == true)
				primes.add(i);
		}
		
		return primes;
	}
}
public class SeiveOfEratosthenes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(n);
		scan.close();
		
		Solution s = new Solution();
		List<Integer> primes = s.primeNumberList(n);
		primes.forEach(i -> System.out.print(i + " "));
	}

}
