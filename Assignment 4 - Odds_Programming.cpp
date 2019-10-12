#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm> //for random shuffle of vector
#include <list>
#include <cstdlib>

using namespace std;

//function prototypes
int linearSearch(vector<int> v, int a);
void vectorSortCompare ();
void ShellSort(vector <int> &num);
void selection_sort(vector<int>& vec);
void bubble_sort_improved(vector <int> &vec);
void insertion_sort(std::vector <int> &num);
void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound);
void mergesort(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand);
void mergeSort(std::vector<int>& array);
int partition(int first, int last, std::vector<int>& arr);
void sort_median(std::vector<int>& arr, int first, int last);
int partitionB(int first, int last, std::vector<int>& arr);
void middle_quick_sort(int first, int last, std::vector<int>& arr);
void middle_quick_sort_wrapper(vector<int>& arr);
void quick_sort(int first, int last, std::vector<int>& arr);
void quick_sort_wrapper(vector<int>& arr);

vector<int> vector1{2,6,7,5,9,3,5,2,6,3,0};

vector<int> sortedVector;
vector<int> reverseVector;
vector<int> randomVector;

int comparison_count;
int exchange_count;

int main() {

	linearSearch(vector1, 3);
	vectorSortCompare();
	return 0;
}

// 4.3 Programming Question
int linearSearch(vector<int> v, int a){  
   for (int i = v.size(); i > 0; i--){  
      if (v[i] == a) {
         cout << "Last occurrence at position " << i;
         return i;
      }
   }
}

