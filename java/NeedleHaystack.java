package com.suha.dsa;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class NeedleHaystack {
//    public int strStr(String haystack, String needle) {
//        if (needle.length() == 0 && haystack.length() == 0) return -1;
//        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
//            int match = 0;
//            for (int j = 0; j < needle.length(); j++) {
//                if (needle.charAt(j) == haystack.charAt(i + j))
//                    match++;
//                else
//                    break;
//            }
//            if (match == needle.length())
//                return i;
//        }
//        return -1;
//    }

//    public static int strStr(String haystack, String needle) {
//        if (needle.length() == 0) return 0;
//        if (haystack.length() == 0) return -1;
//        if (haystack.contains(needle)) return haystack.indexOf(needle);
//        return -1;
//    }

    public List<Integer> strStr(String haystack, String needle) {
        if (needle.length() == 0) return new ArrayList<Integer>(0);
        if (haystack.length() == 0) return new ArrayList<Integer>(-1);
        List<Integer> l = new ArrayList<>();
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            int match = 0;
            for (int j = 0; j < needle.length(); j++) {
                if (needle.charAt(j) == haystack.charAt(i + j))
                    match++;
                else
                    break;
            }
            if (match == needle.length())
                l.add(i);
        }
        return l;
    }

    private int[] calculateZ(String input) {
        int Z[] = new int[input.length()];
        int left = 0;
        int right = 0;
        for(int k = 1; k < input.length(); k++) {
            if(k > right) {
                left = right = k;
                while(right < input.length() && input.charAt(right) == input.charAt(right - left)) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                //we are operating inside box
                int k1 = k - left;
                //if value does not stretches till right bound then just copy it.
                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else { //otherwise try to see if there are more matches.
                    left = k;
                    while(right < input.length() && input.charAt(right) == input.charAt(right - left)) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }

    public List<Integer> patternMatching(String txt, String pattern) {
        List<Integer> l = new ArrayList<>();
        if (txt.length() < pattern.length()) {
            l.add(-1);
            return l;
        }
        String zstr = pattern + "$" + txt;

        int Z[] = calculateZ(zstr);
        for(int i = 0; i < Z.length ; i++) {
            if(Z[i] == pattern.length()) {
                l.add(i - pattern.length() - 1);
            }
        }
        return l;
    }
    public static void main(String[] args) {
        NeedleHaystack nh = new NeedleHaystack();
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String hs = sc.next();
            String nd = sc.next();
            System.out.println("NeedleHaystack(naive): " + nh.strStr(hs, nd).toString());
            System.out.println("NeedleHaystack(ZAlgo): " + nh.patternMatching(hs, nd));
        }
        sc.close();
    }
}
