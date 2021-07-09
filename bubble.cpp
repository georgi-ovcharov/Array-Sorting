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
	mySaveFile.open("bubbleSorted.txt");
	for (int i = 0; i < SIZE; i++) {
		mySaveFile << setw(5) << A[i];
		cout << setw(5) << A[i];
	}
	cout << endl;
	mySaveFile.close();
}

void bubbleSort() {
	int temp;
	for (int i = 0; i < SIZE-1; i++) {
		for (int j = 0; j < SIZE-1; j++) {
			if (A[j] > A[j+1]) {
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

int main() {
	readFile();
	bubbleSort();
	printFile();
	return 0;
}
