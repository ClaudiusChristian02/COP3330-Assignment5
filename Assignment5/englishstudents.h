/******************************************************************************/
/*                       Author and Date                                      */
/*

Author: Claudius Christian 
Date: 3/22/2013 

/******************************************************************************/
/*                       Summary                                              */
/*

1. Design a set of classes that store student grade information. There should
be one base class to store common data, and three derived classes that divide 
the set of students into three categories: English students, History students, 
and Math students. All data stored in these classes should be private or 
protected. Any access to class data from outside should be done through public 
member functions. The base class should allocate storage for the following data 
(and only this data):

o student's first name (you may assume 20 characters or less)
o student's last name (you may assume 20 characters or less)
o Which course the student is in (English, History, or Math)

2. Each class should have a function that will compute and return the student's 
final average, based on the stored grades. All grades are based on a 100 point 
scale. Here are the grades that need storing 
for each subject, along with the breakdown for computing each final grade:

English -- Attendance = 10%, Project = 30%, Midterm = 30%, Final Exam = 30%
*/

/******************************************************************************/
/*                       Header Files                                         */

#ifndef ENGLISHSTUDENT_H
#define ENGLISHSTUDENT_H

#include "baseclass.h"
#include <stdlib.h>

class englishStudents : public BaseClass
{
public:
	englishStudents();
	englishStudents(string className, string givenName, string sirName, 
                        int a, int p, int m, int f );

	 double finalGrade();
	 int finalExam();

protected:

	int Attendance;
	int Project;
	int Midterm;
	int FinalExam;
};

#endif
