#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student {
string name;
int idNum;
int* tests;
double average;
char grade;
};
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
  Student* students = new Student[numStudents];
  for (int i = 0; i < numStudents; i++)
    {
      inputFile >> students[i].name >> students[i].idNum;
      students[i].tests = new int[numTests];
      for (int j = 0; j < numTests; j++)
        {
          inputFile >> students[i].tests[j];
        }
    }
  inputFile.close();
  calculateGrades(students, numStudents, numTests);
  displayGrades(students, numStudents);
  for (int i = 0; i < numStudents; i++)
    {
      delete[] students[i].tests;
    }
  delete[] students;
  return 0;
}
void calculateGrades(Student* students, int numStudents, int numTests)
{
  for (int i = 0; i < numStudents; i++)
    {
      int total = 0;
      for (int j = 0; j < numTests; j++)
        {
          total += students[i].tests[j];
        }
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
void displayGrades(const Student* students, int numStudents)
{
  cout << left << setw(12) << "Name" << setw(8) << "ID" << setw(10) << "Average" << setw(8) << "Grade" << endl;
  for (int i = 0; i < numStudents; i++)
    cout << left << setw(12) << students[i].name << setw(8) << students[i].idNum << setw(10) << fixed << setprecision(2) << students[i].average << students[i].grade << endl;
}