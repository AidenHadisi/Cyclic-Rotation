
#include<vector>
#include <iostream>

using namespace std;

/**
 * @brief Given an integer vector moves elements to the right (rotates the vector) by k steps
 * @param nums an integer vector
 * @param k number of steps to move the array
*/
void rotate(vector<int>& nums, int k) {


	//Calculate size once so we don't need to calculate it everytime
	int size = nums.size();
	
	// IMPORTANT: If k == the length of the array, we will end up where we started
	//So no need to do anything if that's the case. We can just return immedietly 
	if (k == nums.size()) return;

	for (size_t i = 0, count = 0; count != size; i++) {
		int curIndex = i;
		int prevElement = nums[curIndex];
		do {
			//Calculate target index for the element at curIndex
			int nextIndex = (curIndex + k) % size;

			//Save the element at target index in a temp var so we won't lose it
			int temp = nums[nextIndex];

			// move prevElement to target index
			nums[nextIndex] = prevElement;

			//Prev element is now temp and cur index is target index
			prevElement = temp;
			curIndex = nextIndex;

			//Increase replacement count
			count++;
		} while (curIndex != i);
	}
 

}


int main() {
	vector<int> v{ 1,2,3,4, 5, 6 };
	rotate(v, 2);

	for (int e : v) {
		cout << e << " ";
	}
	return 0;
}
