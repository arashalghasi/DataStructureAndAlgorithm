#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstddef>
#include "Exception.h"

class NodeTree
{
public:
	NodeTree() : Left(nullptr), Right(nullptr), Data(NULL) {}
	NodeTree(int value) : Left(nullptr), Right(nullptr), Data(value) {}
	NodeTree *Left;
	NodeTree *Right;
	int Data;
};

/**
 * @brief: The binary search tree
 */
class BST
{
public:
	BST() : Root(nullptr) {}

	bool Empty()
	{
		if (this->Root == nullptr)
		{
			return true;
		}
		return false;
	}

	void InsertNode(int value)
	{
		NodeTree *NewNode = new NodeTree(value);
		NodeTree *tmp = this->Root;
		if (tmp == nullptr)
		{
			this->Root = NewNode;
		}
		else
		{
			while (tmp != nullptr)
			{

				if (NewNode->Data == tmp->Data)
				{
					throw ExceptionCustom("No duplication is allowded!");
				}
				else if (tmp->Data < NewNode->Data && tmp->Right == nullptr)
				{
					tmp->Right = NewNode;
					break;
				}
				else if (tmp->Data < NewNode->Data)
				{
					tmp = tmp->Right;
				}
				else if (tmp->Data > NewNode->Data && tmp->Left == nullptr)
				{
					tmp->Left = NewNode;
					break;
				}
				else if (tmp->Data > NewNode->Data)
				{
					tmp = tmp->Left;
				}
			}
		}
	}

	void PrintPreOrder()
	{
		PrintPreOrderInside(this->Root);
	}
	void PrintInOrder()
	{
		PrintInOrderInside(this->Root);
	}

	void PrintPostOrder()
	{
		PrintPostOrderInside(this->Root);
	}

	NodeTree *IterativeSearch(int value)
	{
		if (this->Root == nullptr)
		{
			return this->Root;
		}
		else
		{
			NodeTree *temp = this->Root;
			while (temp != nullptr)
			{
				if (temp->Data == value)
				{
					return temp;
				}
				else if (temp->Data < value)
				{
					temp = temp->Right;
				}
				else
				{
					temp = temp->Left;
				}
			}
		}

		return nullptr;
	}

	NodeTree *RecursiveSearch(NodeTree *node, int value)
	{
		if (node == nullptr || node->Data == value)
		{
			return node;
		}
		else if (node->Data > value)
		{
			RecursiveSearch(node->Left, value);
		}
		else
		{
			RecursiveSearch(node->Right, value);
		}
	}

	int Height(NodeTree *node)
	{
		if (node == nullptr)
		{
			return -1;
		}
		else
		{
			int lheight = Height(node->Left);
			int rheight = Height(node->Right);
			if (lheight > rheight)
			{
				return (lheight + 1);
			}
			else if (lheight < rheight)
			{

				return (rheight + 1);
			}
			else
			{
				return lheight;
			}
		}
	}

	void PrintLevelOrderBFS(NodeTree *node)
	{
		int height = Height(node);
		for (int level = 0; level <= height; level++)
		{
			PrintGivenLevel(node, level);
		}
	}

	NodeTree *DeleteNode(NodeTree *node, int value)
	{
		if (node == nullptr)
		{
			return node;
		}
		else if (node->Data > value)
		{
			DeleteNode(node->Left, value);
		}
		else if (node->Data < value)
		{
			DeleteNode(node->Right, value);
		}
		else // If value matches
		{
			if (node->Left == nullptr) // Node with only right child or no child
			{
				NodeTree *temp = node->Right;
				delete (node);
				return temp;
			}
			else if (node->Right == nullptr) // Node with only left child or no child
			{
				NodeTree *temp = node->Left;
				delete (node);
				return temp;
			}
			else // node wth two child
			{
				NodeTree *temp = minValueNode(node->Right);
				node->Data = temp->Data;
				node->Right = DeleteNode(node->Right, temp->Data);
			}
		}
		return node;
	}

