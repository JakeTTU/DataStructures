//
//  main.cpp
//  Sorting
//
//  Created by Jake Gonzalez on 4/10/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <iostream>
using namespace std;

void bubble_sort(int *ints, int length) { //order n^2
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++){
            if(ints[j] > ints[j + 1]) {
                int k = ints[j];
                ints[j] = ints[j+1];
                ints[j + 1] = k;
            }
        }
    }
}

void selection_sort(int *ints, int length) { //order n^2
    for (int i = 0; i < length; i ++) {
        int min = i; //min is the index of the smallest number
        for (int j = i + 1; j < length; j++) {
            if (ints[j] < ints[min]) {
                min = j;
            }
        }
        int k = ints[min];
        ints[min] = ints[i];
        ints[i] = k;
    }
}

void insertion_sort (int *ints, int length) { //order n^2
    for (int i = 0; i < length; i ++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (ints[j] < ints[min]) {
                min = j;
            }
        }
        int k = ints[min];
        for (int l = min; l > i; l--) {
            ints[l] = ints[l - 1];
        }
        ints[i] = k;
    }
}

void quick_sort_recursion(int* ints, int lo, int hi) {//average complexity nlogn, worst case n^2, (inplace)
    int pivot = ints[hi - 1];
    int temp;
    int low = lo;
    int high = hi;
    if (hi - lo > 1) {
        hi -=2;
        while (lo < hi) {
            if (ints[lo] < pivot) {
                lo++;
            }
            else {
                temp = ints[hi];
                ints[hi] = ints[lo];
                ints[lo] = temp;
                hi--;
            }
        }
        int mid;
        if (ints[lo] < pivot) {
            mid = lo + 1;
        }
        else {
            mid = lo;
        }
        temp = ints[high - 1];
        ints[high - 1] = ints[mid];
        ints[mid] = temp;
        
        quick_sort_recursion(ints, low, mid);
        quick_sort_recursion(ints, mid + 1, high);
    }
}

void quick_sort(int *ints, int size) {
    quick_sort_recursion(ints, 0, size);
}


void merge_sort(int *ints, int length) { //time complexity will always take nlog(n), less space efficient than quicksort (linked list can be used and pointers can be moved instead of copying the entire array.
    if (length != 1) {
        int leftSize = length / 2;
        int rightSize = length - leftSize;
        int *left = new int[leftSize];
        int *right = new int[rightSize];
        for (int i = 0; i < leftSize; i++) {
            left[i] = ints[i];
        }
        for (int i = leftSize; i < length; i++) {
            right[i - leftSize] = ints[i];
        }

        merge_sort(left, leftSize);
        merge_sort(right, rightSize);
        //merge
        int i = 0;
        int j = 0;
        int k = 0;
        for (;j < leftSize && k < rightSize; i++) {
            if (left[j] < right[k]) {
                ints[i] = left[j];
                j++;
            }
            else {
                ints[i] = right[k];
                k++;
            }
        }
        if (j == leftSize) {
            for (; i < length; i++, k++) {
                ints[i] = right[k];
            }
        }
        else{
            for (; i < length; i++, j++) {
                ints[i] = left[j];
            }
        }
        
        //clear memory
        delete[] left;
        delete[] right;
    
    }
}

void dislplay_array(int *ints, int length) {
    cout << "{";
    if (length > 0) {
        cout << " " << ints[0];
        for (int i = 1; i < length; i++){
            cout << ", " << ints[i];
        }
    }
    cout << " }" << endl;
}

int main(int argc, const char * argv[]) {
    int ints[] = {8, 15, 4, 69, 42, 36};
    
    dislplay_array(ints, 6);
    //bubble_sort(ints, 6);
    //selection_sort(ints, 6);
    //insertion_sort(ints, 6);
    //merge_sort(ints, 6);
    quick_sort(ints, 6);
    dislplay_array(ints, 6);
    
    return 0;
}
