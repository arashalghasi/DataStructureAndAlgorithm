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
		tree->InsertRecursive(tree->Root, 20);
		tree->InsertRecursive(tree->Root, 25);
		tree->InsertRecursive(tree->Root, 40);
		tree->PrintLevelOrderBFS(tree->Root);
		tree->print2D(tree->Root, 10);
		tree->InsertRecursive(tree->Root, 10);
		tree->InsertRecursive(tree->Root, 30);
		//tree->InsertNode(20);
		//tree->InsertNode(25);
		//tree->InsertNode(40);
		//tree->InsertNode(10);
		//tree->InsertNode(30);
		tree->PrintLevelOrderBFS(tree->Root);
		tree->print2D(tree->Root, 10);

	}
	catch (const ExceptionCustom& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}



