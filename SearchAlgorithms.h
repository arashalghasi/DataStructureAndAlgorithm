#ifndef SEARCHALGORITHM_H
#define SEARCHALGORITHM_H
#include <iostream>
class SearchAlgorithms
{
public:
	/**
	* @brief
	* The linear search that search the array for the desired item
	*/
	static void LinearSearch(int arr[], const int size, const int item) {
		bool result = false;
		for (int i = 0; i < size; i++) {
			if (item == arr[i]) {
				std::cout << "item found at location: " << i << std::endl;
				result = true;
			}
		}
		if (!result) {
			std::cout << "item does not found" << std::endl;
		}
	}

	/**
	 * @brief
	 * The binary search that returns the index of desired item passed to it if exists and if not return -1
	 */
	static int BinarySearch(int arr[], int size, const int item) {
		int left = 0;
		int right = size - 1;
		while (left <= right) {
			const int mid = left + (right - left) / 2;
			if (arr[mid] == item) {
				return mid;
			}
			else if (arr[mid] < item) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}

		}

		return -1;
	}
};
#endif
