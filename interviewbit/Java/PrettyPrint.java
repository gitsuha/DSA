package com.suha.app;

import java.util.*;
import java.util.Scanner;

/*
 * 4 4 4 4 4 4 4
 * 4 3 3 3 3 3 4 
 * 4 3 2 2 2 3 4
 * 4 3 2 1 2 3 4
 * 4 3 2 2 2 3 4
 * 4 4 4 4 4 4 4
 * 
 * (0,0) (0,1) (0,2) (0,3) (0,4) (0,5) (0,6)
 * (1,0) (1,1) (1,2) (1,3) (1,4) (1,5) (1,6)
 * (2,0) (2,1) (2,2) (2,3) (2,4) (2,5) (2,6)
 * (3,0) (3,1) (3,2) (3,3) (3,4) (3,5) (3,6)
 * (4,0) (4,1) (4,2) (4,3) (4,4) (4,5) (4,6)
 * (5,0) (5,1) (5,2) (5,3) (5,4) (5,5) (5,6)
 * (6,0) (6,1) (6,2) (6,3) (6,4) (6,5) (6,6)
 * 
 * 1 2 3 4
 * 1 3 5 7
*/


class PrettyPrintSolution {
	
    public int[][] prettyPrint(int A) {

    	int d = 2*A - 1;
        int [][] m = new int[d][d];
        int dir = 0;
        int i = 0;
        while (A > 0)
        {
            if(dir==0){
                for (int j = i; j < d; j++)
                    m[i][j] = A;
                i++;
            }
            else if(dir==1){
            	for (int j = i; j < d; j++)
            		m[j][d - 1] = A;
            	i--;
            	d--;
            }
            else if(dir==2){
            	for (int j = i; j < d; j++)
            		m[d][j] = A;
            }
            else if(dir==3){
            	for (int j = i + 1; j < d; j++)
            		m[j][i] = A;
            	i++;
            }
            dir=(dir+1)%4;
            if (dir == 0)
            	A--;
        }
        
        return m;
    }
}

public class PrettyPrint {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		scn.close();
		
		PrettyPrintSolution s = new PrettyPrintSolution();
		int [][] m = s.prettyPrint(n);
		for (int i = 0; i < 2*n - 1; i++) {
			for (int j = 0; j < 2*n - 1; j++) {
				System.out.print(m[i][j] + " ");
			}
			System.out.print('\n');
		}
		
	}

}
