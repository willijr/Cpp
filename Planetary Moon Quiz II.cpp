//program that is a quiz for the number of moons for each planet.

#include <iostream>

using namespace std;

int Moon[] = {0, 0, 1, 2, 67, 60, 27, 14, 5};								//array for the number of moons
//the number of moons came from the website: 
//https://www.quora.com/How-many-moons-does-each-planet-have

string Planets[] = {"Mercury", 												//array for the planets
					"Venus", 
					"Earth", 
					"Mars", 
					"Jupiter", 
					"Saturn", 
					"Uranus", 
					"Neptune", 
					"Pluto"};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int quiz (int rightNum, int wrongNum)										//quiz function
{
	int moonGuess;															//assigning int
	int moonCount;															//assigning int
	string planet;															//assigning string
	int i;																	//assigning int for counter
	for (i = 0; i <= 8; i++)												//counter controlled for
	{	planet = Planets[i];												//assigning planet from the array Planets from spot i
		moonCount = Moon[i];												//assigning moonCount from the array Moon from spot i
		system("CLS");														//clearing the screen
		cout << "How many moons does " << planet << " have?  ";				//prompting the number of moons for planet
		cin >> moonGuess;													//getting user input for number of moons
		if (moonGuess == moonCount)											//comparing user input with correct answer
		{	cout << "You are correct, " << planet << " does indeed have " 	//if user has right answer, it shows correct answer in statement
				 << moonCount << " moon(s).\n" << "Great Job!\n\n";
		    rightNum = rightNum + 1;
		}
		else																//this is for an incorrect answer
		{	cout << "I'm sorry, that is incorrect. " << planet << " has " 	//it will show the correct response in a statement stating user was incorrect
				 << moonCount << " moon(s).\n\n" << "Better luck next time.\n\n";
			wrongNum = wrongNum + 1;
		}
		system("PAUSE");													//pausing before the for statement loops
	}
	system("CLS");
	cout << "You got " << rightNum << " questions right!\n";
	cout << "You got " << wrongNum << " questions incorrect!\n\n";
	system("PAUSE");
	system("CLS");
}	



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main ()																	//main function
{
	int rightNum = 0;
	int wrongNum = 0;	
	cout << "This is a quiz where you should answer the number of moons for each planet.\n\n"
		 << "Good Luck!\n\n";												//display beginning statement
	system("PAUSE");														//pausing program
	system("CLS");															//clearing the screen
	quiz(rightNum, wrongNum);												//calling the quiz function
	return 0;
}