// 4.5 Programming Question
void vectorSortCompare () {
    // init sorted/random vector
    for (int i=0; i < 10000; i++) {
        sortedVector.push_back(i);
        randomVector.push_back(i);
    }
    // init reverse vector 
    for (int i=10000; i > 0; i--) {
        reverseVector.push_back(i);
    }
    // randomize random vector 
    random_shuffle(randomVector.begin(), randomVector.end());
    
    //Table Values
    //Comparison Values
    cout << '\n' << left << setw(15) << "Algorithm" << setw(15) << "Random Vector" << setw(15) << "Sorted Vector" << setw(15) << "Reversed Vector";
    cout << '\n' << "Selection Sort";
    selection_sort(randomVector);
    cout << right << setw(15) << comparison_count;
    selection_sort(sortedVector);
    cout << right << setw(15) << comparison_count;
    selection_sort(reverseVector);
    cout << right << setw(15) << comparison_count;

    cout << '\n' << "Bubble Sort (I)";
    bubble_sort_improved(randomVector);
    cout << right << setw(15) << comparison_count;
    bubble_sort_improved(sortedVector);
    cout << right << setw(15) << comparison_count;
    bubble_sort_improved(reverseVector);
    cout << right << setw(15) << comparison_count;

    cout << '\n' << "Insertion Sort";
    insertion_sort(randomVector);
    cout << right << setw(15) << comparison_count;
    insertion_sort(sortedVector);
    cout << right << setw(15) << comparison_count;
    insertion_sort(reverseVector);
    cout << right << setw(15) << comparison_count;

    cout << '\n' << "Shell Sort";
    ShellSort(randomVector);
    cout << right << setw(15) << comparison_count;
    ShellSort(sortedVector);
    cout << right << setw(15) << comparison_count;
    ShellSort(reverseVector);
    cout << right << setw(15) << comparison_count;

    cout << '\n' << "Merge Sort";
    mergeSort(randomVector);
    cout << right << setw(15) << comparison_count;
    mergeSort(sortedVector);
    cout << right << setw(15) << comparison_count;
    mergeSort(reverseVector);
    cout << right << setw(15) << comparison_count;

    cout << '\n' << "Quick Sort";
    quick_sort_wrapper(randomVector);
    cout << right << setw(15) << comparison_count;
    quick_sort_wrapper(sortedVector);
    cout << right << setw(15) << comparison_count;
    quick_sort_wrapper(reverseVector);
    cout << right << setw(15) << comparison_count;

    cout << '\n' << "Quick Sort (I)";
    middle_quick_sort_wrapper(randomVector);
    cout << right << setw(15) << comparison_count;
    middle_quick_sort_wrapper(sortedVector);
    cout << right << setw(15) << comparison_count;
    middle_quick_sort_wrapper(reverseVector);
    cout << right << setw(15) << comparison_count;

    //Exchange Values
    cout << '\n' << "Selection Sort";
    selection_sort(randomVector);
    cout << right << setw(15) << exchange_count;
    selection_sort(sortedVector);
    cout << right << setw(15) << exchange_count;
    selection_sort(reverseVector);
    cout << right << setw(15) << exchange_count;

    cout << '\n' << "Bubble Sort (I)";
    bubble_sort_improved(randomVector);
    cout << right << setw(15) << exchange_count;
    bubble_sort_improved(sortedVector);
    cout << right << setw(15) << exchange_count;
    bubble_sort_improved(reverseVector);
    cout << right << setw(15) << exchange_count;

    cout << '\n' << "Insertion Sort";
    insertion_sort(randomVector);
    cout << right << setw(15) << exchange_count;
    insertion_sort(sortedVector);
    cout << right << setw(15) << exchange_count;
    insertion_sort(reverseVector);
    cout << right << setw(15) << exchange_count;

    cout << '\n' << "Shell Sort";
    ShellSort(randomVector);
    cout << right << setw(15) << exchange_count;
    ShellSort(sortedVector);
    cout << right << setw(15) << exchange_count;
    ShellSort(reverseVector);
    cout << right << setw(15) << exchange_count;

    cout << '\n' << "Merge Sort";
    mergeSort(randomVector);
    cout << right << setw(15) << exchange_count;
    mergeSort(sortedVector);
    cout << right << setw(15) << exchange_count;
    mergeSort(reverseVector);
    cout << right << setw(15) << exchange_count;

    cout << '\n' << "Quick Sort";
    quick_sort_wrapper(randomVector);
    cout << right << setw(15) << exchange_count;
    quick_sort_wrapper(sortedVector);
    cout << right << setw(15) << exchange_count;
    quick_sort_wrapper(reverseVector);
    cout << right << setw(15) << exchange_count;

    cout << '\n' << "Quick Sort (I)";
    middle_quick_sort_wrapper(randomVector);
    cout << right << setw(15) << exchange_count;
    middle_quick_sort_wrapper(sortedVector);
    cout << right << setw(15) << exchange_count;
    middle_quick_sort_wrapper(reverseVector);
    cout << right << setw(15) << exchange_count;

}

//Source Code for sorting

void ShellSort(vector <int> &num) {
    comparison_count = 0;
    exchange_count = 0;
	int i, temp, flag = 1, numLength = num.size();
	int gap = numLength;
	bool insertionNeeded = false;
	int swapPos = 0;
	int key;

	while (true)  {    // boolean flag (true when not equal to 0) 
		gap = (gap - 1) / 2;
		if (gap == 0)
			break;

		for (int k = 0; k < gap; k++) {
			for (int j = gap + k; j < numLength; j += gap) {
				key = num[j];

				insertionNeeded = false;
				for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right

					if (key < num[i]) {
						swapPos = i;
						num[i + gap] = num[i];
						insertionNeeded = true;
					}
					else
						break;
				}
				if (insertionNeeded) {
					num[swapPos] = key;    //Put key into its proper location
				}
			}
		}
	}
	return;
}


