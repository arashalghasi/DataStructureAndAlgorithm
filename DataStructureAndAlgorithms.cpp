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


int main()
{

	try {
		int arraynot_sorted5[] = { 1,5,3,2,4,0,0,1,3,3,4,6,2,2,5,6,2 };
		SortAlgorithms::QuickSort3Way(arraynot_sorted5, 0, std::size(arraynot_sorted5)-1);
		for (int i : arraynot_sorted5)
		{
			std::cout << i << " ";
		}
	}
	catch (const ExceptionCustom& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}



