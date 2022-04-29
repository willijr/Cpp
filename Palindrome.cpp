#include <iostream>														//needed for input and output
#include <string.h>														//needed for string operation and counting string
#include <deque>														//needed for the deque

using namespace std;														//assigning the namespace std

int main()															//main function
{
	char compare[15];													//assigning char array compare
	deque<char> S;														//assigning a deque S
		
	cout << "Please enter the string to compare: ";										//prompting for user to enter
	cin.getline (compare,14);												//using getline to input the char array for multiple words
	int len = strlen(compare);												//counting the char array and assign it to len
	cout << endl;

	{
		for (int arraySize = 0; arraySize < len; arraySize++)								//to run through the char array
		{
			while (isspace (compare[arraySize]))									//while there is a space in the char array
			{
				arraySize++;											//it will skip the space
			}
			S.push_back(compare[arraySize]);									//loads the next item to the stack
		}
	}
	if (S.front() == S.back())												//if the first in q matches the last entered in s
	{
		S.pop_front();													//removing the first item entered in q
		S.pop_back();													//removing the last item enetered in s
		if (S.empty())
			cout << "This word/phrase IS considered a palindrome";							//display correct message
		else	
		{
			if (S.front() == S.back())										//if the first in q matches the last entered in s
			{
				S.pop_front();											//removing the first item entered in q
				S.pop_back();											//removing the last item enetered in s
				if (S.empty())		
					cout << "This word/phrase IS considered a palindrome";					//display correct message
				else
				{
					if (S.front() == S.back())								//if the first in q matches the last entered in s
					{
						S.pop_front();									//removing the first item entered in q
						S.pop_back();									//removing the last item enetered in s
						if (S.empty())		
							cout << "This word/phrase IS considered a palindrome";			//display correct message
						else
							if (S.front() == S.back())											//if the first in q matches the last entered in s
								cout << "This word/phrase IS considered a palindrome!";		//display correct message
							else
								cout << "This word/phrase IS NOT considered a palindrome!";	//display error message
					}
					else
						cout << "This word/phrase IS NOT considered a palindrome!";			//display error message
				}
			}
			else
				cout << "This word/phrase IS NOT considered a palindrome!";					//display error message
		}
	}
	else
		cout << "This word/phrase IS NOT considered a palindrome!";							//display error message
	cout << endl;	
	
	return 0;
}
