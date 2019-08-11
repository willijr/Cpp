#include <iostream>																//needed for input/output functions
#include <fstream>																//needed for file functions

using namespace std;															//setting the std
	
int main()																		//main function
{	const int MAX = 100000;														//setting the constant integer MAX at 100,000
	int arraySize, low = 0, hi = 0;												//assigning arraySize, low, and hi as an integer
	string headerA, headerB, headerC;											//assigning the strings to take the headers from the file
	float time[MAX], volt[MAX], amp[MAX];										//assigning the float arrays to the the numbers from each column	
	cout << "This program found the min and max of the volts in the file\n"		//displaying the meaning of the program
		 << "'volts.txt', and listed the time and amps when it occurred.\n\n";	//displaying the meaning of the program	
	ifstream inFile;															//assigning the file to inFile
	inFile.open("volts.txt");													//opening the volts.txt to inFile	
	if (!inFile)																//if the infile does not open
	{	cout << "Cannot open the file, or file not found.";						//error message for file not opening
		return 1;																//returning a value of 1 to show ended irregularly
	}	
	else																		//if the file opens correctly
	{  	inFile >> headerA >> headerB >> headerC;								//labelling the column headers to keep out of the data
		for (arraySize = 0; arraySize < MAX; arraySize++)						//for operation to assign each column to an array assignment
		{	inFile >> time[arraySize] >> volt[arraySize] >> amp[arraySize];		//putting the first column to time array, secont to volt, third to ampere
			if (volt[low] > volt[arraySize])									//if the next item is smaller than voltLow
				low = arraySize;												//assigning the array spot for the lowest volt
			else if (volt[hi] < volt[arraySize])								//if the next item is larger than voltHi
				hi = arraySize;													//assigning the array spot for the highest volt
		}
		cout << "The lowest voltage was: " << volt[low] 						//displaying the lowest voltage
			 << " volts, \nwhich occurred at: " << time[low] 					//displaying the time of the lowest volt
			 << " seconds, \nwith an amperage of: " << amp[low] << " amps.\n\n";//displaying the amps of the lowest volt
		cout << "The highest voltage was: " << volt[hi]							//displaying the highest voltage
			 << " volts, \nwhich occurred at: " << time[hi] 					//displaying the time of the highest volt
			 << " seconds, \nwith an amperage of: " << amp[hi] << " amps.\n\n";	//displaying the amps of the highest volt
		inFile.close();															//closing the inFile
	}
	return 0;																	//returning 0 if the program terminates properly
}	