void selection_sort(vector<int>& vec){
    comparison_count = 0;
    exchange_count = 0;
	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next != vec.size(); ++next) {
            comparison_count ++;
			if (vec[next] < vec[pos_min])
				pos_min = next;
		}
		if (fill != pos_min)
			swap(vec[pos_min], vec[fill]);
            exchange_count ++;
	}
}
void bubble_sort_improved(vector <int> &vec){
    comparison_count = 0;
    exchange_count = 0;
	bool exchanges = false;
	for (int i = 1; i <= vec.size(); i++){
		exchanges = false;
		for (int j = 0; j < vec.size() - i; j++){
			if (vec[j + 1] < vec[j]){
				swap(vec[j], vec[j + 1]);// swap elements
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
}
void insertion_sort(std::vector <int> &num) {
    comparison_count = 0;
    exchange_count = 0;
	int i, j, key;
	bool insertionNeeded = false;

	for (j = 1; j < num.size(); j++) {
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--){ // larger values move right

			if (key < num[i]) {
				num[i + 1] = num[i];
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key;    //Put key into its proper location
	}
}


void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound) {
	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items

	while (lowPointer <= mid && highPointer <= upperBound){
        exchange_count ++;
		if (array[lowPointer] < array[highPointer])
			result[j++] = array[lowPointer++];
		else
			result[j++] = array[highPointer++];
	}

	while (lowPointer <= mid) 
		result[j++] = array[lowPointer++];
		exchange_count ++;


	while (highPointer <= upperBound) 
		result[j++] = array[highPointer++];
		exchange_count ++;
	

	for (j = 0; j < n; j++) //copy the items from the temporary array to the original array
		array[lowerBound + j] = result[j];
}

void mergesort(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand) {
	int midpoint;
	comparison_count ++;
	if (lowerBand < upperBand) {
		midpoint = (lowerBand + upperBand) / 2;
		mergesort(array, result, lowerBand, midpoint); //merge sort the left half
		mergesort(array, result, midpoint + 1, upperBand); //merge sort the right half
		merge(array, result, lowerBand, midpoint + 1, upperBand);
	}
}

void mergeSort(std::vector<int>& array){
    comparison_count = 0;
    exchange_count = 0;
	std::vector<int> result = array;
	mergesort(array, result, 0, array.size() - 1);
}



int partition(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.
	int up = first+1;
	int down = last-1;
	do {

		while ((up != last) && !(arr[first] < arr[up])) {
			++up;
		}
		while (arr[first] < arr[down]) {
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[down], arr[first]);
	return down;
}

void sort_median(std::vector<int>& arr, int first, int last){

	bool exchanges = true;
	int middle = (first + last) / 2;
	if (arr[first]>arr[middle])
		swap(arr[first], arr[middle]);
	if (arr[middle] > arr[last])
		swap(arr[middle], arr[last]);
	if (arr[first] > arr[middle])
		swap(arr[first], arr[middle]);


	//swap the middle with the left 
	swap(arr[middle], arr[first]);
}

int partitionB(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.


	int up = first+1;
	int down = last-1;
	sort_median(arr, first, last-1);
	int mid = first;
	do {
		while ((up != last - 1) && !(arr[mid] < arr[up])) {
			++up;
		}
		while (arr[mid] < arr[down]) {
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[mid], arr[down]);
	
	return down;
}

void middle_quick_sort(int first, int last, std::vector<int>& arr) {
	comparison_count ++;
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partitionB(first, last, arr);

		// Sort the left half.
		middle_quick_sort(first, pivot, arr);
		exchange_count ++;

		// Sort the right half.
		middle_quick_sort(pivot + 1, last, arr);
		exchange_count ++;
	}
}

void middle_quick_sort_wrapper(vector<int>& arr){
    comparison_count = 0;
    exchange_count = 0;
	middle_quick_sort(0, arr.size(), arr);
}

void quick_sort(int first, int last, std::vector<int>& arr) {
    comparison_count ++;
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partition(first, last, arr);

		// Sort the left subarray.
		quick_sort(first, pivot, arr);
		exchange_count ++;

		// Sort the right subarray.
		quick_sort(pivot + 1, last, arr);
		exchange_count ++;
	}
}

void quick_sort_wrapper(vector<int>& arr){
	comparison_count = 0;
    exchange_count = 0;
	quick_sort(0, arr.size(), arr);
}