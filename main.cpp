/**********************************************************************************************************************
In-Class Group Project TRACK 2
Name: Laura Yang, Jesse Dammann and Shigeki Kamata
Date: 11/24/2019
***********************************************************************************************************************/

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

//*********************************************** Function Protopypes **************************************//
int mainMenu();
double sumOfNums(double input[], int size);
double meanOfNums(double input[], int size);
double sdOfNums(double input[], int size);
void getInput(double input[], int &size, int sizeMax);
void ascendingSort(double input[], int size);
double median(double input[], int size);
void displayResult(int userAnswer, double input[], int size);
//*********************************************** START HERE ***********************************************//

int main()
{
    int sizeMax = 10;
    double input[sizeMax];
    int size = 0;
    int userAnswer;

    cout << "CS161 Lab7 Track 2 – Menu driven calculator using functions." << endl;
	
    // prompt the user to type in a set of numbers. Terminate the list with a -1
    getInput(input, size, sizeMax);                      //get input
    ascendingSort(input, size);                          //sort (After these lines, numbers in input[] are in ascending order )
	
    cout << setprecision(2) << fixed;
       
    while (userAnswer != 9) {
                         
        // prompt the user what they would like to do (this menu can be seen after or before prompting the user to input thier numbers
        userAnswer = mainMenu();
        //display the answer to the question of user's choice
        displayResult(userAnswer, input, size);
    }
	
    cout << "GoodBye!";
    
return 0;
}



//***********************************************Difinitions of Function ***********************************************//

int mainMenu() {
    int answer = 0;

    cout << " Select an option:" << endl;
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

double sumOfNums(double input[], int size){
    double sum = 0;

    for (int j = 0; j < size; j++ ){
        sum = sum + input[j];
    }
    
    return(sum);
}


double meanOfNums(double input[], int size){
    double mean;
    mean = sumOfNums(input, size) / size;
    return(mean);
}

double sdOfNums(double input[], int size){
    double mean;
    double step1 = 0;
    double sd = 0;

    mean = meanOfNums(input, size);
    
    for (int j = 0; j < size; j++ ){
            step1 = step1 + pow((input[j] - mean), 2);
    }
    sd = sqrt(step1/(size - 1));
    
    return(sd);
}

//This function gets input from user and reflect it to input[] and size in main()
void getInput(double input[], int &size, int sizeMax)
{
    cout << "Enter a series of up to 10 positive numbers. \n Terminate the list with a -1." << endl;
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
}


// This function sorts a given array. The result is reflecrted in main()
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
        return     input[size/2];
    }
    else
    {
        double mean = 0;
        mean = (input[size/2 - 1] + input[size/2]) / 2.0;
        return mean;
    }
}

void displayResult(int userAnswer, double input[], int size)
{
    switch(userAnswer)
    {
        case 1:
            cout << "The values entered are: ";
            
        	for (int i = 0; i < size; i++)
            {
                cout << input[i];
                if (i < (size - 1))
                {
                	cout << ", ";
				}
            }
            cout << endl;
                
            break;
              
        case 2:
            cout << "The smallest value entered is ";
            cout << input[0] << endl;
            break;
        case 3:
            cout << "The largest value entered is ";
            cout << input[size -1] << endl;
        	break;
        case 4:
            cout << "The range of the values entered is ";
            cout << input[size - 1] - input[0] << endl;
            break;
        case 5:
            cout << "The sum = ";
            cout << sumOfNums(input, size) << endl;
            break;
        case 6:
            cout << "The mean = ";
            cout << meanOfNums(input, size) << endl;
            break;
        case 7:
            cout << "The median = ";
            cout <<median(input, size) << endl;
            break;
        case 8:
            cout << "The sample standard deviation = ";
            cout << sdOfNums(input, size) << endl;
            break;
	case 9:
	    break;
        default:
            cout << "Invalid input. Please Enter a number 1 - 9.";
            break;
	}
	cout << endl;
}

