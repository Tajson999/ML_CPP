#include <iostream>
#include <fstream>

using namespace std;

int main() {

	fstream file;
	file.open("download.png", ios::in, ios::binary);

	int min = file.tellg();
	file.seekg(0, ios::end);
	int max = file.tellg();
	file.seekg(0, ios::beg);

	int bytes = max - min;
	cout << "Bytes is " << bytes << endl
	char* buffer = new char(4096);
	file.read(buffer, sizeof(buffer));
	for (int i = 0; i < sizeof(4096); i++) {
		cout << *(buffer + i);
	}

	getchar();

	return 0;
}