package com.suha.dsa;

import java.util.*;

public class topKFrequent {
    public static List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> m = new HashMap<>();
        for (String word : words) {
            m.put(word, m.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> pq = new PriorityQueue<>(
                (s1, s2) -> m.get(s1).equals(m.get(s2)) ? s2.compareTo(s1) : m.get(s1) - m.get(s2)
        );
        for (String word : m.keySet()) {
            pq.offer(word);
            if (pq.size() > k) pq.poll();
        }
        List<String> l = new ArrayList<>();
        while (!pq.isEmpty()) {
            l.add(pq.poll());
        }
        Collections.reverse(l);
        return l;
    }
    public static void main(String[] args) {
        System.out.println(topKFrequent(new String[]{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4).toString());
        System.out.println(topKFrequent(new String[]{"i", "love", "leetcode", "i", "love", "coding"}, 2).toString());
    }
}
