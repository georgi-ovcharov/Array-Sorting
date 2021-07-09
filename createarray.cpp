#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 8;
int A[SIZE];

int generateRand() {
	return rand() % 100;
}


void generateAndSave() 
{
	ofstream myfile;
	myfile.open ("unsorted.txt");
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		A[i] = generateRand();
		cout << setw(5) << A[i];
		myfile << setw(5) << A[i];
	}
	cout << endl;
	myfile.close();
}

int main() {
	generateAndSave();
}
