/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 3/22/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

To gain experience with base and derived classes, virtual functions, and using 
applications of polymorphism. Also, to gain further practice with file I/O.

You will design a set of classes for storing student information, along with a 
main program that will read student information from a file, store the data, 
compute final grades, and then print a summary report to an output file. Program 
Details and Requirements:

Write a main program (in a separate file) that does the following (in this 
order):

a) Ask the user for input and output file names. This is the only input and 
output that should be done from keyboard and to the screen. All other input and 
output will be to and from files. (See the sample run below).

b) Read the student data from the input file and store it using an array of 
appropriate type. You should use just one array for all students, not a separate 
array for each subject (i.e. this will be a heterogeneous list). You will need 
to allocate this list dynamically, since the size is stored in the input file. 
(Note that this also means each list item will need to be created dynamically). 
Each student's data should be stored in a separate object. (Any dynamically 
allocated space should be cleaned up appropriately with delete when you are 
finished with it). Hint: Remember that a heterogeneous list is implemented 
using an array of pointers to the base class type. And as stated above, this 
must be created dynamically in this situation. i.e. you will need to use the 
new operator. If you declare your array like this: Student* list[size];
then it is WRONG.

c) Print a summary report to the output file, as specified below. You'll need 
to use the function that computes the final average when you do this, since 
the final averages will be included in this summary report.

Input File -- The first line of the input file will contain the number of students 
listed in the file. This will tell you how big a list you need. After the first 
lines, every set of two lines constitutes a student entry. The first line of a 
student entry is the name, in the format lastName, firstName. Note that a name 
could include spaces -- the comma will delineate last name from first name. 
The second line will contain the subject ("English", "History", or "Math"), 
followed by a list of grades (all integers), all separated by spaces. The order
of the grades for each class type is as follows:

English -- Attendance, Project, Midterm, Final Exam
History -- Term Paper, Midterm, Final Exam
Math -- Quiz 1, Quiz 2, Quiz 3, Quiz 4, Quiz 5, Test 1, Test 2, Final Exam

Output File -- The output file that you print should list each student's name 
(firstName lastName - no extra punctuation between), Final Exam grade, final 
average (printed to 2 decimal places), and letter grade (based on 10 point scale, 
i.e. 90-100 A, 80-89 B, etc). Output should be separated by subject, with an 
appropriate heading before each section, and each student's information listed 
on a separate line, in an organized fashion. (See example below).

/******************************************************************************/
/*                       Header Files                                         */

#include "englishstudents.h"
#include "mathstudents.h"
#include "historystudents.h"

#include <iostream>                         // for input and output
#include <iomanip>                          // for arithmatic
#include <fstream>                          // for file manipulation
#include <string.h>                         // for string manipulation
using namespace std;


/******************************************************************************/
/*                       Student Organizer Function                           */


void studentOrganizer(BaseClass** &student, ofstream &outfile, int n, 
                      string classname)
{
            outfile << fixed << showpoint << setprecision(2);
            outfile << classname << " Class" << endl;
            outfile << "Student                   Final    Final    Letter" 
                    << endl; 
            outfile << "Name                      Exam     Avg      Grade" 
                    << endl; 
            outfile << "---------------------------------------------------" 
                    << endl;

        // loop through the total number of students
	    for( int i = 0; i < n; i++ )
	    {       
            // determines if the student belongs in the class
		    if(student[ i ]->getCourseName() == classname)
		    {
			    outfile << setw(25) << left 
                                    << student[i]->getFirstName() + " " 
                                    + student[i]->getLastName()
				         << setw(8) << student[i]->finalExam() 
                                    << setw(8) << student[i]->finalGrade() 
                                    << student[i]->getLetterGrade() << endl; 
		    } // end of if(student[ i ]->getCourseName() == classname)
	    } // end of for( int i = 0; i < n; i++
} // end of function studentOrganizer(BaseClass** &student, ofstream &outfile, int n
  // string classname)

