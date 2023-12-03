#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstddef>
#include  "Exception.h"

class NodeTree
{
public:
	NodeTree() : Left(nullptr), Right(nullptr), Data(NULL) {}
	NodeTree(int value) : Left(nullptr), Right(nullptr), Data(value) {}
	NodeTree* Left;
	NodeTree* Right;
	int Data;
};
/*
 *@brief: The binary search tree
 **/
class BST
{
public:
	BST() :Root(nullptr) {}
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
		NodeTree* NewNode = new NodeTree(value);
		NodeTree* tmp = this->Root;
		if (tmp == nullptr)
		{
			this->Root = NewNode;
		}
		else {
			while (tmp != nullptr) {

				if (NewNode->Data == tmp->Data)
				{
					throw ExceptionCustom("No duplication is allowded!");
				}
				else if (tmp->Data < NewNode->Data && tmp->Right == nullptr)
				{
					tmp->Right = NewNode; break;
				}
				else if (tmp->Data < NewNode->Data)
				{
					tmp = tmp->Right;
				}
				else if (tmp->Data > NewNode->Data && tmp->Left == nullptr)
				{
					tmp->Left = NewNode; break;
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


	NodeTree* IterativeSearch(int value)
	{
		if (this->Root == nullptr)
		{
			return this->Root;
		} else
		{
			NodeTree* temp = this->Root;
			while(temp != nullptr)
			{
				if(temp->Data == value)
				{
					return temp;
				} else if(temp->Data < value)
				{
					temp = temp->Right;
				} else
				{
					temp = temp->Left;
				}
			}
		}

		return nullptr;

	}

	NodeTree* Root;

private:

	//node-left-right
	void PrintPreOrderInside(NodeTree* node)
	{
		if (node == nullptr)
		{
			return;

		}
		std::cout << node->Data << std::endl;
		PrintPreOrderInside(node->Left);
		PrintPreOrderInside(node->Right);
	}

	void PrintInOrderInside(NodeTree* node)
	{
		if (node == nullptr)
		{
			return;

		}
		PrintPreOrderInside(node->Left);
		std::cout << node->Data << std::endl;
		PrintPreOrderInside(node->Right);
	}


	void PrintPostOrderInside(NodeTree* node)
	{
		if (node == nullptr)
		{
			return;

		}
		PrintPreOrderInside(node->Left);
		PrintPreOrderInside(node->Right);
		std::cout << node->Data << std::endl;
	}


};
#endif

