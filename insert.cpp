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
	mySaveFile.open("insertSorted.txt");
	for (int i = 0; i < SIZE; i++) {
		mySaveFile << setw(5) << A[i];
		cout << setw(5) << A[i];
	}
	cout << endl;
	mySaveFile.close();
}

void insertSort() {
	int i, j, key;
    for (i = 0; i < SIZE; i++) {
		key = A[i];
		j = i;
        while ((j > 0) && (A[j-1] > key)) {
            A[j] = A[j-1];
			j--;
        }
		A[j] = key;
    }
}

int main() {
	readFile();
	insertSort();
	printFile();
	return 0;
}
