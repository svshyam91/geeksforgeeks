import java.util.Scanner;

public class RotateAndDelete{

	static int n;

	public static void main(String[] args) {

		int t, i, ans;
		
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the number of test cases: ");
		t = sc.nextInt();

		while( t!=0 ) {
			System.out.println("Enter the value of n: ");
			n = sc.nextInt();

			// Declaring array
			int arr[] = new int[n];

			// Input array
			System.out.println("Enter the array: ");
			for( i = 0; i < n; i++ ) {
				arr[i] = sc.nextInt();
			}

			ans = rotateAndDelete( arr, n );
			System.out.println("Answer: "+ans);
			t--;
		}
	}

	static int rotateAndDelete( int arr[], int n ) {

		int N = n, j, l, i;

		for( j = 1; j <= N-1; j++ ) {
			rotate( arr, n );

			printArray( arr, n );

			l = N-j+1;
			i = n-l;

			delete( arr, n, i );
			n = n - 1;
		}
		return arr[0];
	}

	static void rotate( int arr[], int n ) {
		int temp, i;

		temp = arr[n-1];
		for( i = n-1; i > 0; i-- ) {
			arr[i] = arr[i-1];
		}
		arr[0] = temp;
	}

	static void delete( int arr[], int n, int d ) {
		int i; 
		i = d;
		while( i < n-1 ) {
			arr[i] = arr[i+1];
			i++;
		}
		arr[n-1] = 0;
	}

	static void printArray( int arr[], int n ) {
		int i;
		System.out.println();
		for( i = 0; i < n; i++ )
			System.out.print(arr[i]+" ");
	}

}