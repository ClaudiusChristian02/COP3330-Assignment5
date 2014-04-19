/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 2/26/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

An object of type Sale will store information about a single sale.
The variable "item" stores the type of item being sold (one of the four
items in the enumerated type ItemType).  Books, music, and software are
the types of items sold.  CREDIT stands for store credit, which incurs
a negative monetary charge.

A Register object should store at least the following information: an 
identification number (an integer) for the cash register object, the amount of 
money in the cash register object, and a list of sales. All member data must be 
private. There is no size limit to the sales list, so it should be implemented with 
a dynamically allocated array. (This means you'll need an array of Sale objects). 
There should never be more than 5 unused slots in this array (i.e. the number of 
allocated spaces may be at most 5 larger than the number of slots that are actually 
filled with real data). This means that you will need to ensure that the array 
allocation expands or shrinks at appropriate times. Whenever the array is resized, 
print a message (for testing purposes) that states that the array is being resized, 
and what the new size is. Example: "** Array being resized to 10 allocated slots". 
Correct memory management
*/

/******************************************************************************/
/*                       Header Files                                         */
#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>

using namespace std;

class BaseClass
{

protected:
	string courseName;
	string firstName;
	string lastName;

public:

	// default constructor
	BaseClass();

	// constructor
	BaseClass( string className, string givenName, string sirName, 
		       int grades );

	// virtual function final grade
	virtual double finalGrade()=0;
	// virtual function final exam
	virtual int finalExam()=0;
	char getLetterGrade();

	string getFirstName();
	void setFirstName( string givenName );
	string getCourseName();
	void setCourseName( string className );
	string getLastName();
	void setLastName( string sirName );
	string getGrades();
	void setGrades( string scores );

};

#endif
