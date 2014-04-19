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

There are 5 quizzes, to be averaged into one Quiz Average (which can be a 
decimal number). Final grade computed as follows: * Quiz Average = 15%, 
Test 1 = 25%, Test 2 = 25%, Final Exam = 35%
*/

/******************************************************************************/
/*                       Header Files                                         */

#ifndef MATHSTUDENT_H
#define MATHSTUDENT_H

#include "baseclass.h"
#include <stdlib.h>

class mathStudents: public BaseClass
{


public:

	mathStudents();
	mathStudents(string className, string givenName, string sirName, int q1, 
                     int q2, int q3, int q4, int q5, int t1, int t2, int f );

	double finalGrade();
	int finalExam();

protected:

	int QuizAverage;
	int TestOne;
	int TestTwo;
	int FinalExam;

};
#endif
