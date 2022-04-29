// This program will calculate the volume of several shapes,
// with either imperial or metric measurements, then turn 
// that to gallons and ounces.

#include <iostream>										// needed for input and output
#include <cmath>										// needed for power and pi
#include <iomanip>										// needed for setprecision

using namespace std;

string measurement, dimA, dimB, shape, measure;							// assinging the global strings
double radius;											// assinging the global doubles
int measure_A, measure_B, measure_C, measure_D, height_A, height_B;				// assinging the global integers
int height, measureTotal, width, length;							// assinging the global integers
char type;											// assinging the global character
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string wrong()											// wrong function for when an incorrect key is entered
{
	cout << "I don't think that is one of the options, please run again later!\n\n";	// displaying error message for incorrect letter
	system("PAUSE");									// pausing the program
	exit(1);										// forcing the program to end and returning 1
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double dia()											// dia function to turn diameter to radius
{
	measure = "Diameter of ";								// assigning string measure for display at end of program
	cout << "What is the diameter, in " << dimA << " and " << dimB << ", please: \n\n";	// 7. prompt for dimensions
   	cout << dimA << ": ";									// 7. prompt for feet or meters
	cin >> measure_A; 									// 8. get feet or meters
	cout << dimB << ": ";									// 7. prompt for inches or centimeters
	cin >> measure_B;									// 8. get inches or centimeters
	if (measurement == "A" || measurement =="a")						// if measurements are in imperial
	{
		measureTotal = (measure_A * 12 + measure_B);					// 9. converting feet to inches and adding the inches
	}
	else											// if measurements are in metric
	{
		measureTotal = (measure_A * 100 + measure_B);					// 9. converting the meters to cm and adding the cm
	}											
   	return radius = (measureTotal / 2);							// calculates and returns radius from diameter input to volum function
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double rad()											// rad function to input and return the radius
{	
	measure = "Radius of ";									// assigning string measure for display at end of program
	cout << "What is the radius, in " << dimA << " and " << dimB << ", please: \n\n";	// 7. prompt for dimensions
   	cout << dimA << ": ";									// 7. prompt for feet or meters
	cin >> measure_A;  									// 8. get feet or meters
	cout << dimB << ": ";									// 7. prompt for inches or centimeters
	cin >> measure_B;									// 8. get inches or centimeters
	if (measurement == "A" || measurement =="a")						// if measurements are in imperial
	{
		measureTotal= (measure_A * 12 + measure_B);					// 9. converting feet to inches and adding the inches
	}
	else											// if measurements are in metric
	{
		measureTotal = (measure_A * 100 + measure_B);					// 9. converting the meters to cm and adding the cm
	}	
	return radius = measureTotal;								// returns radius to volume function
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
double cir()											// cir function to turn circumference to radius	
{
	measure = "Circumference of ";								// assigning string measure for display at end of program
	cout << "What is the circumference, in " << dimA << " and " << dimB << ", please: \n\n";// 7. prompt for dimensions
   	cout << dimA << ": ";									// 7. prompt for feet or meters
	cin >> measure_A;  									// 8. get feet or meters
	cout << dimB << ": ";									// 7. prompt for inches or centimeters
	cin >> measure_B;									// 8. get inches or centimeters
	if (measurement == "A" || measurement =="a")						// if measurements are in imperial
	{
		measureTotal = (measure_A * 12 + measure_B);					// 9. converting feet to inches and adding the inches
	}
	else											// if measurements are in metric
	{
		measureTotal = (measure_A * 100 + measure_B);					// 9. converting the meters to cm and adding the cm
	}
	return radius = (measureTotal / M_PI / 2);						// calculates and returns radius from diameter input to volum function
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double hi()											// hi function to input and return the height
{
	system("CLS");										// clearing the screen
	cout << "Please tell me the height of the water needed, in " 
		 << dimA << " and " << dimB << ", please: \n\n";				// 7. prompt for dimensions
   	cout << dimA << ": ";									// 7. prompt for feet or meters
	cin >> height_A;  									// 8. get feet or meters
	cout << dimB << ": ";									// 7. prompt for inches or centimeters
	cin >> height_B;									// 8. get inches or centimeters
	if (measurement == "A" || measurement =="a")						// if measurements are in imperial
	{
		height = (height_A * 12 + height_B);						// 9. converting feet to inches and adding the inches
	}
	else											// if measurements are in metric
	{
		height = (height_A * 100 + height_B);						// 9. converting the meters to cm and adding the cm
	}
	system("CLS");										// clearing the screen	
	return height;										// returns height to volume function
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double volume()											// this is the function for calculating volume (depends on the shape)
{	
	char dim;										// assigning the local chars
	double cubic;										// assigning the local doubles
	
	cout << "Is this tank of yours: cylindrical, spherical, conical, or cubical?\n\n";	// 3. prompting for shape
	cout << "Please enter:\n\n" << "A for a cylinder\n" << "B for a sphere\n" 
		 << "C for a cone\n" << "D for a cube\n\n";					// 3. prompting for shape
	cin >> type;										// 4. getting the shape
	system("CLS");										// clearing the screen

	switch (type)										// This is a switch for which shape was entered
	{	
	case 'A':										// This is for the volume of a sphere based on which measurement you have
	case 'a':
		shape = "Cylinder";								// assigning string shape for display at end of program
		cout << "What dimension do you have?\n\n";					// 5. prompting for available dimension
	    cout << "Please enter:\n\n" << "A for diameter\n" << "B for radius\n" << "C for circumference\n\n";	// 5. prompting for available dimension
	    cin >> dim;										// 6. getting the available dimension
	    system("CLS");									// clearing the screen
	    
		switch (dim)
	    {  	
		case 'A':									// diameter
		case 'a':
			radius = dia();								// getting radious returned from called dia function
	    	break;
		case 'B':									// radius
		case 'b':
			radius = rad();								// getting radious returned from called rad function
			break;
		case 'C':									// circumference
		case 'c':
			radius = cir();								// getting radious returned from called cir function
			break;
		default:									// any other key
			wrong();								// runs the wrong function for error message and end program
		}
		hi ();										// height
		return cubic = (pow(radius,2) * height * M_PI);					// 9. calculate and return volume (of a cylineder)
	break;
	case 'B':										// This is for the volume of a sphere based on which measurement you have
	case 'b':
		shape = "Sphere";								// assigning string shape for display at end of program
		cout << "What dimension do you have?\n\n";					// 5. prompting for available dimension
	    cout << "Please enter:\n\n" << "A for diameter\n" << "B for radius\n" << "C for circumference\n\n";	// 5. prompting for available dimension
	    cin >> dim;										// 6. getting the available dimension
		system("CLS");									// clearing the screen
	    switch (dim)
	    {  	
		case 'A':									// diameter
		case 'a':	
	    	radius = dia();									// getting radious returned from called dia function
	    	break;
		case 'B':									// radius
		case 'b':	
			radius = rad();								// getting radious returned from called rad function
			break;
		case 'C':									// circumference
		case 'c':
			radius = cir();								// getting radious returned from called cir function
			break;
		default:									// any other key
			wrong();								// runs the wrong function for error message and end program
		}
		system("CLS");									// clearing the screen
		return cubic = ((4.0/3.0) * M_PI * pow(radius,3));				// 10. calculate and return volume (of a sphere)
	break;
	case 'C':										// This is for the volume of a cone based on which measurement you have
	case 'c':	
		shape = "Cone";									// assigning string shape for display at end of program
		cout << "What dimension do you have?\n\n";					// 5. prompting for available dimension
	    cout << "Please enter:\n\n" << "A for diameter of the base\n" 			// 5. prompting for available dimension
			 << "B for radius of the base\n" << "C for circumference of the base\n\n";	// 5. prompting for available dimension
	    cin >> dim;										// 6. getting the available dimension
	    system("CLS");									// clearing the screen
	    
	    switch(dim)
	    {
		case 'A':									// diameter
		case 'a':
	    	radius = dia();									// getting radious returned from called dia function
	    	break;
		case 'B':									// radius
		case 'b':	
			radius = rad();								// getting radious returned from called rad function
			break;
		case 'C':									// circumference
		case 'c':	
			radius = cir();								// getting radious returned from called cir function
			break;
		default:									// any other key
			wrong();								// runs the wrong function for error message and end program
		}
		height = hi ();									// height is returned from hi function
		return cubic = (pow(radius,2) * height * M_PI / 3);				// 10. calculate and return volume (of a cone)
	break;
	case 'D':										// This is for the volume of a cube
	case 'd':
		shape = "Cube";									// assigning string shape for display at end of program
		measure = "Length of ";								// assigning string measure for display at end of program		
		cout << "What is the length, in " << dimA << " and " << dimB << ", please: \n\n";	// 7. prompt for dimensions
   		cout << dimA << ": ";								// 7. prompt for feet or meters
		cin >> measure_A;  								// 8. get feet or meters
		cout << dimB << ": ";								// 7. prompt for inches or centimeters
		cin >> measure_B;								// 8. get inches or centimeters
		if (measurement == "A" || measurement =="a")					// if measurements are in imperial
		{
			measureTotal = (measure_A * 12 + measure_B);				// 9. converting feet to inches and adding the inches
		}
		else										// if measurements are in metric
		{
			measureTotal = (measure_A * 100 + measure_B);				// 9. converting the meters to cm and adding the cm
		}		
		system("CLS");									// clearing the screen
		cout << "What is the width, in " << dimA << " and " << dimB << ", please: \n\n";// 7. prompt for dimensions
   		cout << dimA << ": ";								// 7. prompt for feet or meters
		cin >> measure_C;  								// 8. get feet or meters
		cout << dimB << ": ";								// 7. prompt for inches or centimeters
		cin >> measure_D;								// 8. get inches or centimeters
		if (measurement == "A" || measurement =="a")					// if measurements are in imperial
		{
			width = (measure_C * 12 + measure_D);					// 9. converting feet to inches and adding the inches
		}
		else										// if measurements are in metric
		{
			width = (measure_C * 100 + measure_D);					// 9. converting the meters to cm and adding the cm
		}	
		height = hi ();									// height is returned from hi function
		return cubic = (measureTotal * width * height);					// 10. calculate and return volume (of a cube)
	break;
	default:
		wrong();									// runs the wrong function for error message and end program
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main ()											// main function
{
	double gallon, cubic;									// assigning local functions
	int gal, ounces;									// assinging ounces and gal as whole numbers
	cout << setprecision(2) << fixed;							// setting decimals to two places
	
	cout << "I understand you need to determine how many gallons of distilled water you need.\n";	// explanation of the program
	cout << "Please tell me about this fish tank you wish to fill.\n\n";			// explanation of the program
	system("PAUSE");									// pausing the program
	system("CLS");										// clearing the screen
	cout << "What will your measurements be recorded in?\n\n";				// 1. prompting for measurement units
	cout << "Please enter:\n\n" << "A for Imperial\n" << "B for Metric\n\n";		// 1. prompting for measurement units
	cin >> measurement;									// 2. getting measurement units
	system("CLS");										// clearing the screen
	if (measurement == "A" || measurement == "a")						// this is where we convert each metric to gallons	
	{											// here is the feet and inches
		dimA = "Feet";									// assinging dimA to Feet
		dimB = "Inches";								// assinging dimB to Inches		
		cubic = volume();								// volume is determined in the function	
		gallon = (cubic / 231);								// 10. calculating the gallons (inches)		
		measure_A = measureTotal / 12;							// 12. converting the total inches to feet
		measure_B = measureTotal % 12;							// 12. remainder of inches after feet
		measure_C = width / 12;								// 12. converting the total inches to feet
		measure_D = width % 12;								// 12. remainder of inches after feet
		height_A = height / 12;								// 12. converting the total inches to feet
		height_B = height % 12;								// 12. remainder of inches after feet
	}
	else if (measurement == "B" || measurement == "b")					// here is the meters and cm	
	{
		dimA = "Meters";								// assinging dimA to Meters
		dimB = "Centimeters";								// assinging dimB to Centimeters		
		cubic = volume();								// volume is determined in the function	
		gallon = (cubic / 3785.41);							// 10. calculating the gallons (cm)			
		measure_A = measureTotal / 100;							// 12. converting the total centimeters to meters
		measure_B = measureTotal % 100;							// 12. remainder of cenitmeters after meters
		measure_C = width / 100;							// 12. converting the total centimeters to meters
		measure_D = width % 100;							// 12. remainder of cenitmeters after meters
		height_A = height / 100;							// 12. converting the total centimeters to meters
		height_B = height % 100;							// 12. remainder of cenitmeters after meters		
	}
	else 											// for any other answer then A,a,or B,b
	{
		wrong();									// runs the wrong function for error message and end program
	}	
	gal = gallon;										// turning the double gallon to whole number int gal
	ounces = gallon * 128;									// 13. calculating total number of ounces
	ounces = ounces % 128;									// 13. getting the remainder of ounces after gallons
	cout << "The gallons of distilled water needed to fill \n"
		 << "a fishtank in the shape of a " << shape  << " with a: \n\n" 		// 14. displays the text with the shape
		 << measure << measure_A << " " << dimA << ", " << measure_B << " " << dimB;	// 15. displays the first measurement
	if (type == 'D' || type == 'd')								// if the shape is a cube, width is displayed here
		cout << " by a\nWidth of " << measure_C << " " << dimA << ", " << measure_D << " " << dimB;	// 15. displaying the text with the width	
	if (type == 'A' || type == 'a' || type == 'C' || type == 'c' || type == 'D' || type =='d')		// if the shape is not a sphere, displays the height
		cout << " by a \nHeight of " << height_A << " " << dimA << ", " << height_B << " " << dimB;	// 15. displaying the text with the height
	cout << " is: \n\n" << gallon << " gallons, or: \n\n" << gal 
		 << " gallons \n" << ounces << " ounces." << endl << endl; 			// 16. displays the statement with gallons and ounces
	return 0;										// ending the program
}
