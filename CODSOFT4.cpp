//TASK 3 MANAGING STUDENT GRADE


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> studentNames;
    vector<double> studentGrades;

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Input student names and grades
    for (int i = 0; i < numStudents; ++i) {
        string name;
        double grade;

        cout << "Enter name for student " << i + 1 << ": ";
        cin >> name;

        cout << "Enter grade for " << name << ": ";
        cin >> grade;

        studentNames.push_back(name);
        studentGrades.push_back(grade);
    }

    // Calculate average grade
    double sum = 0;
    for (double grade : studentGrades) {
        sum += grade;
    }
    double average = sum / numStudents;

    // Find highest and lowest grades
    auto minMax = minmax_element(studentGrades.begin(), studentGrades.end());
    double lowestGrade = *minMax.first;
    double highestGrade = *minMax.second;

    // Display results
    cout << "\nAverage Grade: " << average << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}