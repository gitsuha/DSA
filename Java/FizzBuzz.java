package com.suha.app;

import java.util.*;

class Solution {
    public ArrayList<String> fizzBuzz(int A) {
        
        ArrayList<String> l = new ArrayList<String>();
        for (int i = 1; i <= A; i++)
        {
        	if (i % 15 == 0)
        	{
        		l.add("FizzBuzz");
        	}
        	else if (i % 3 == 0)
        	{
        		l.add("Fizz");
        	}
        	else if (i % 5 == 0)
        	{
        		l.add("Buzz");
        	}
        	else
        	{
        		l.add(Integer.toString(i));
        	}
        }
		return l;        
    }
}

public class FizzBuzz {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Solution s = new Solution();
		ArrayList<String> l = s.fizzBuzz(16);
		l.forEach(i -> System.out.println(i));
	}

}
