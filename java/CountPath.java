package com.suha.dsa;

import java.util.*;

class Graph {
    int v;
    LinkedList<Integer> adj[];
    Graph(int v) {
        this.v = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList<>();
    }
    void addEdge(int i, int j) {
        adj[i].add(j);
        adj[j].add(i);
    }
    int solve(int i, int j, int count, boolean visited[]) {
        visited[i] = true;
        if (i == j)
            count++;
        else {
            Iterator<Integer> k = adj[i].listIterator();
            while (k.hasNext()) {
                int n = k.next();
                if (!visited[n]) {
                    count = solve(n, j, count, visited);
                }
            }
        }
        visited[i]=false;
        return count;
    }
    int countPath(int s, int d) {
        boolean visitor[] = new boolean[v];
        Arrays.fill(visitor, false);
        int count = 0;
        int i = 0;
        count = solve(s, d, i, visitor);
        Arrays.fill(visitor, false);
        i = 0;
        count += solve(d, s, i, visitor);
        return count;
    }
}

public class CountPath {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            Graph g = new Graph(n);
            int e = sc.nextInt();
            for (int j = 0; j < e; j++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                g.addEdge(a, b);
            }
            int q = sc.nextInt();
            int l = sc.nextInt();
            for (int j = 0; j < q; j++) {
                int s = sc.nextInt();
                int d = sc.nextInt();
                System.out.println(g.countPath(s, d));
            }
        }
        sc.close();
    }
}
