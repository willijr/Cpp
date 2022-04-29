#include <iostream>                                                             	//for input and output
#include <string>                                                               	//for string operations
#include <fstream>                                                              	//for loading file
#include <list>                                                                 	//for sort,push_back, remove, list, and iterator

using namespace std;                                                            	//setting it to std

string searchItem;                                                              	//setting global string of searchItem

void sortNumber();                                                              	//defining the sortNumber function
void sortFirst();                                                               	//defining the sortFirst function
void sortLast();                                                                	//defining the sortLast function

list<string> l;                                                                 	//assigning the global string list l
list<string> f;                                                                 	//assigning the global string list f
list<string> n;                                                                 	//assigning the global string list n
list<string>::iterator it;                                                      	//assigning the global iterator it

struct nodeType                                                                 	//defining the global struct nodeType
{
	string firstName, lastName, phoneNumber;                                	//assigning the strings in the struct
	nodeType *link;                                                         	//assigning the pointer in the struct
};
nodeType *current, *newNode, *first, *last;						//assigning the global struct pointers nodeType

//main function
int main ()
{
	string firstN, lastN, number, newfirst, newlast, newnumber, nowpicked;  	//assigning local strings
	int newadd;                                                             	//assigning local int
	char selection, choice, type, picked;                                   	//assigning local chars

	ifstream inFile;								//assigning the file to inFile
	inFile.open("NameList.txt");							//opening the volts.txt to inFile
	if (!inFile)									//if the infile does not open
	{	cout << "Cannot open the file, or file not found.";			//error message for file not opening
		return 1;								//returning a value of 1 to show ended irregularly
	}

//filling the list
	first = nullptr;                                                        	//assigning first (pointer) to nullptr (points to nothing)
	while( inFile >> firstN >> lastN >> number)                             	//while there is still data to import from inFile...
	{
	    newNode = new nodeType;                                            		//creating a newNode that is a new nodeType
	    newNode->firstName = firstN;                                        	//putting firstN from inFile in to the firstName spot of ttruct
	    newNode->lastName = lastN;                                          	//putting lastN from inFile in to the lastName spot of ttruct
	    newNode->phoneNumber = number;                                      	//putting number from inFile in to the phoneNumber spot of ttruct

	    if (first == nullptr)                                               	//if the location in the linked list is open
		{
			first = newNode;                                        	//assigning to be filled
			last = newNode;                                         	//assigning to be filled
		}
		else                                                            	//else the location is filled
		{
			last->link = newNode;                                   	//moves to the next location
			last = newNode;                                         	//sets last as the new location
		}
	f.push_back(newNode->firstName);                                        	//pulling from the struct to put firstName in the f list
	l.push_back(newNode->lastName);                                         	//pulling from the struct to put lastName in the l list
    n.push_back(newNode->phoneNumber);                                          	//pulling from the struct to put phoneNumber in the n list
	}

//print the original list
	current = first;								//set current to point to the first node in the list
	while (current != nullptr)                                              	//while current has a next location
	{
		cout << current->lastName << ", " << current->firstName << ": " 	//displaying the struct items at the current location
			 << current->phoneNumber << endl;
		current = current->link;                                        	//assigning current to the next location
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "\nWould you like to:\nA: Add to the current list\n"            	//prompting for user input on how to change the lists
		 << "B: Remove a name from the list\nC: Search for an item in the list\n"
		 << "D: display the sorted list\n\nPlease enter you selection: ";
	cin >> selection;                                                       	//user inputs
	switch(selection)                                                       	//switch to go to which item user inputted
	{
		case 'a':                                                      		//if user prompted to add records
		case 'A':
			{cout << "How many records would you like to add?  ";   	//prompting to ask how many records
			cin >> newadd;                                          	//user input for how many records to add
			for (int i=1; i <= newadd; i++)                                 //for loop until the correct number of records is added
			{
				cout << "Please enter the first and last name: ";       //prompting for first and last name to add
				cin >> newfirst >> newlast;                             //input for newfirst name and newlast name
				cout << "Please enter the phone number, ex.(XXX)XXX-XXXX: ";    //prompting for phone number to add
				cin >> newnumber;                                       //input for newnumber

                newNode = new nodeType;                                         	//creating newNode which is a new nodeType
                newNode->firstName = newfirst;                                  	//putting newfirst in the firstName spot of newNode struct
                newNode->lastName = newlast;                                    	//putting newlast in the lastName spot of newNode struct
                newNode->phoneNumber = newnumber;                               	//putting newnumber in the phonenumber spot of newNode struct
                last->link = newNode;
                last = newNode;

				f.push_back(move(newfirst));                           	//also adding newfirst to the end of the f list
				l.push_back(move(newlast));                             //also adding newlast to the end of the l list
				n.push_back(move(newnumber));                           //also adding newnumber to the end of the n list
			}
			system("CLS");                                                  //clearing the screen after all new items are inputted
			cout << "How would you like to sort the list?\nA: Last name\n"  //prompting to ask how to sort the list
				 << "B: First name\nC: Phone number\n\nPlease enter: ";
			cin >> choice;                                                  //input for how to sort the list
			switch(choice)                                                  //switch for which option was selected
			{
				case 'a':
				case 'A':
					sortLast();                                     //if a or A was selected, calls the sortLast function
					break;
				case 'b':
				case 'B':
					sortFirst();                                    //if b or B was selected, calls the sortFirst function
					break;
				case 'c':
				case 'C':
					sortNumber();                                   //if c or C was selected, calls the sortNumber function
					break;
                default:
                    cout << "That is not one of the options, please try again later.";
                    break;
			}
			break;
			}
		case 'b':
        case 'B':
            {cout << "Which field would you like to select to remove the entire row:\n"
                  << "A: By last name\nB: By first name\nC: By phone number\n\n"
                  <<"Please make a selection: ";
            cin >>picked;
            switch(picked)
			{
				case 'a':
				case 'A':
                    {cout << "Please type the last name of the item you wish to remove: ";
                    cin >> nowpicked;
                    bool found= false;
                    current = first;							//set current to point to the first node in the list
                    while (current != nullptr)						//search the list
                        if (current->lastName == nowpicked)				//searchItem is found
                        {
                            found = true;
                            l.remove(current->lastName);
                            f.remove(current->firstName);
                            n.remove(current->phoneNumber);
                            sortLast();
                        }
                        else
                            current = current->link;					//make current point to the next node
                    if (!found)
                    {
                        system("CLS");
                        cout << "That is not listed, please try again later.\n\n";
                        return 1;
                    }
					break;
                    }
				case 'b':
				case 'B':
                    {cout << "Please type the first name of the item you wish to remove: ";
                    cin >> nowpicked;
                    bool found= false;
                    current = first;							//set current to point to the first node in the list
                    while (current != nullptr)						//search the list
                        if (current->firstName == nowpicked)			    	//searchItem is found
                        {
                            found = true;
                            l.remove(current->lastName);
                            f.remove(current->firstName);
                            n.remove(current->phoneNumber);
                            sortFirst();
                        }
                        else
                            current = current->link;					//make current point to the next node
                    if (!found)
                    {
                        system("CLS");
                        cout << "That is not listed, please try again later.\n\n";
                        return 1;
                    }
					break;
                    }
				case 'c':
				case 'C':
                    {cout << "Please type the phone number of the item you wish to remove: ";
                    cin >> nowpicked;
                    bool found= false;
                    current = first;							//set current to point to the first node in the list
                    while (current != nullptr)						//search the list
                        if (current->phoneNumber == nowpicked)				//searchItem is found
                        {
                            found = true;
                            l.remove(current->lastName);
                            f.remove(current->firstName);
                            n.remove(current->phoneNumber);
                            sortFirst();
                        }
                        else
                            current = current->link;					//make current point to the next node
                    if (!found)
                    {
                        system("CLS");
                        cout << "That is not listed, please try again later.\n\n";
                        return 1;
                    }
					break;
                    }
                default:
                    system("CLS");
                    cout << "That is not one of the options, please try again later.\n";
                    break;
			}
            break;
            }
        case 'c':
        case 'C':
            {cout << "How would you like to search the list?\nA: By last name\n"
                 << "B: By first name\nC: By phone number\n\n"
                 << "Please make a selection: ";
            cin >> type;
            switch(type)
            {
                case 'a':
                case 'A':
                {
                    //searching the last name
                    cout << "Please enter the last name to search for: ";
                    cin >> searchItem;
                    system("CLS");
                    bool found= false;
                    current = first;							//set current to point to the first node in the list
                    while (current != nullptr)						//search the list
                        if (current->lastName == searchItem)				//searchItem is found
                        {
                            found = true;
                            cout << current->lastName << ", " << current->firstName << ": "
                                 << current->phoneNumber << endl;
                            current = current->link;

                        }
                        else
                            current = current->link;					//make current point to the next node
                    if (!found)
                    {
                        system("CLS");
                        cout << "That is not listed, please try again later.\n\n";
                        return 1;
                    }
                    break;
                }
                case 'b':
                case 'B':
                {
                    //searching the first name
                    cout << "Please enter the first name to search for: ";
                    cin >> searchItem;
                    system("CLS");
                    bool found = false;
                    current = first;							//set current to point to the first node in the list
                    while (current != nullptr)						//search the list
                        if (current->firstName == searchItem)				//searchItem is found
                        {
                            found = true;
                            cout << current->lastName << ", " << current->firstName << ": "
                                 << current->phoneNumber << endl;
                            current = current->link;
                        }
                        else
                            current = current->link;					//make current point to the next node
                    if (!found)
                    {
                        system("CLS");
                        cout << "That is not listed, please try again later.\n\n";
                        return 1;
                    }
                    break;
                }
                case 'c':
                case 'C':
                {
                    //searching the phone number
                    cout << "Please enter the phone number to search for: ";
                    cin >> searchItem;
                    system("CLS");
                    bool found = false;
                    current = first;							//set current to point to the first node in the list
                    while (current != nullptr)						//search the list
                        if (current->phoneNumber == searchItem)				//searchItem is found
                        {
                            found = true;
                            cout << current->lastName << ", " << current->firstName << ": "
                                 << current->phoneNumber << endl;
                            current = current->link;					//make current point to the next node
                        }
                        else
                            current = current->link;					//make current point to the next node
                    if (!found)
                    {
                        system("CLS");							//clearing the screen
                        cout << "That is not listed, please try again later.\n\n";
                        return 1;
                    }
                    break;
                }
                default:
                    system("CLS");							//clearing the screen
                    cout << "That is not listed, please try again later.\n";
                    return 1;
                }
                break;
            }
        case 'd':
        case 'D':
			{cout << "How would you like to sort the list?\nA: Last name\n"	//prompting for which sort
				 << "B: First name\nC: Phone number\n\nPlease enter: ";
			cin >> choice;							//input for which sort was selected
			switch(choice)							//switch depenging on which sort was selected
			{
				case 'a':
				case 'A':
					sortLast();                                     //if a or A was selected, calls the sortLast function
					break;
				case 'b':
				case 'B':
					sortFirst();                                    //if b or B was selected, calls the sortFirst function
					break;
				case 'c':
				case 'C':
					sortNumber();                                   //if c or C was selected, calls the sortNumber function
					break;
                default:                                                        	//if another character was entered
                    system("CLS");							//clearing the screen
                    cout << "That is not one of the options, please try again later.\n";
                    break;
			}
            break;
			}
        default:                                                                	//if another character was entered
            system("CLS");								//clearing the screen
            cout << "That is not one of the options, please try again later.\n";
            break;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//sorting by phone number
void sortNumber()
{
	system("CLS");									//clearing the screen
	n.sort();									//sorting the n list
	for (it=n.begin(); it!=n.end(); ++it)						//using the iterator it to go through the list
	{
    	searchItem = *it;								//setting searchItem as the item it is pointing to
		current = first;							//set current to point to the first node in the list
		while (current != nullptr)						//search the list
			if (current->phoneNumber == searchItem)				//searchItem is found
			{
				cout << current->phoneNumber << ": " << current->lastName << ", "
					 << current->firstName << endl;			//displaying the current items in the lists
				current = current->link;				//advancing current to the next item
			}
			else
				current = current->link;				//make current point to the next node
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//sorting by first name
void sortFirst()
{
	system("CLS");									//clearing the screen
	f.sort();									//sorting the f list
	for (it=f.begin(); it!=f.end(); ++it)						//using the iterator it to go through the list
	{
    	searchItem = *it;								//setting searchItem as the item it is pointing to
		current = first;							//set current to point to the first node in the list
		while (current != nullptr)						//search the list
			if (current->firstName == searchItem)				//searchItem is found
			{
				cout << current->firstName << " " << current->lastName << ": "
					 << current->phoneNumber << endl;		//displaying the current items in the lists
				current = current->link;				//advancing current to the next item
			}
			else
				current = current->link;				//make current point to the next node
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//sorting by last name
void sortLast()
{
	system("CLS");									//clearing the screen
	l.sort();									//sorting the l list
	for (it=l.begin(); it!=l.end(); ++it)						//using the iterator it to go through the list
	{
    	searchItem = *it;								//setting searchItem as the item it is pointing to
		current = first;							//set current to point to the first node in the list
		while (current != nullptr)						//search the list
			if (current->lastName == searchItem)				//searchItem is found
			{
				cout << current->lastName << ", " << current->firstName << ": "
					 << current->phoneNumber << endl;		//displaying the current items in the lists
				current = current->link;				//advancing current to the next item
			}
			else
				current = current->link;				//make current point to the next node
	}
}
