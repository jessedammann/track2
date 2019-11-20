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

int sumOfNums(int input[], int size){
    
    //cout << size << endl;
    //sum function
    double sum = 0;
    for (int j = 0; j < size; j++ ){
        sum = sum + input[j];
    }
    cout << sum;
    
    return(sum);
}


int meanOfNums(int input[], int size){
    double mean;
    double sum = 0;
    for (int j = 0; j < size; j++ ){
        sum = sum + input[j];
    }
    
    mean = sum / size;
    cout << mean;
    
    return(mean);
}

int sdOfNums(int input[], int size){
    double mean;
    double sum = 0;
    for (int j = 0; j < size; j++ ){
        sum = sum + input[j];
    }
    
    mean = sum / size;
    cout << mean;
    
    return(mean);
}


//*********************************************** START HERE ***********************************************//


int main()
{
int sizeMax = 10;
int input[sizeMax];
int size = 0;
   
// prompt the user what they would like to do (this menu can be seen after or before prompting the user to input thier numbers
mainMenu();
    
cout << "Enter a series of up to 10 positive numbers. Terminate the list with a -1." << endl;
cin;

for(int j = 0; j < sizeMax; ++j){
    input[j] = -1;
}

//take input
for( int j = 0; j < sizeMax; ++j ){
    int tmp = 0;
    cin >> tmp;
    if( tmp == -1 ) {
        size = j;
        break;
    }
    input[ j ] = tmp;
}

    sumOfNums(input, size);
    meanOfNums(input, size);


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
