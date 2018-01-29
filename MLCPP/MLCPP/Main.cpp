#include <iostream>
#include <fstream>


using namespace std;

int main() {

	fstream file;
	//path: C:\\Users\\alexa\\Desktop\\ML_CPP\\train-images.idx3-ubyte
	file.open("C:\\Users\\alexa\\Desktop\\ML_CPP\\train-images.idx3-ubyte", ios::in, ios::binary);
	int min, max, bytes;
	min = file.tellg();
	file.seekg(0, ios::end);
	max = file.tellg();
	file.seekg(0, ios::beg);
	bytes = max - min;
	cout << "bytes is " << bytes << endl;
	char* buffer = new char(bytes);
	file.read(buffer, bytes);


	int magicNumber = (int)buffer;
	cout << "Magic number is " << magicNumber << endl;

	int *nrImages;
	nrImages = (int *)buffer;
	cout << "nrImages is " << nrImages << endl;

	int nrRows;
	file.read((char *)&nrRows, sizeof(int));
	cout << "nrRows is " << nrRows << endl;

	int nrCols;
	file.read((char *)&nrCols, sizeof(int));
	cout << "nrCols is " << nrCols << endl;

	getchar();

	delete[] buffer;

	return 0;
}