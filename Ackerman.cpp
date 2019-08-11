#include <iostream>

using namespace std;

int A(int m, int n)
{	if (m == 0)											//Base case
		return (n + 1);
	else if (m > 0 && n == 0)
		return A(m - 1,1);
	else if (m > 0 && n > 0)
		return A(m - 1, A(m, n -1));
	else 
		cout << "Incorrect integers entered, program will close";
		return 1;
}

int main()
{
	int num1, num2, i, j;
	cout << "Please enter two non-negative integers to run the Ackermann function: ";
	cin >> num1 >> num2;
	system ("CLS");
	for (i = 0; i <= num1; i++)							//Scrolling through the first integer in A()
		for (j = 0; j <= num2; j++)						//Scrolling through the second integer in A()
			cout << "A(" << i << "," << j << ") is:  " 
				 << A(i, j) << endl;					//Displaying the results
		
	return 0;

}