	NodeTree *minValueNode(NodeTree *node)
	{
		NodeTree *current = node;
		while (current->Left != nullptr)
		{
			current = current->Left;
		}
		return current;
	}

	NodeTree *InsertRecursive(NodeTree *&node, int value)
	{
		NodeTree *NewNode = new NodeTree(value);
		if (node == nullptr)
		{
			node = NewNode;
			return node;
		}
		else if (node->Data < value)
		{
			node->Right = InsertRecursive(node->Right, value);
		}
		else if (node->Data > value)
		{
			node->Left = InsertRecursive(node->Left, value);
		}
		else
		{
			throw ExceptionCustom("No duplication is allowded!");
		}

		int balancedFactro = gerBalacedFactor(node);
		if (balancedFactro > 1 && value < node->Left->Data)
		{
			return RightRotation(node);
		}
		else if (balancedFactro < -1 && value > node->Right->Data)
		{
			return LeftRotation(node);
		}
		else if (balancedFactro > 1 && value > node->Right->Data)
		{
			node->Left = LeftRotation(node->Left);
			return RightRotation(node);
		}
		else if (balancedFactro < -1 && value < node->Right->Data)
		{
			node->Right = RightRotation(node->Right);
			return LeftRotation(node);
		}

		return node;
	}

	// AVL tree deleteNode with re-balancing
	NodeTree *DeleteNodeAvl(NodeTree *node, int value)
	{
		if (node == nullptr)
		{
			return node;
		}
		else if (value < node->Data)
		{
			DeleteNode(node->Left, value);
		}
		else if (value > node->Data)
		{
			DeleteNode(node->Right, value);
		}
		else // At this point we find the value
		{
			if (node->Left == nullptr) // Node with just right children
			{
				NodeTree *temp = node->Right;
				delete node;
				return temp;
			}
			else if (node->Right == nullptr) // Node with just left children
			{
				NodeTree *temp = node->Left;
				delete node;
				return temp;
			}
			else // node with two children
			{
				NodeTree *temp = minValueNode(node->Right);
				node->Data = temp->Data;
				node->Right = DeleteNode(node->Right, temp->Data);
			}
		}

		int balanceFactor = gerBalacedFactor(node);

		if (balanceFactor == 2 && gerBalacedFactor(node->Left) >= 0)
		{
			return RightRotation(node);
		}
		else if (balanceFactor == 2 && gerBalacedFactor(node->Left) == -1)
		{
			node->Left = LeftRotation(node->Left);
			return RightRotation(node);
		}
		else if (balanceFactor == -2 && gerBalacedFactor(node->Right) <= 0)
		{
			return LeftRotation(node);
		}
		else if (balanceFactor == -2 && gerBalacedFactor(node->Right) == 1)
		{
			node->Right = RightRotation(node->Right);
			LeftRotation(node);
		}

		return node;
	}

	void print2D(NodeTree *node, int space)
	{
		if (node == nullptr) // Base case  1
			return;
		space += 10;				 // Increase distance between levels   2
		print2D(node->Right, space); // Process right child first 3
		std::cout << std::endl;
		for (int i = 10; i < space; i++) // 5
			std::cout << " ";			 // 5.1
		std::cout << node->Data << "\n"; // 6
		print2D(node->Left, space);		 // Process left child  7
	}
	NodeTree *Root;

private:
	// node-left-right
	void PrintPreOrderInside(NodeTree *node)
	{
		if (node == nullptr)
		{
			return;
		}
		std::cout << node->Data << std::endl;
		PrintPreOrderInside(node->Left);
		PrintPreOrderInside(node->Right);
	}

	void PrintInOrderInside(NodeTree *node)
	{
		if (node == nullptr)
		{
			return;
		}
		PrintPreOrderInside(node->Left);
		std::cout << node->Data << std::endl;
		PrintPreOrderInside(node->Right);
	}

