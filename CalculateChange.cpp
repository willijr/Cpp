#include <iostream>
#include <cstdlib>

void displayBills(int);
using namespace std;

int main()
{     
int dollars;

cout << "Please enter the whole dollar amount (no cents!).  Input 0 to terminate: " << endl;
cin >> dollars;

while (dollars != 0)
{
	displayBills(dollars);
	cout << "PLeaase enter the whole dollar amount (no cents!).  Input 0 to terminate: " << endl;
	cin >> dollars;
}

system("PAUSE");
return 0;
}

void displayBills(int dollars)
{
int ones;
int fives;
int tens;
int twenties;
int temp;

twenties = (dollars / 20);
temp = (dollars % 20);
tens = (temp / 10);
temp = (temp % 10);
fives = (temp / 5);
ones = (temp % 5);

cout << "The dollar amoun of " << dollars << " can be represented by the following monetary denominations" << endl;
cout << "     Twenties: " << twenties << endl;
cout << "     Tens: " << tens << endl;
cout << "     Fives: " << fives << endl;
cout << "     Ones: " << ones << endl;
}
