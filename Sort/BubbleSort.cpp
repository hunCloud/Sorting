/*

Bubble Sort
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Example:
First Pass:
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

Third Pass:
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )



Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
Following is the implementations of Bubble Sort.

*/





// C program for bubble sort
#include <iostream>
#include <stdint.h>// to use int64_t
#define LOOP(i, n) for (int i = 0; i < n; i++) // defination about for loop
#include <time.h>// to use srand() and function rand()


#define MAXIMUM_NUMBER 244 // We can change max value in here
#define MINIMUM_NUMBER -233// change min value in here


// defination of the size of the array that need test..
#define SIZE_OF_ARRAY 42// can cahnge the size in here
#define TIME_SLEEP .4 // Set time to sleep in here
#include <unistd.h> // to use sleep() function



void createArray(int arr[], int n)
{
	// we just use one function srand to random numbers....

	// the argument pass on the srand function is NULL value
	// And convert the value its return to unsigned int type
	srand((unsigned int)time(NULL));

	LOOP(i, n)
	{	// random value from MINIMUM to MAXIMUM
		arr[i] = MINIMUM_NUMBER + rand() % (MAXIMUM_NUMBER - MINIMUM_NUMBER + 1);
	}
}
// A utility function to print an array of size n
void printArray(int a[], int n)
{
	//do not need declare namespace std
	LOOP(i, n)
	{
		std::cout << a[i] << '\t';
	}
	std::cout << std::endl;
	// std::cout
}
//... Test linear search algorithm

// A function to implement bubble sort
void bubbleSort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n - 1; i++)
	{
		for (j = n - 1; j >= i; j--)
		{
			if (a[j - 1] > a[j])
				std::swap(a[j - 1], a[j]);
		}
	}
}
// driver program to test bubble sort

int main(int argc, char const *argv[])
{

	//declare and initialize the size of array
	int a[SIZE_OF_ARRAY];
	// pass array variable in createArray dunction

	//sleep 2 seconds to fresh srand() fucntion....
	// include unix standard to use sleep() fucntion.

	std::cout << "wating for " << TIME_SLEEP << " seconds\n"; // to announce wating for 2 seconds
	//sleep(TIME_SLEEP);

	createArray(a, SIZE_OF_ARRAY);
	// print all elements in this array that just made
	bubbleSort(a, SIZE_OF_ARRAY);
	//after sort the array.
	printArray(a, SIZE_OF_ARRAY);
	// pass array in the linearSearch function
	/*	idex = linearSearch(a, SIZE_OF_ARRAY, x);
		// after search
		if (idex < 0)
			std::cout << "The value that search is INVALID in this array.\n";
		else
			std::cout << "The value that search is PRESENT in this array at " << idex << " index.\n";
	*/
	// to use excute out file that won't break
	system("pause");

	return 0;
}

/*

Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

Auxiliary Space: O(1)

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Sorting In Place: Yes

Stable: Yes

Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.
In computer graphics it is popular for its capability to detect a very small error (like swap of just
two elements) in almost-sorted arrays and fix it with just linear complexity (2n).
For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate
at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements
are swapped) only at intersections of two lines (Source: Wikipedia)
*/