	void PrintPostOrderInside(NodeTree *node)
	{
		if (node == nullptr)
		{
			return;
		}
		PrintPreOrderInside(node->Left);
		PrintPreOrderInside(node->Right);
		std::cout << node->Data << std::endl;
	}

	void PrintGivenLevel(NodeTree *node, int level)
	{
		if (node == nullptr)
		{
			return;
		}
		else if (level == 0)
		{
			std::cout << node->Data << std::endl;
		}
		else
		{
			PrintGivenLevel(node->Left, level - 1);
			PrintGivenLevel(node->Right, level - 1);
		}
	}

	int gerBalacedFactor(NodeTree *node)
	{
		if (node == nullptr)
		{
			return -1;
		}
		else
		{
			return (Height(node->Left) - Height(node->Right));
		}
	}

	NodeTree *RightRotation(NodeTree *node)
	{
		NodeTree *x = node->Left;
		NodeTree *T2 = x->Right;

		// We preform the rotation
		x->Right = node;
		node->Left = T2;
		return x;
	}

	NodeTree *LeftRotation(NodeTree *node)
	{
		NodeTree *x = node->Right;
		NodeTree *T2 = x->Left;
		// Performing ther rotation
		x->Left = node;
		node->Right = T2;
		return x;
	}
};

class Heap
{

public:
	Heap()
	{
		this->Table = nullptr;
		this->Size = 0;
	}

	/**
	 * @brief
	 * The algorithm to build max heap and the efficiency of it is O(n)
	 */
	void *BuildMaxHeap(int A[], int size)
	{
		this->Size = size;
		this->Table = new int[size + 1];

		for (int j = 0; j < size; j++)
		{
			this->Table[j + 1] = A[j];
			// std::cout << heap->Table[j+1] << " index is: "<< j+ 1<<  " :" << A[j] << std::endl;
		}
		// we check the half of the size of the table because the half of the table are the leaf and they are automatically right
		for (int i = this->Size / 2; i > 0; i--)
		{
			HeapSink(i);
		}

		this->maxHeap = true;
	}

	int Left(int node)
	{
		return node * 2;
	}

	int Right(int node)
	{
		return (node * 2) + 1;
	}

	int Parent(int node)
	{
		return node / 2;
	}

	int getMax()
	{
		if (this->maxHeap)
		{
			return Table[1];
		}
		else
		{
			throw ExceptionCustom("The heap is not a max heap!");
		}
	}

	int getMin()
	{
		if (!this->maxHeap)
		{
			return this->Table[1];
		}
		else
		{
			throw ExceptionCustom("The heap is not a min heap!");
		}
	}

	void getType()
	{
		if (this->maxHeap)
		{
			std::cout << "It is a max heap" << std::endl;
		}
		else
		{
			std::cout << "It is a min heap" << std::endl;
		}
	}

	/**
	 * @brief
	 * The algorithm to balance the binary heap in case of violation of on node, the efficiency of it is O(logn)
	 */
	void HeapSink(int errorNode)
	{
		int container;
		int size = this->Size;
		int left = Left(errorNode);
		int right = Right(errorNode);
		if (left <= size && this->Table[left] > this->Table[errorNode])
		{
			container = left;
		}
		else
		{
			container = errorNode;
		}

		if (right <= size && this->Table[right] > this->Table[container])
		{
			container = right;
		}

		if (container != errorNode)
		{
			Swap(this->Table, errorNode, container);
			HeapSink(container);
		}
	}

	void PrintTable()
	{
		std::cout << std::endl;
		for (int i = 1; i < this->Size + 1; i++)
		{
			std::cout << this->Table[i] << " ";
		}
		std::cout << std::endl;
	}

	int *Table;
	int Size;	  // Maximum number of elements in heap
	int heapSize; // current number of elements in heap
	bool maxHeap;

private:
	void Swap(int A[], const int i, const int j)
	{
		const int Container = A[i];
		A[i] = A[j];
		A[j] = Container;
	}
};
#endif
