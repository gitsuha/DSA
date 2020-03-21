package com.suha.dsa.graph;

import javax.swing.*;
import java.util.*;

class Vertex {
    char id;
    int d, f;
    List<Vertex> adj;
    Vertex p;
    boolean visited;
    Vertex(char id) {
        adj = new LinkedList<>();
        this.id = id;
        d = f = 0;
        p = null;
        visited = false;
    }

    @Override
    public String toString() {
        return "Vertex{" +
                "id=" + id +
                ", d=" + d +
                ", f=" + f +
                ", p=" + (p == null ? "null" : p.id) +
                '}' + '\n';
    }
}

class Edge {
    Vertex u, v;
    String label;
    Edge(Vertex u, Vertex v) {
        this.u = u;
        this.v = v;
        label = new String();
    }
}
class Graph {
    int time;
    private Map<Character, Vertex> vertices;
    List<Edge> edges;

    Graph() {
        time = 0;
        vertices = new HashMap<>();
        edges = new ArrayList<>();
    }
    public void addVertex(Vertex v) {
        vertices.put(v.id, v);
    }
    public void addEdge(char id1, char id2)
    {
        Vertex v1 = vertices.get(id1);
        Vertex v2 = vertices.get(id2);
        v1.adj.add(v2);
//        edges.add(new Edge(v1, v2));
    }
    public void Reset() {
        time = 0;
        for (Vertex v : vertices.values()) {
            v.d = v.f = 0;
            v.p = null;
            v.visited = false;
        }
    }
    public void DFSReccur() {
        Reset();
        for (Vertex v : vertices.values()) {
            if (!v.visited)
                DFSVertex(v);
        }
    }
    private void DFSVertex(Vertex v) {
        v.d = ++time;
        v.visited = true;
        for (Vertex u : v.adj) {
            if (!u.visited) {
                u.visited = true;
                DFSVertex(u);
                u.p = v;
            }
        }
        v.f = ++time;
    }

    public void DFSIter() {
        Reset();
        Stack<Object> s = new Stack<>();
        for (Vertex v : vertices.values()) {
            s.push(v);
        }
        while (!s.isEmpty()) {
            Object x = s.peek();
            s.pop();
            if (x instanceof Vertex)
                ExploreVertex(x, s);
            else
                ExploreEdge(x, s);
        }
    }

    private void ExploreVertex(Object o, Stack<Object> s) {
        Vertex v = (Vertex)o;
        if (v == null) return;
        if (!v.visited) {
            v.visited = true;
            v.d = ++time;
            s.push(v);
            for (Vertex u : v.adj) {
                s.push(new Edge(v, u));
            }
        } else if (v.f == 0) {
            v.f = ++time;
        } else return;
    }

    private void ExploreEdge(Object o, Stack<Object> s) {
        Edge e = (Edge)o;
        if (e == null) return;
        Vertex u = e.u;
        Vertex v = e.v;
        if (!v.visited) {
            e.label = "treeEdge";
            edges.add(e);
            v.p = u;
            ExploreVertex(v, s);
        } else if (v.f == 0) {
            e.label = "backEdge";
            edges.add(e);
        } else if (v.d > u.d) {
            e.label = "forwardEdge";
            edges.add(e);
        } else {
            e.label = "crossEdge";
            edges.add(e);
        }
    }
    private List<Vertex> Sort() {
        List<Vertex> sortedVertices = new ArrayList<>();
        for (Vertex v : vertices.values())
            sortedVertices.add(v);
        Collections.sort(sortedVertices, new Comparator<Vertex>(){
            public int compare(Vertex v1, Vertex v2){
                if (v1.d > v2.d)
                    return 1;
                else if (v1.d < v2.d)
                    return -1;
                else
                    return 0;
            }
        });
        return sortedVertices;
    }
    public void DFSIterative() {
        Reset();
        Stack<Vertex> s = new Stack<>();
        for (Vertex v : vertices.values()) {
            if (!v.visited) {
                v.d = ++time;
                v.visited = true;
                s.push(v);
                while (!s.isEmpty()) {
                    Vertex u = s.peek();
                    s.pop();
                    boolean bFinished = true;
                    for (Vertex w : u.adj) {
                        if (!w.visited) {
                            w.visited = true;
                            w.d = ++time;
                            w.p = u;
                            s.push(w);
                            bFinished = false;
                            break;
                        }
                    }
                    if (bFinished) {
                        u.f = ++time;
                        if (u.p != null)
                            s.push(u.p);
                    }
                }
            }
        }
    }
    @Override
    public String toString() {
        String str = new String();
        List<Vertex> sortedVertices = Sort();
        for (Vertex v : Sort()) {
            str += v.toString();
        }
        for (Edge e : edges) {
            str += e.label + ":" + e.u.id + "," + e.v.id + '\n';
        }
        return str;
    }
}
public class DFS {
    public static void main(String[] args) {
        Graph g = new Graph();
        g.addVertex(new Vertex('A'));
        g.addVertex(new Vertex('B'));
        g.addVertex(new Vertex('C'));
        g.addVertex(new Vertex('D'));
        g.addVertex(new Vertex('E'));
        g.addVertex(new Vertex('F'));
        g.addVertex(new Vertex('G'));
        g.addVertex(new Vertex('H'));
        g.addVertex(new Vertex('I'));
        g.addEdge('A', 'D');
        g.addEdge('B', 'A');
        g.addEdge('B', 'G');
        g.addEdge('C', 'D');
        g.addEdge('C', 'G');
        g.addEdge('C', 'B');
        g.addEdge('D', 'B');
        g.addEdge('D', 'G');
        g.addEdge('D', 'F');
        g.addEdge('E', 'H');
        g.addEdge('F', 'C');
        g.addEdge('H', 'D');
        g.addEdge('H', 'E');
        g.addEdge('H', 'F');
        g.addEdge('I', 'E');
        g.addEdge('A', 'D');

        g.DFSReccur();
        System.out.println(g.toString());
        System.out.println("-----------------------------------------");
        g.DFSIterative();
        System.out.println(g.toString());
    }
}
