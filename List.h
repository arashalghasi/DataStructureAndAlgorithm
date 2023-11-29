#ifndef LIST_H
#define LIST_H



// Doubly Linked Array list


#include "Exception.h"

template <typename T>
class Node {
public:
	Node(T data) : _Key(data), _Prev(nullptr), _Next(nullptr) {}
	Node() : _Key(NULL), _Prev(nullptr), _Next(nullptr) {}
	

	Node<T>* _Prev;
	Node<T>* _Next;
	T _Key;
};

template <typename T>
class List {
public:

	List() {
		this->_Head = nullptr;
		this->_Tail = nullptr;
	}

	bool Empty() const {
		return _Head == nullptr;
	}

	T Head() {
		return this->_Head->_Key;
	}

	T Tail() {
		return this->_Tail->_Key;
	}

	void InsertFront(T item) {
		Node<T>* newNode = new Node<T>(item);
		newNode->_Next = this->_Head;
		newNode->_Prev = nullptr;
		if (Empty()) {
			this->_Tail = newNode;
			this->_Head = newNode;
		}
		else {
			this->_Head->_Prev = newNode;
			this->_Head = newNode;
		}
	}

	//void InsertFront(List<T> list) {
	//	List<T>* newList = &list;
	//	newNode->_Next = this->_Head;
	//	newNode->_Prev = nullptr;
	//	if (Empty()) {
	//		this->_Tail = newNode;
	//		this->_Head = newNode;
	//	}
	//	else {
	//		this->_Head->_Prev = newNode;
	//		this->_Head = newNode;
	//	}
	//}

	void InsertBack(T item) {
		Node<T>* newNode = new Node<T>(item);
		newNode->_Next = nullptr;
		newNode->_Prev = this->_Tail;
		if (Empty()) {
			this->_Tail = newNode;
			this->_Head = newNode;
		}
		else {
			this->_Tail->_Next = newNode;
			this->_Tail = newNode;
		}
	}


	bool Serach(T item) {
		Node<T>* node = ListSearch(item);
		return node == nullptr ? false : true;
	}


	T DeleteFront() {
		if (this ->_Head == nullptr) {
			throw ExceptionCustom ("The List is empty!");
		}
		else {
			T item = _Head->_Key;
			ListDelete(_Head);
			return item;
		}
	}

	T DeleteBack() {
		if (this ->_Tail == nullptr) {
			throw ExceptionCustom ("The List is empty!");
		}
		else {
			T item = this->_Tail->_Key;
			ListDelete(this->_Tail);
			return item;
		}
	}

	void Delete(T item) {
		Node<T>* node = ListSearch(item);
		if (node != nullptr) {
			ListDelete(node);
		}
	}
private:
	Node<T>* _Head;
	Node<T>* _Tail;

	void ListDelete(Node<T>* item)  {
		if (item->_Prev != nullptr) {
			item->_Prev->_Next = item->_Next;
		}
		else {
			this->_Head = item->_Next;
		}

		if (item->_Next != nullptr) {
			item->_Next->_Prev = item->_Prev;
		}
		else {
			this->_Tail = item->_Prev;
		}
	}

	Node<T>* ListSearch(T item) const {
		auto newNode = this->_Head;
		while (newNode != nullptr && newNode->_Key != item) {
			newNode = newNode->_Next;
		}
		return newNode;

	}
};

// Node class definition


#endif
