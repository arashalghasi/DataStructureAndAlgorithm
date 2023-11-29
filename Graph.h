#ifndef GRAPH_H
#define GRAPH_H
#include "Exception.h"
class GraphMatrix {
public:
	GraphMatrix() {
		this->matrix = nullptr;
		this->_Size = NULL;
		throw ExceptionCustom("Please specify the size of the graph.");
	}
	GraphMatrix(int size) {
		this->_Size = size;
		matrix = new int* [size];
		for (int i = 0; i < size  ; i++) {
			matrix[i] = new int[size];
		}

		for (int i = 0; i < size  ; i++) {
			for (int j = 0; j < size ; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	void PrintGraph() const {
		for (int i = 0; i < this->_Size ; i++) {
			for (int j = 0; j < this->_Size; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}


	void Link(int node1, int node2) {
		matrix[node1][node2] = 1;
		matrix[node2][node1] = 1;
	}


	void UnLink(int node1, int node2) {
		matrix[node1][node2] = 0;
		matrix[node2][node1] = 0;
	}

	bool AreLinked(int node1, int node2) {
		return matrix[node1][node2] == 1 ? true : false;
	}

private:
	int** matrix;
	int _Size;
};
#endif 
