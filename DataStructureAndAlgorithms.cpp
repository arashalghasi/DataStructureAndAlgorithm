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


int main()
{

	try {
		BST* tree = new BST();
		tree->InsertNode(30);
		tree->InsertNode(18);
		tree->InsertNode(10);
		tree->InsertNode(25);
		tree->InsertNode(43);
		tree->InsertNode(32);
		tree->InsertNode(48);
		tree->PrintPreOrder();
		std::cout << std::endl;
		tree->PrintInOrder();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << tree->IterativeSearch(60) << std::endl;
		std::cout << tree->IterativeSearch(25) << std::endl;
	}
	catch (const ExceptionCustom& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}



