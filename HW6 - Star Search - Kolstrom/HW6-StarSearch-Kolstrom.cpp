//----------------------------------------------------------
//  Tim Kolstrom
//  trk10@psu.edu 
//  CMPSC 121
//  HW # 6 - Part 2 - Star Search
//  2014-03-28 
//  
//	The program calculates a contestant's score based on user input data.
//----------------------------------------------------------

#include <iostream>
#include <cmath>


using namespace std;

//Function prototypes
void getJudgeData(int);
void calcScore(int,int,int,int,int);

int findLowest(int,int);
int findHighest(int,int);

//Declares each score variable as global variables that can be used in all functions
int s1, s2, s3, s4, s5;

int main()
{

	cout << "*********   STAR SEARCH  ***********" << endl << endl;

	//For loop that calls the getJudgeData fn 5 times
	for(int x = 1; x <= 5; x++)
	{

		//Calls getJudgeData using the x counter to determine which judge score to put the entered score in
		getJudgeData(x);


	}

	//Calls the calcScore fn using the 5 scores that were retrieved from the getJudgeData fn
	calcScore(s1,s2,s3,s4,s5);

	return 0;


}

//Gets the judge score data from the user
//Passes the x counter variable to determine which score # to put the data in
void getJudgeData(int x)
{

	//Declares local reference variable to handle the score data
	int score;

	do
	{
		cout << "Please enter the judge's score: ";

		cin >> score;

		//Alerts the user that the score is invalid
		if(score < 0 || score > 10)
			cout << endl << "Invalid score, please re-enter." << endl;


	}while(score < 0 || score > 10); //Keeps running the loop until the user enters a valid score

	//Switch statement to determine which score variable to put the user entered data in
	switch(x)
	{
		case 1:
			s1 = score;
			break;
		case 2:
			s2 = score;
			break;
		case 3:
			s3 = score;
			break;
		case 4:
			s4 = score;
			break;
		case 5:
			s5 = score;
			break;
		default:
			cout << "Unknown error!";
	}

	return;

}


//Function to calculate the average combined judge score dropping the lowest and the highest
void calcScore(int s1, int s2, int s3, int s4, int s5)
{
	int averageScore;
	
	//Finds the min score by composing the findLowest functions within one another
	int min = findLowest(s5, (findLowest(s4, findLowest(s3, findLowest(s1, s2)))));

	//Finds the max score by composing the findHighest functions within one another
	int max = findHighest(s5, (findHighest(s4, findHighest(s3, findHighest(s1, s2)))));

	//Calculates averageScore by adding all scores together, subtracting the min and the max and then dividing by 3
	averageScore = ((s1+s2+s3+s4+s5) - (min + max)) / 3;

	//Displays average combined judge's score
	cout << endl << "Your combined judge's score is " << averageScore << endl ;

	return;
}

//Determines the lowest score out of the set and returns the value
int findLowest(int a1, int a2)
{

	if(a1 < a2)
		return a1;
	return a2;

}

//Determines the highest score out of the set and returns the value
int findHighest(int a1, int a2)
{

	if(a1 > a2)
		return a1;
	return a2;

}

