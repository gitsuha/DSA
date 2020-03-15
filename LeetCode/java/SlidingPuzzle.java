package com.suha.dsa;

import java.util.*;

class Board {
    int [][] board;
    int ox, oy;
    int move;
    Board (int [][] board, int ox, int oy, int move) {
        this.board = board;
        this.ox = ox;
        this.oy = oy;
        this.move = move;
    }
}
class Solution {
    private int[][] swap(int[][] board, int x, int y, int x1, int y1) {
        int [][] newBoard = new int[2][3];
        for (int i = 0; i < 2; i++) {
            System.arraycopy(board[i], 0, newBoard[i], 0, board[i].length);
        }
        int temp = newBoard[x1][y1];
        newBoard[x][y] = newBoard[x1][y1];
        newBoard[x1][y1] = 0;
        return newBoard;
    }
    private boolean validMove(int x, int y) {
        if (x < 0 || y < 0 || x > 1 || y > 2) return false;
        return true;
    }
    public int slidingPuzzle(int[][] board) {
        Queue<Board> q = new LinkedList<>();
        Set<String> s = new HashSet<>();
        s.add(Arrays.deepToString(board));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    q.offer(new Board(board, i, j, 0));
                    break;
                }
            }
        }
        int [][] solved = new int[][]{{1, 2, 3}, {4, 5, 0}};
        int [] dirx = {1, -1, 0, 0};
        int [] diry = {0, 0, 1, -1};
        while (!q.isEmpty()) {
            Board b = q.poll();
            if (Arrays.deepEquals(b.board, solved)) return b.move;
            for (int i = 0; i < 4; i++) {
                int x = b.ox + dirx[i];
                int y = b.oy + diry[i];
                if (validMove(x, y)) {
                    int [][] newBoard = swap(b.board, b.ox, b.oy, x, y);
                    if (!s.contains(Arrays.deepToString(newBoard))) {
                        q.offer(new Board(newBoard, x, y, b.move + 1));
                        s.add(Arrays.deepToString(newBoard));
                    }
                }
            }
        }
        return -1;
    }
}

public class Test {

    public static void main(String[] args) {
        int [][] board = {{1,2,3},{5,4,0}};
        Solution s = new Solution();
        System.out.println(s.slidingPuzzle(board));
    }
}
