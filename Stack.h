
#ifndef STACK_H
#define STACK_H


template <typename T>

class Stack {
public:
	Stack(int n) {
		this->Table = new T[n];
		this->Top = -1;
	}

	bool Empty() {
		return Top < 0 ? true : false;
	}

	bool Full() {
		return this->Top == sizeof(Table) - 1 ? true : false;
	}

	void Push(T item) {
		if (Full()) {
			throw std::invalid_argument("The stack is full!!");
		}
		++this->Top;
		this->Table[Top] = item;
		std::cout << Top << std::endl;
	}

	void TOP() {
		if (Empty()) {
			throw std::invalid_argument("The stack is empty!!");
		}
		return this->Table[this->Top];
	}

	T Pop() {
		if (Empty()) {
			throw std::invalid_argument("The stack is empty!!");
		}

		T item = Table[Top];
		--this->Top;
		return item;
	}

	int Size() {
		return ++this->Top;
	}

private:
	int Top;
	T* Table;
};

#endif
