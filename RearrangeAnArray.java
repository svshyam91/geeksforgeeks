import java.util.Scanner;

class RearrangeAnArray {
	public static void main(String[] args) {
		RearrangeAnArray ob = new RearrangeAnArray();
		int t, n, i;
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the number of test cases: ");
		t = sc.nextInt();

		while( t != 0) {
			System.out.println("Enter the size of array: ");
			n = sc.nextInt();
			int[] arr = new int[n];

			System.out.println("Enter the array: ");
			for( i = 0; i < n; i++ ) {
				arr[i] = sc.nextInt();
			}

			ob.rearrangeAnArray( arr, n );

			t--;
		}
		sc.close();
	}

	void rearrangeAnArray( int[] arr, int n ) {
		int next = 0, temp, i;
		temp = arr[0];
		while( next != 0 ) {
			if( arr[next] == 0 ) {
				arr[next] = temp;
				System.out.printf("arr[%d] = %d", arr[next], temp);
			}
			else {
				arr[next] = arr[arr[next]];
				System.out.printf("arr[%d] = %d", arr[next], arr[arr[next]]);
			}
			next = arr[next];
		}
		//Printing the array
		for( i = 0; i < n; i++ ) {
			System.out.print(arr[i]+" ");
		}
	}
}