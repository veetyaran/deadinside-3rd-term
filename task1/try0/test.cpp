// Name of program mainreturn.cpp
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	cout << "You have entered " << argc
		<< " arguments:" << "\n";

	for (int i = 0; i < argc; ++i)
		cout << argv[i] << "\n";
        int n = stoi(argv[2]);
        cout << n << "\n";

	return 0;
}
