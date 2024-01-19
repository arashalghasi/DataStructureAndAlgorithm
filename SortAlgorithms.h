#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H
#include "BinaryTree.h"

class SortAlgorithms
{
public:


	/**
	* @brief
	* The The Quick Sort is a sort with O(nlog(n)) time complexity and the space complexity O(n) and is one of the most efficient sorting algorithms
	*/
	static void QuickSort3Way(int A[], int low, int high)
	{
		if (high <= low )
		{
			return;
		}
		int lt = low; //less than part
		int gt = high; // greater than part
		int i = low + 1;
		int v = A[low];
		while (i <= gt)
		{
			if (A[i] < v)
			{
				Swap(A, lt, i);
				++lt;
				++i;

			}
			else if (A[i] > v)
			{
				Swap(A, i, gt);
				--gt;
			}
			else
			{
				++i;
			}
		}
		QuickSort3Way(A, low, lt - 1);
		QuickSort3Way(A, gt + 1, high);
	}

	/**
	* @brief
	* The The heap Sort is a sort with the efficiency of O(nlogn)
	*/
	static void HeapSort(int item[], const int size){
		Heap* heap = new Heap();
		heap->BuildMaxHeap(item, size);
		for (int i = size; i > 0; i--){
			item[i-1] = heap->Table[1];
			Swap(heap->Table,1,i);
			heap->Size -= 1;
			//heap->BuildMaxHeap(heap->Table,i);
			heap->HeapSink(1);
		}
	}

	/**
	* @brief
	* The The Quick Sort is a sort with O(nlog(n)) time complexity and the space complexity O(n) and is one of the most efficient sorting algorithms
	*/
	static void QuickSort(int item[], const int low, const int high ) {
		if (low < high) {
			const int pivot = PartitionRnd(item, low, high);
			QuickSort(item, low, pivot - 1);
			QuickSort(item, pivot + 1, high);

		}
	}



	/**
	* @brief
	* The Optimized Merge Sort is a sort with O(n) time complexity and is one of the most efficient sorting algorithms
	*/

	static void OptMergeSort(int A[], const int sizeOfA) {
		int* B = new int[sizeOfA];
		MergeSortRec(A, B, 0, sizeOfA - 1);
	}


	/**
	* @brief
	* The Merge Sort is a sort with O(nlog(n))  time complexity and is one of the most efficient sorting algorithms
	*/ 
	static void MergeSort(int A[], const int size) {
		if (size > 1) {
			int sizeOfB = size / 2;
			int sizeOfC = size - (size / 2);
			int* B = new int[sizeOfB]; // int* B = new int(sizeOfB); the difference is the first one you create a dynamic array with the size of sizeOfB but the second one you create a dynamci array and instantiate it by the an integer sizeOfB
			int* C = new int[sizeOfC];
			CopyMergeSort(A, B, 0, (size / 2) -1 );
			CopyMergeSort(A, C, (size / 2), size - 1);
			MergeSort(B, sizeOfB);
			MergeSort(C, sizeOfC);
			Merge(B, C, A, sizeOfB, sizeOfC);
			delete[] B;
			delete[] C;
		}
	}

	/**
	* @brief
	* The insertion Sort is a sort with O(n^2)  time complexity
	*/
	static void InsertionSort(int A[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			int element = A[i];
			int j = i - 1;
			while (j >= 0 && A[j] > element)
			{
				A[j + 1] = A[j];
				--j;
			}
			A[j + 1] = element;
		}
	}

	/**
	 *@brief The selectionSort is a sort algorithm with the complexity of O(n^2)
	 */
	static void SelectionSort(int A[], int size)
	{
		for (int i = 0; i < size -1; i++)
		{
			int min = i;
			for (int j = i + 1; j < size ; j++)
			{
				if (A[j] < A[min])
				{
					min = j;
				}
			}

			if (min != i)
			{
				int container = A[i];
				A[i] = A[min];
				A[min] = container;

			}
		}

	}

	/**
	*@brief
	*The Bubble Sort is a sort with O(n^2)  time complexity
	*/

	static void BubbleSort(int A[], int size)
	{
		for ( int i = 0; i < size ; i++)
		{
			for (int j = 0; j < size - i - 1; j++) {
				if (A[j] > A[j + 1])
				{
					int container = A[j + 1];
					A[j + 1] = A[j];
					A[j] = container;
				}
			}
		}
	}

	/**
*@brief
*The Optimized Bubble Sort is a sort with O(n^2)  time complexity
*/

	static void OptimizedBubbleSort(int A[], int size)
	{
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i - 1; j++) {
				if (A[j] > A[j + 1])
				{
					flag = true;
					int container = A[j + 1];
					A[j + 1] = A[j];
					A[j] = container;
				}
			}
			if (!flag) break;
		}
	}



private:

	static void Swap(int A[], const int i, const int j) {
		const int Container = A[i];
		A[i] = A[j];
		A[j] = Container;
	}


	static int Partition(int A[], const int low, const int high) {
		const int pivot = A[high]; //The arbitrary choice 
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (A[j] <= pivot) {
				++i;
				Swap(A, i, j);
			}
		}
		Swap(A, i + 1, high);
		return i + 1;

	}

	static int PartitionRnd(int A[], int low, int high)
	{
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(low, high); // define the range

		int pivotRnd = distr(gen);
		Swap(A, pivotRnd, high);
		return Partition(A, low, high);
	}

	static void MergeSortRec(int A[], int B[], const int low, const int high) {
		if (high > low) {
			const int mid = low + ((high - low) / 2);
			MergeSortRec(A, B, low, mid);
			MergeSortRec(A, B, mid + 1, high);
			OptMerge(A, B, low, mid, high);
		}
	}

	static void OptMerge(int A[], int B[], const int low, const int mid, const int high) {
		for (int k = low; k <= high; k++) {
			B[k] = A[k];
		}

		int i = low;
		int j = mid + 1;
		for (int k = low; k <= high; k++) {
			if (i > mid) {
				A[k] = B[j];
				++j;
			}
			else if (j > high) {
				A[k] = B[i];
				++i;
			}
			else if (B[j] < B[i]) {
				A[k] = B[j];
				++j;
			}
			else {
				A[k] = B[i];
				++i;
			}
		}
	}

	static void CopyMergeSort(int A[], int B[],  int first,  int last) {
		int j = 0;
		for (int i = first; i <= last; i++) {
			B[j] = A[i];
			++j;
		}
	}

	static void Merge(int B[], int C[], int A[],  int sizeOfB,  int sizeOfC) {
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < sizeOfB && j < sizeOfC) {
			if (B[i] <= C[j]) {
				A[k] = B[i];
				++i;
			}
			else {
				A[k] = C[j];
				++j;
			}

			++k;
		}
		// at this point means the array of B is finished
		if (i == sizeOfB) {
			while (j < sizeOfC) {
				A[k] = C[j];
				++j;
				++k;
			}
		} // at this point means the array of C is finished and we must just merge the rest of the array of B
		else {
			while (i < sizeOfB) {
				A[k] = B[i];
				++i;
				++k;
			}
		}
	}

};
#endif
