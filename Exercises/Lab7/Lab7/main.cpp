
#include "MaxHeap.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    Heap *newHeap = new Heap;

	newHeap->push(7);
	newHeap->push(12);
	newHeap->push(8);
    newHeap->push(14);
	newHeap->push(16);
	newHeap->push(6);
	cout << "The Root is: " << newHeap->peek() << endl;

	return 0;	//return 0 ending the main function
}

