/**********************************************************************************************************************
In-Class Group Project TRACK 2
Name: Laura Yang, Jesse Dammann, Jesse and Shigeki Kamata
Date: 11/20/2019
***********************************************************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;


int mainMenu() {
    int answer = 0;

    cout << " Select an option:" << endl;
    cout << endl;
    cout << "1. Display the values in ascending order"<< endl;
    cout << "2. Display the smallest value entered"<< endl;
    cout << "3. Display the largest value entered"<< endl;
    cout << "4. Display the range of the values entered"<< endl;
    cout << "5. Display the sum of the values entered" << endl;
    cout << "6. Display the mean (average value)"<< endl;
    cout << "7. Display the median value"<< endl;
    cout << "8. Display the sample standard deviation"<< endl;
    cout << "9. Exit"<< endl;


    cout << endl;
    cout << "Type in which one you'd like here: ";
    cin >> answer;
    cout << endl;
    

    
    return(answer);
}

int sumOfNums(double input[], int size){
    
    //cout << size << endl;
    //sum function
    double sum = 0;
    for (int j = 0; j < size; j++ ){
        sum = sum + input[j];
    }
    cout << sum;
    
    return(sum);
}


double meanOfNums(double input[], int size){
    double mean;
    double sum = 0;
    for (int j = 0; j < size; j++ ){
        sum = sum + input[j];
    }
    
    mean = sum / size;
    cout << mean;
    
    return(mean);
}

double sdOfNums(double input[], int size){
    double mean;
    double sum = 0;
    for (int j = 0; j < size; j++ ){
        sum = sum + input[j];
    }
    
    mean = sum / size;
    cout << mean;
    
    return(mean);
}


//This function gets input from user and reflect it to input[] and size in main()
void getInput(double input[], int &size, int sizeMax)
{
	cout << "Enter a series of up to 10 positive numbers. Terminate the list with a -1." << endl;
	cin;
	
	//Initiazize the array
	for( int j = 0; j < sizeMax; ++j) 
	{
    	input[j] = -1;
	}
	
	//take in input
	for( int i = 0; i < sizeMax; ++i) 
	{
    	double tmp = 0;
    	cin >> tmp;
    	if( tmp == -1 ) {   // if the input is equal to -1, then record size and terminate the loop
    		size = i;
        	break;
    	}
       	input[ i ] = tmp;
       	size = i;
	}
	
	//echo input	
	cout << "your input: ";
	for( int i = 0; i < size; ++i) {
    	cout << input[i] << " ";
	}
	cout << endl;
	
	//display the size
	cout << size << " number(s) entered\n\n" << endl;
}


// This function sort a given array. The result is reflecrted in main() 
void ascendingSort(double input[], int size)
{
	int result[size];	
	for (int i = 0; i < size; i++)
	{
		for( int j = i + 1; j < size; j++)
		{
			if(input[i] > input[j])
			{
				double temp;
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}	
	}
 }
 
 // returns median (NOTE: works only when the array is sorted)
double median(double input[], int size)
{
	if (size % 2 != 0)
	{
		return 	input[size/2];
	}
	else
	{
		double mean = 0;
		mean = (input[size/2 - 1] + input[size/2]) / 2.0;
		return mean;
	}
} 

//*********************************************** START HERE ***********************************************//


int main()
{
	int sizeMax = 10;
	double input[sizeMax];
	int size = 0;
	int userAnswer;

    // primpt the user to type in a set of numbers. Terminate the list with a -1 
	getInput(input, size, sizeMax);                      //get input 
	ascendingSort(input, size);                          //sort (After these lines, numbers in input[] are in ascending order )
	
//////TEST OUTPUT (please erase before submission)/////////////////////////////													 
	cout << "checking sort result: ";
	for(int i = 0; i < size; i++)
	{
		cout << input[i] << " ";
	} 
	cout <<"\n\n\n" << endl;	
//////////////////////////////////////////////////////////////////////////////
   
	// prompt the user what they would like to do (this menu can be seen after or before prompting the user to input thier numbers
	userAnswer = mainMenu();
    
    switch(userAnswer) 
	{
  		case 1:
    		cout << "1. Display the values in ascending order\n\n";
    		cout << "Answer: ";
			for (int i = 0; i < size; i++)
			{
				cout << input[i] << " ";
			}
			cout << endl;
			
    		break;
  		
		case 2:
			cout << "2. Display the smallest value entered\n\n";
    		cout << "Answer: " << input[0] << endl;	
    		break;
    	case 3:
    		cout << "3. Display the largest value entered\n\n";
    		cout << "Answer: "  << input[size -1] << endl;
			break;
    	case 4:
    		cout << "4. Display the range of the values entered\n\n";
    		cout << "Answer: " << input[size - 1] - input[0] << endl;
			break;
    	case 5:
    		cout << "5. Display the sum of the values entered\n\n";
    		cout << "Answer: " << sumOfNums(input, size) << endl;
			break;
    	case 6:
    		cout << "6. Display the mean (average value)\n\n";
    		cout << "Answer: " << meanOfNums(input, size) << endl;
			break;
    	case 7:
    		cout << "7. Display the median value\n\n";
    		cout << "Answer: " <<median(input, size) << endl;
			break;
    	case 8:
    		cout << "8. Display the sample standard deviation\n\n";
    		// Answer for Q8 comes here
			break;
  		default:
    		cout << "default";
    		// Action for 9 and other invalid numbers comes here
    		break;
	}

    
    


return 0;
}
//Enter a series of up to 10 positive numbers. Terminate the list with a -1.
//1. ascending order
//2. smallest value entered
//3. largest value entered
//4. range
//5. sum of the value entered
//6. the mean
//7. median
//8. standard deviation
//9. exit
