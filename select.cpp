#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 8;
int A[SIZE];

void readFile() {
	int x,i = 0;
	ifstream myReadFile;
	myReadFile.open("unsorted.txt");
	if (myReadFile.is_open()) {
		while (myReadFile >> x) {
			A[i++] = x;
			cout << setw(5) << x;
		}
	}
	cout << endl;
	myReadFile.close();
}

void printFile() {
	ofstream mySaveFile;
	mySaveFile.open("selectSorted.txt");
	for (int i = 0; i < SIZE; i++) {
		mySaveFile << setw(5) << A[i];
		cout << setw(5) << A[i];
	}
	cout << endl;
	mySaveFile.close();
}

void selectSort() {
	int i, j, imin;
	for(i = 0; i < SIZE-1; i++) {
		imin = i;
		for(j = i+1; j < SIZE; j++)
			if(A[j] < A[imin]) {
				imin = j;
			}
		swap(A[i], A[imin]);
	}
}		

int main() {
	readFile();
	selectSort();
	printFile();
	return 0;
}
