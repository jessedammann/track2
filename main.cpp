#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

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



int main()
{
int sizeMax = 10;
int input[sizeMax];
int size = 0;

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
    sdOfNums(input, size)
    /*int input[] = {5,5,5,5,5,5,5,5,5,5};
    double size = sizeof(input);
    cout << size << endl;
    //sum function
    double sum =0;
    for (int j = 0; j < size; j++ ){
        sum = sum + input[j];
    }
    cout << sum;
    
    // mean function
    double mean;
    mean = sum / size;
    
    cout << mean;*/
    
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
