/*

Selection Sort
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

Following example explains the above steps:


arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.

*/
// C program for implementation of selection sort
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
// function to print an array
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

// make function to swap two numbers.


void swapTwoNums(int *px, int *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

void selectionSort(int a[], int n)
{
	int i, j, pos;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		pos = i;// find the minimum element in unsorted array
		for (j = i + 1; j < n; j++)
		{
			if (a[pos] > a[j])
				pos = j;
		}
		// swap the found minium element with the first element
		swapTwoNums(&a[i], &a[pos]);
	}
}

// driver program to test above functions
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
	selectionSort(a, SIZE_OF_ARRAY);
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


// C program for implementation of selection sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

/* Function to print an array */

// Driver program to test above functions
/*
Output:
Sorted array:
11 12 22 25 64
Time Complexity: O(n2) as there are two nested loops.

Auxiliary Space: O(1)
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.

Exercise :
Sort an array of strings using Selection Sort

Stability : The default implementation is not stable. However it can be made stable. Please see stable selection sort for details.

In Place : Yest, it does not require extra space.
*/