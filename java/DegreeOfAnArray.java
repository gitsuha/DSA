package com.suha.dsa;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DegreeOfAnArray {
    public static int solve(int [] arr) {
        int n = arr.length;
        Map<Integer, int[]> freq = new HashMap<>(); // degree, left, right
        for (int i = 0; i < n; i++) {
            if (freq.containsKey(arr[i])) {
                int data[] = freq.get(arr[i]);
                data[0]++;
                data[2] = i;
            } else {
                int data[] = {1, i, i};
                freq.put(arr[i], data);
            }
        }
        int ans = Integer.MAX_VALUE;
        int d = 0;
        for (int i : freq.keySet()) {
            int data[] = freq.get(i);
            if (data[0] > d) {
                d = data[0];
                ans = data[2] - data[1] + 1;
            } else if (data[0] == d)
                ans = Math.min(ans, data[2] - data[1] + 1);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        String[] words = s.split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(words[i]);
        }
        System.out.println(solve(arr));
    }
}
