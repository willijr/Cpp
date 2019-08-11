#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main()
{ 
int SIZE = 10;
int NUMBERS[SIZE];
int i;
int j;
int temp;

for(i = 0; i <= (SIZE-1); i++)
{
	cout << "Please enter a number: " << endl;
	cin >> NUMBERS[i];
}

for(i = 0; i <= (SIZE-2); i++)
{
	for (j = 0; j <= (SIZE-2); j++)
	{
		if (NUMBERS[j] < NUMBERS[j+1])
		{
			temp = NUMBERS[j];
			NUMBERS[j] = NUMBERS[j+1];
			NUMBERS[j+1] = temp;
		}
	}
}

cout << "Sorted List" << endl;
cout << "===========" << endl;

for (i = 0; i <= (SIZE-1); i++)
{
	cout << "Number " << (i+1) << ": " << NUMBERS[i] << endl;
}

system("PAUSE");
return 0;
}
