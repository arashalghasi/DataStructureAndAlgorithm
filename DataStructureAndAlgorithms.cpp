#include <stdexcept>
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "List.h"
#include "Exception.h"
#include "Graph.h"
#include <chrono>
#include <random>
#include "SearchAlgorithms.h"
#include "SortAlgorithms.h"
#include "BinaryTree.h"
#include "TransformAndConquer.h"

int main()
{

	try
	{
		int numArr3[] = {10, 2, 3, 22, 5, 6, 1, 1, 13, 4, 4, 4};
		const int size  = sizeof(numArr3)/sizeof(numArr3[0]);
		Heap* heap = new Heap();
		heap->BuildMaxHeap(numArr3,size);
		SortAlgorithms::HeapSort(numArr3,size);
		for (auto ele : numArr3){
			std::cout << ele << " ";
		}
	}
	catch (const ExceptionCustom &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
