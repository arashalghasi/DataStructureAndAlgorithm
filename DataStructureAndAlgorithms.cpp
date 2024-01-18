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
		int numArr3[] = {1, 2, 3, 4, 5, 6, 1, 1, 4, 4, 4, 4};
		const int size  = sizeof(numArr3)/sizeof(numArr3[0]);
		int* numArr = SortAlgorithms::HeapSort(numArr3,size);
		const int size2  = sizeof(numArr)/sizeof(numArr[0]);
		for (int i = 0; i < 12; i++){
			std::cout << numArr[i] << std::endl;
		}
	}
	catch (const ExceptionCustom &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
