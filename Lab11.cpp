// Joshua Seibt, 3/31/2026
// Welcome to my program that takes a text file filled with numbers and outputs relevent data about them!
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 100;

// Function prototypes
int readNumbers(const string& filename, double arr[], int maxSize);
void analyzeNumbers(const double arr[], int count);

// This function takes a file name, opens the file, and takes the numbers in the file.  
int main()
{
	double numbers[SIZE];
	string filename;

	cout << "Enter the file name: ";
	cin >> filename;

	int count = readNumbers(filename, numbers, SIZE);

	if (count == 0)
	{
		cout << "No data read from file.\n";
		return 0;
	}

	analyzeNumbers(numbers, count);

	return 0;
}

// This function reads numbers from the file into the array
int readNumbers(const string& filename, double arr[], int maxSize)
{
	ifstream inputFile(filename);
	int count = 0;

	if (!inputFile)
	{
		cout << "Error opening file.\n";
		return 0;
	}

	while (count < maxSize && inputFile >> arr[count])
	{
		count++;
	}

	inputFile.close();
	return count;
}

// This function looks at and displays statistics
void analyzeNumbers(const double arr[], int count)
{
	double lowest = arr[0];
	double highest = arr[0];
	double total = 0;

	// Finds min, max, and total
	for (int i = 0; i < count; i++)
	{
		if (arr[i] < lowest)
			lowest = arr[i];

		if (arr[i] > highest)
			highest = arr[i];

		total += arr[i];
	}

	double average = total / count;

	// Computes the standard deviation
	double sumSquaredDiffs = 0;
	for (int i = 0; i < count; i++)
	{
		sumSquaredDiffs += pow(arr[i] - average, 2);
	}

	double stdDev = sqrt(sumSquaredDiffs / count);

	// Outputs answers
	cout << "\nResults:\n";
	cout << "Lowest number: " << lowest << endl;
	cout << "Highest number: " << highest << endl;
	cout << "Total: " << total << endl;
	cout << "Average: " << average << endl;
	cout << "Standard Deviation: " << stdDev << endl;
}