package com.suha.dsa;

import java.util.Stack;

public class Calculator {

    public static int calculate(String s) {
        Stack<Integer> st = new Stack<>();
        int val = 0;
        char op = '+';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                val = val * 10 + (int)(c - '0');
            }
            if ((int)c == 42 || (int)c == 43 || (int)c == 45 || (int)c == 47 || i == s.length() - 1) {
                if (op == '+') {
                    st.push(val);
                } else if (op == '-') {
                    st.push(-val);
                } else {
                    val = (op == '*') ? st.pop() * val : st.pop() / val;
                    st.push(val);
                }
                op = c;
                val = 0;
            }
        }
        return st.stream().reduce(0, Integer::sum);
    }

    public static void main(String[] args) {
        System.out.println(calculate(" 3+5 / 2 "));
    }
}
