#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to hold subject details
struct Subject {
    string name;
    int credits;
    float marks;
    int gradePoint;
};

// Function to convert marks to grade point (10-point scale)
int getGradePoint(float marks) {
    if (marks >= 90 && marks <= 100) return 10;
    else if (marks >= 80) return 9;
    else if (marks >= 70) return 8;
    else if (marks >= 60) return 7;
    else if (marks >= 50) return 6;
    else if (marks >= 40) return 5;
    else return 0;
}

int main() {
    vector<Subject> subjects;
    int numSubjects;
    char addMore;

    cout << "===== GPA CALCULATOR =====" << endl;

    // Input subjects one by one
    do {
        Subject sub;
        cout << "\nEnter subject name: ";
        cin.ignore(); // clear newline from previous input
        getline(cin, sub.name);

        cout << "Enter credits (e.g., 3, 4): ";
        cin >> sub.credits;

        cout << "Enter marks obtained (0-100): ";
        cin >> sub.marks;

        // Validate marks range
        if (sub.marks < 0 || sub.marks > 100) {
            cout << "Invalid marks! Please enter between 0 and 100.\n";
            continue;
        }

        sub.gradePoint = getGradePoint(sub.marks);
        subjects.push_back(sub);

        cout << "Add another subject? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');

    // Compute total credits and weighted sum
    int totalCredits = 0;
    float totalWeightedPoints = 0;

    for (const auto& sub : subjects) {
        totalCredits += sub.credits;
        totalWeightedPoints += sub.credits * sub.gradePoint;
    }

    float gpa = (totalCredits > 0) ? (totalWeightedPoints / totalCredits) : 0;

    // Display Marksheet
    cout << "\n\n========== MARKSHEET ==========\n";
    cout << left << setw(25) << "Subject" 
         << setw(10) << "Credits" 
         << setw(10) << "Marks" 
         << setw(12) << "Grade Point" << endl;
    cout << "--------------------------------------------\n";

    for (const auto& sub : subjects) {
        cout << left << setw(25) << sub.name 
             << setw(10) << sub.credits 
             << setw(10) << sub.marks 
             << setw(12) << sub.gradePoint << endl;
    }

    cout << "--------------------------------------------\n";
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Weighted Points: " << totalWeightedPoints << endl;
    cout << fixed << setprecision(2);
    cout << "\n🎓 Your GPA is: " << gpa << " / 10.0" << endl;

    if (gpa >= 9.0) cout << "🏆 Outstanding!";
    else if (gpa >= 8.0) cout << "👍 Very Good!";
    else if (gpa >= 7.0) cout << "📘 Good!";
    else if (gpa >= 6.0) cout << "📚 Satisfactory";
    else if (gpa >= 5.0) cout << "⚠️ Needs Improvement";
    else cout << "❌ Poor performance (consider reappearing)";

    cout << endl;
    return 0;
}