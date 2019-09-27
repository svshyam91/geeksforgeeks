/* GeeksForGeeks - Spirally traversing the matrix 
	Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0
	Author: Shyam Kumar
	Date: 14th March, 2019
*/

import java.util.Scanner;

class Spiral_traverse {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int rows, cols, i, j;

		int t = sc.nextInt();
		while(t > 0) {
			rows = sc.nextInt();
			cols = sc.nextInt();

			int arr[][] = new int[rows][cols];

			for( i = 0; i < rows; i++ ){
				for( j = 0; j < cols; j++ ) {
					arr[i][j] = sc.nextInt();
				}
			}
			spirally_traverse( rows, cols, arr );
			System.out.println();
			t--;
		}
	}

	static void spirally_traverse( int rows, int cols, int arr[][] ) {
		int i, j, s;
		s = 0;
		while( (s < cols) && (s < rows) ) {
			print_border( rows, cols, s, arr );
			rows--;
			cols--;
			s++;
		}
	}

	static void print_border( int rows, int cols, int s, int arr[][] ) {

		int i, j;
		for( i = s; i < cols; i++ ) 
			System.out.print(arr[s][i]+" ");

		for( j = s+1; j < rows; j++ ) 
			System.out.print(arr[j][cols-1]+" ");
		
		if( s != rows-1 ) {
			for( i = cols-2; i >= s; i-- ) 
				System.out.print(arr[rows-1][i]+" ");
		}

		if( s != cols-1 ) {
			for( j = rows-2; j > s; j-- )
				System.out.print(arr[j][s]+" ");
		}
	}
}