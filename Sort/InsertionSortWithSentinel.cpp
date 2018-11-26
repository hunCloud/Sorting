/*
Insertion Sort
Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
Algorithm
// Sort an arr[] of size n
insertionSort(arr, n)
Loop from i = 1 to n-1.
……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]

Example:


Another Example:
12, 11, 13, 5, 6

Let us loop for i = 1 (second element of the array) to 5 (Size of input array)

i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12
11, 12, 13, 5, 6

i = 2. 13 will remain at its position as all elements in A[0..I-1] are smaller than 13
11, 12, 13, 5, 6

i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position.
5, 11, 12, 13, 6

i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position.
5, 6, 11, 12, 13



Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
*/
// C program for insertion sort
#include <iostream>
#include <stdint.h>// to use int64_t
#define LOOP(i, n) for (int i = 0; i < n; i++) // defination about for loop
#include <time.h>// to use srand() and function rand()


#define MAXIMUM_NUMBER 244 // We can change max value in here
#define MINIMUM_NUMBER -233// change min value in here


// defination of the size of the array that need test..
#define SIZE_OF_ARRAY 42// can change the size in here
#define TIME_SLEEP .4 // Set time to sleep in here
#include <unistd.h> // to use sleep() function



void createArray(int arr[], int n)
{
	// we just use one function srand() to random numbers....

	// the argument pass on the srand() function is NULL value
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

// Function to sort an array using insertion sort
void insertionSortSentinel(int a[], int n)
{

	int i, j, key;
	for (i = n; i >= 1; i--)// examine from n down to 1
		a[i] = a[i - 1];// move every element up 1 unit.

	for (i = 2; i < n; i++)
	{
		key = a[i];
		a[0] = key;
		j = i - 1;
		/*
		Move elements of a[0..i-1], that are greater than key, to one position
		ahead of their current position.
		*/
		while (key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = key;
	}
}
// driver program to test insertion sort

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

	insertionSortSentinel(a, SIZE_OF_ARRAY);
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

Output:

5 6 11 12 13
Time Complexity: O(n*2)

Auxiliary Space: O(1)

Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.

Algorithmic Paradigm: Incremental Approach

Sorting In Place: Yes

Stable: Yes

Online: Yes

Uses: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

What is Binary Insertion Sort?
We can use binary search to reduce the number of comparisons in normal insertion sort. Binary Insertion Sort find use binary search to find the proper location to insert the selected item at each iteration. In normal insertion, sort it takes O(i) (at ith iteration) in worst case. we can reduce it to O(logi) by using binary search. The algorithm as a whole still has a running worst case running time of O(n2) because of the series of swaps required for each insertion. Refer this for implementation.

How to implement Insertion Sort for Linked List?
Below is simple insertion sort algorithm for linked list.

1) Create an empty sorted (or result) list
2) Traverse the given list, do following for every node.
......a) Insert current node in sorted way in sorted or result list.
3) Change head of given linked list to head of sorted (or result) list.
Refer this for implementation.
*/
