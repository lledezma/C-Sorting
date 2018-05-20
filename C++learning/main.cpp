//#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;


double AverageScore(double Total, int NumScores);
void selectionSort(double array[], int size);
void showArray(double array[], int size);


int main()
{
    double *scores, // To dynamically allocate an array of scores
    total = 0.0;   // Accumulator
    int numScores,   // Number of Test Scores
    count;     // Counter variable
    
    
    
    cout << "How many Test scores do you want ";
    cout << "to average? ";
    cin >> numScores;
    
    scores = new double[numScores];
    cout << "Enter your Test scores.\n";
    for (count = 0; count < numScores; count++)
    {
        cout << "Test " << (count + 1) << ": ";
        cin >> scores[count];
    }
    
    for (count = 0; count < numScores; count++)
    {
        total += scores[count];
    }
    cout << "You entered the following scores: \n";
    showArray(scores,numScores);
    selectionSort(scores,numScores);
    cout << "The following scores will be averaged: \n";
    showArray(scores,numScores);
    
    cout << fixed << showpoint << setprecision(2);
    cout << "Your average test score is: " << AverageScore(total,numScores) << endl;
    delete [] scores; //Release the momory
    scores = 0; // Make scores point to null.
    system("PAUSE");
    return 0;
}

double AverageScore(double Total, int NumScores)
{
    return Total / NumScores;
    
}

void selectionSort(double array[], int size)
{
    int startScan, minIndex, minValue;
    
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}
void showArray(double array[], int size)
{
    for (int count = 0; count < size; count++)
        cout << array[count] << " ";
    cout << endl;
}

