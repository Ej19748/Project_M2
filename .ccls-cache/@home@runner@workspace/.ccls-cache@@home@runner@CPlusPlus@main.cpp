#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
// Structure to store student data
struct Student {
string name;
int idNum;
int* tests;
double average;
char grade;
};
// Function to read student data from file
void calculateGrades(Student* students, int numStudents, int numTests);
void displayGrades(const Student* students, int numStudents);
int main()
{
  ifstream inputFile("test_data.txt");
  if (!inputFile) {
    cout << "Error opening file." << endl;
    return 1;
  }
  int numStudents, numTests;
  inputFile >> numStudents >> numTests;
  // Dynamically allocate memory for student data
  Student* students = new Student[numStudents];
  // Read student data from file
  for (int i = 0; i < numStudents; i++)
    {
      inputFile >> students[i].name >> students[i].idNum;
      // Dynamically allocate memory for test scores
      students[i].tests = new int[numTests];
      for (int j = 0; j < numTests; j++)
        {
          inputFile >> students[i].tests[j];
        }
    }
  inputFile.close();
  // Calculate average test score and grade for each student
  calculateGrades(students, numStudents, numTests);
  // Display student data and grades
  displayGrades(students, numStudents);
  // Free dynamically allocated memory
  for (int i = 0; i < numStudents; i++)
    {
      delete[] students[i].tests;
    }
  delete[] students;
  return 0;
}
// Function to calculate average test score and grade for each student
void calculateGrades(Student* students, int numStudents, int numTests)
{
  for (int i = 0; i < numStudents; i++)
    {
      int total = 0;
      for (int j = 0; j < numTests; j++)
        {
          total += students[i].tests[j];
        }
      // Calculate average test score
      students[i].average = static_cast<double>(total) / numTests;
      if (students[i].average >= 91)
        students[i].grade = 'A';
      else if (students[i].average >= 81)
        students[i].grade = 'B';
      else if (students[i].average >= 71)
        students[i].grade = 'C';
      else if (students[i].average >= 61)
        students[i].grade = 'D';
      else
        students[i].grade = 'F';
    }
}
// Function to display student data and grades
void displayGrades(const Student* students, int numStudents)
{
  cout << left << setw(12) << "Name" << setw(8) << "ID" << setw(10) << "Average" << setw(8) << "Grade" << endl;
  for (int i = 0; i < numStudents; i++)
    cout << left << setw(12) << students[i].name << setw(8) << students[i].idNum << setw(10) << fixed << setprecision(2) << students[i].average << students[i].grade << endl;
}