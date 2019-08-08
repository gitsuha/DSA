package com.suha.app;

import java.util.*;

public class KthSmallestNoExtraSpace {

    public static int kthsmallest(final List<Integer> a, int k) {
        
        if(a == null || a.size() == 0)
             throw new IllegalArgumentException("Empty or null list.");
        int lo = Collections.min(a);
        int hi = Collections.max(a);

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int countLess = 0, countEqual = 0;

            for(int i = 0; i < a.size(); i++) {
                if(a.get(i) < mid) {
                    countLess++;
                }else if(a.get(i) == mid) {
                    countEqual++;
                }
                if(countLess >= k) break;
            }

            if(countLess < k && countLess + countEqual >= k){
                return mid;
            }else if(countLess >= k) {
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }


        assert false : "k cannot be larger than the size of the list.";
        return -1;
    
    }
    
	public static void main(String[] args) {
		
		List<Integer> a = new ArrayList<>(Arrays.asList(7, 10, 4, 3, 20, 15));
		int k = 3;
		System.out.println(kthsmallest(a, k));
	}

}
