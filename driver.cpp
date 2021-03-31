#include <iostream>
#include <fstream>
#include <cctype>
int main(int argc, char* argv[]) {
	
	int a = 10;
	float b = 15.5;

	int *p1 = &a;
	float *p2 = &b;

	std::cout << "The value of variable 'a' is: " << a << std::endl;
std::cout << "The address of variable 'a' is: " << &a << std::endl;
std::cout << "The value of variable 'p1' is: " << p1 << std::endl;
std::cout << "The value of '*p1' is: " << *p1 << std::endl;

std::cout << "The value of variable 'b' is: " << b << std::endl;
std::cout << "The address of varialbe 'b' is: " << &b << std::endl;
std::cout << "The value of variable 'p2' is: " << p2 << std::endl;
std::cout << "The value of '*p2' is: " << *p2 << std::endl;


std::cout << std::endl << "Part 2:" << std::endl;
std::string filename;
int size;
if(argc == 1){
	filename = "single_row.txt";
	size = 10;
}else {
	filename = argv[1];
	size = std::stoi(argv[2]);
}
std::ifstream in(filename);
if(!in) {
	std::cout << "Couldn't open file " << filename << std::endl;
	return 1;
}

int rows = size;
int ** values = new int*[rows];
int n_read = 0;

for (int i = 0; i < size; ++i) {
	values[i] = new int[size];

	for (int j=0; j<size; ++j) {
		in >> values[i][j];
		if(in) {// Check to see if an error occurred
			++n_read;
		} else {
			break;
		}
	}


}

in.close();
// Calculate the average value of all the integer values in our file.
float avg = 0.0;
for (int i = 0; i < size; ++i) {
	for (int j = 0; j < size; ++j) {
		avg += values[i][j];	
	}
}


std::cout << "The Average value of " << filename << " is: " << (avg/(float)n_read)<< std::endl;
delete [] values;

	return 0;
}