int main()
{
	// store the number of students
	int NumStudents;
	BaseClass** Student;

	// store 
	string fileName;

	// store last name
	string fname;
	string lname;
	string cname;

	// store the grade
	int grades;

	// store the number of grades in each class
	int count = 0;

	int g1 = 0,                   // initialize in order to store grades
	    g2 = 0,                   // initialize in order to store grades
        g3 = 0,                   // initialize in order to store grades
	    g4 = 0,                   // initialize in order to store grades
	    g5 = 0,                   // initialize in order to store grades
	    g6 = 0,                   // initialize in order to store grades
	    g7 = 0,                   // initialize in order to store grades
	    g8 = 0;                   // initialize in order to store grades

	// declare file
	ifstream infile;
	ofstream outfile;

	// prompt user to enter file name
	cout << "What is the name of the file you would like to open for input? ";

	// store user entered file name 
	cin >> fileName;

	// open file
	infile.open( fileName.c_str() );
        
     // loop to determine if the file has been opened
	while (!infile.is_open())
	{       
        // if the file is not open ask the user the name of the file again
		cout << "Please try again: ";
		cin >> fileName;
		infile.clear();
		infile.open( fileName.c_str() );
	} // end of while(!infile.is_open())	

	// prompt user to enter file name
	cout << "What is the name of the file you would like to open for output? ";

	// store user entered file name 
	cin >> fileName;

	// open file
	outfile.open( fileName.c_str() );
         
    // loop to determine if the file has been opened
	while (!outfile.is_open())
	{
        // if the file is not open ask the user the name of the file again 
		cout << "Please try again: ";
		cin >> fileName;
		outfile.clear();
		outfile.open( fileName.c_str() );
	} // end of while (!outfile.is_open())	

	// read in the number of students
	infile >> NumStudents;

	// create a dynamic array of student objects
	Student = new BaseClass*[NumStudents];  

	// main control structure to read in student information
	for( int i = 0; i < NumStudents; i++ )
	{
		infile.ignore(1);

		// read in last name and stop at comma
		getline( infile, lname, ',' );

		// read in first name and stop at new line character
		getline( infile, fname, '\n');

		// read in the name of the course and stop at blank space
		getline( infile, cname, ' ' );
 
        // if statements determine how many grades to expect when reading in
		if( cname == "English" )
		{
			count = 4;
		}
		if( cname == "Math" )
		{
			count = 8;
		}
		if( cname == "History" )
		{
			count = 3;
		}
		
		// read in the grades
		switch(count)
		{
			case 3:
				infile >> g1 >> g2 >> g3;
				cout << g1 << g2 << g3 << endl;
				break;
			case 4:
				infile >> g1 >> g2 >> g3 >> g4;
				cout << g1 << g2 << g3 << g4 << endl;
				break;
			case 8:
				infile >> g1 >> g2 >> g3 >> g4 >> g5 >> g6 >> g7 >> g8;
				cout << g1 << g2 << g3 << g4 << g5 << g6 << g7 << g8 << endl;
				break;
		} // end switch(count) 

		if( cname == "English" )
		{
			cout << "English" << endl;
			Student[ i ] = new englishStudents(cname, fname, lname, g1, g2, g3, g4 );
		}
		if( cname == "Math" )
		{
			cout << "Math" << endl;
			Student[ i ] = new mathStudents(cname, fname, lname, g1, g2, g3, g4, g5, g6, g7, g8 );
		}
		if( cname == "History" )
		{
			cout << "History" << endl;
			Student[ i ] = new historyStudents(cname, fname, lname, g1, g2, g3 );
		}
	} // end for( int i = 0; i < NumStudents; i++ )


	// close file
	infile.close();

    // calls the studentOrganizer function to print student information to a  file by class
	studentOrganizer(Student, outfile, NumStudents, "English");
	outfile << endl;
	studentOrganizer(Student, outfile, NumStudents, "Math");
	outfile << endl;
	studentOrganizer(Student, outfile, NumStudents, "History");
	outfile << endl;

return 0;
}
