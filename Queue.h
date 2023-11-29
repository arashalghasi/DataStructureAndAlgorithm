#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
#include <stdexcept>


// this is a Circular Queue
class Queue {
public:
	Queue(int n) {
		this->_Size = n; // the queue can contain n cells and n-1 elements.
		Table = new T[n];
		this->_Tail = 0;
		this->_Head = 0;
	}

	bool Empty() {
		return this->_Head == this->_Tail ? true : false;
	}

	int Head() {
		return this->Table[this->_Head];
	}

	int Tail() {
		return this->Table[this->_Tail];
	}

	void EnQueue(T item) {
		if (((this->_Tail + 1) % this->_Size) != this->_Head) {
			this->Table[this->_Tail] = item;
			this->_Tail = ((this->_Tail + 1) % this->_Size);
		}
		else {
			throw std::invalid_argument("The Queue is Full");
		}
	}

	T DeQueue() {
		if (Empty()) {
			throw std::invalid_argument("The Queue is Empty!");
		}
		else {
			std::cout << this->_Head << std::endl;
			T tmp = this->Table[this->_Head];
			std::cout <<"I am here " << this->_Head << std::endl;

			this->_Head = ((this->_Head + 1) % this->_Size);
			std::cout << "I am here after " << this->_Head << std::endl;
			return tmp;

		}
	}
private:
	int _Head, _Tail, _Size;
	T* Table;
};
#endif