#include <iostream>
#include <string>

using namespace std;

class SGPA_CAL
{
public:
    int num_of_sub, external_sub;
    char ext_ch;
    string sub_name[100], p_sub_name[100], e_sub_name[100];
    int marks[100], pmarks[100], e_marks[100];
    float totalCredit = 0.0, TotalGradePoint = 0.0, credit, grade, gp, SGPA, CGPA;
    float P_totalCredit = 0.0, P_TotalGradePoint = 0.0, E_totalCredit = 0.0, E_TotalGradePoint = 0.0, All_credit = 0.0, All_grades = 0.0;

public:
    // Function to input details of subjects
    void input();

    // Function to display subjects and their marks
    void display();

    // Function to assign credit based on marks
    float Credit(float marks);

    // Function to assign grade based on marks
    float Grade(float marks);

    // Function to calculate and set total credit
    void setCredit();

    // Function to calculate and set total grade points
    void setGradePoint();

    // Function to calculate and display SGPA
    float CalCulateSGPA();

    void External_sub();
    // Function to calculate and display CGPA
    void CalCulateCGPA();
    // calculate and display practical
    void calPractical();
};

// Function to input details of subjects
void SGPA_CAL::input()
{
    cout << "How many subjects: ";
    cin >> num_of_sub;
    for (int i = 0; i < num_of_sub; i++)
    {
        cout << "Enter subject name: ";
        cin >> sub_name[i];
        cout << "Enter marks for subject " << sub_name[i] << ": ";
        cin >> marks[i];
    }
}

void SGPA_CAL ::External_sub()
{
    cout << "Do you have any external theory subjects? (y/n): ";
    cin >> ext_ch;
    if (ext_ch == 'Y' || ext_ch == 'y')
    {
        cout << "How many external subjects : ";
        cin >> external_sub;
        for (int i = 0; i < external_sub; i++)
        {
            cout << "Enter subject name: ";
            cin >> e_sub_name[i];
            cout << "Enter marks for subject " << p_sub_name[i] << ": ";
            cin >> e_marks[i];
            e_marks[i] *= 2;
        }
        cout << "Marks : " << endl;
        cout << " Subjects Names and Marks Of : " << num_of_sub << " Subjects " << endl;
        for (int i = 0; i < num_of_sub; i++)
        {
            cout << sub_name[i] << ": " << marks[i] << "\t";
        }
        cout << endl;
        for (int i = 0; i < external_sub; i++)
        {
            E_totalCredit += 2;
        }
        for (int i = 0; i < external_sub; i++)
        {
            E_TotalGradePoint += 2 * Grade(e_marks[i]);
        }
    }
    else
    {
        return;
    }
}
// Function to display subjects and their marks
void SGPA_CAL::display()
{
    cout << " Subjects Names and Marks Of : " << num_of_sub << " Subjects " << endl;
    for (int i = 0; i < num_of_sub; i++)
    {
        cout << sub_name[i] << ": " << marks[i] << "\t";
    }
    cout << endl;
}

// Function to assign credit based on marks
float SGPA_CAL::Credit(float marks)
{
    if (marks <= 100 && marks >= 36)
    {
        return 4.0;
    }
    else
    {
        return 0.0; // No credit for marks below 40
    }
}

// Function to assign grade based on marks
float SGPA_CAL::Grade(float marks)
{
    if (marks <= 100 && marks >= 90)
    {
        return 10.0;
    }
    else if (marks <= 90 && marks >= 80)
    {
        return 9.0;
    }
    else if (marks <= 80 && marks >= 70)
    {
        return 8.0;
    }
    else if (marks <= 70 && marks >= 60)
    {
        return 7.0;
    }
    else if (marks <= 60 && marks >= 50)
    {
        return 6.0;
    }
    else if (marks <= 50 && marks >= 40)
    {
        return 5.0;
    }
    else
    {
        return 0.0; // No grade for marks below 40
    }
}

// Function to calculate and set total credit
void SGPA_CAL::setCredit()
{
    for (int i = 0; i < num_of_sub; i++)
    {
        totalCredit += Credit(marks[i]);
    }
}

void SGPA_CAL::calPractical()
{
    int n;

    cout << "Enter the marks of practical outoff 50  : " << endl;
    cout << "How many practical subject : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter subject name: ";
        cin >> p_sub_name[i];
        cout << "Enter marks for subject " << p_sub_name[i] << ": ";
        cin >> pmarks[i];
        pmarks[i] *= 2;
    }
    cout << "MArks : " << endl;
    display();
    for (int i = 0; i < n; i++)
    {
        P_totalCredit += 2;
    }
    for (int i = 0; i < n; i++)
    {
        P_TotalGradePoint += 2 * Grade(pmarks[i]);
    }
}
// Function to calculate and set total grade points
void SGPA_CAL::setGradePoint()
{
    for (int i = 0; i < num_of_sub; i++)
    {
        float credit = Credit(marks[i]);
        float grade = Grade(marks[i]);
        if (credit == 0 || grade == 0)
        {
            TotalGradePoint = 0.0;
            cout << "Total Grade point of theory : " << TotalGradePoint << endl;
            return;
        }
        TotalGradePoint += credit * grade;
    }
}

// Function to calculate and display SGPA
float SGPA_CAL::CalCulateSGPA()
{
    if (totalCredit == 0.0)
    {
        return 0.0; // Avoid division by zero
    }
    if (ext_ch == 'Y' || ext_ch == 'y')
    {
        cout << "Total Credit of External Subject : " << E_totalCredit << endl;
        cout << "Total Grade Point of External Subject: " << E_TotalGradePoint << endl;
        cout << "Total Credit of practical: " << P_totalCredit << endl;
        cout << "Total Grade Point of Practical: " << P_TotalGradePoint << endl;
        cout << "Total Grade point of theory : " << TotalGradePoint << endl;
        cout << "Total Credit " << totalCredit << endl;
        All_credit = totalCredit + P_totalCredit + E_totalCredit;
        All_grades = TotalGradePoint + P_TotalGradePoint + E_TotalGradePoint;
        cout << "All Credit: " << All_credit << "\t All Grade: " << All_grades << "\n";

        SGPA = (TotalGradePoint + P_TotalGradePoint + E_TotalGradePoint) / (totalCredit + P_totalCredit + E_totalCredit); // Formula: SGPA = Total Grade Points / Total Credits
        cout << "SGPA " << SGPA << endl;
        return SGPA;
    }
    else
    {
        cout << "Total Credit of practical: " << P_totalCredit << endl;
        cout << "Total Grade Point of Practical: " << P_TotalGradePoint << endl;
        cout << "Total Grade point of theory : " << TotalGradePoint << endl;
        cout << "Total Credit " << totalCredit << endl;

        SGPA = (TotalGradePoint + P_TotalGradePoint) / (totalCredit + P_totalCredit); // Formula: SGPA = Total Grade Points / Total Credits
        cout << "SGPA " << SGPA << endl;
        return SGPA;
    }
}

// Function to calculate and display CGPA
// Function to calculate and display CGPA
void SGPA_CAL::CalCulateCGPA()
{
    int num_of_semesters;
    cout << "Enter the number of semesters: ";
    cin >> num_of_semesters;

    SGPA_CAL semesterCalculators[num_of_semesters];

    for (int i = 0; i < num_of_semesters; i++)
    {
        cout << "Enter details for Semester " << i + 1 << ":" << endl;
        semesterCalculators[i].input();
        semesterCalculators[i].External_sub(); // Add this line to include external subjects
        semesterCalculators[i].calPractical(); // Add this line to include practical subjects
    }

    for (int i = 0; i < num_of_semesters; i++)
    {
        cout << "Details for Semester " << i + 1 << ":" << endl;
        semesterCalculators[i].display();
    }

    for (int i = 0; i < num_of_semesters; i++)
    {
        semesterCalculators[i].setCredit();
        semesterCalculators[i].setGradePoint();

        // Check if the student failed in any subject in the semester
        for (int j = 0; j < semesterCalculators[i].num_of_sub; j++)
        {
            if (semesterCalculators[i].marks[j] < 35)
            {
                cout << "Student failed in Semester " << i + 1 << "." << endl;
                cout << "CGPA: 0.0" << endl;
                return;
            }
        }
    }

    float totalCreditCGPA = 0.0;
    float totalGradePointCGPA = 0.0;

    for (int i = 0; i < num_of_semesters; i++)
    {
        totalCreditCGPA += semesterCalculators[i].totalCredit + semesterCalculators[i].P_totalCredit + semesterCalculators[i].E_totalCredit;
        totalGradePointCGPA += semesterCalculators[i].TotalGradePoint + semesterCalculators[i].P_TotalGradePoint + semesterCalculators[i].E_TotalGradePoint;
    }

    if (totalCreditCGPA == 0.0)
    {
        CGPA = 0.0;
    }
    cout << "Total Credit And Grades of Semester "
         << " is : " << totalCreditCGPA << "\t " << totalGradePointCGPA << endl;

    CGPA = totalGradePointCGPA / totalCreditCGPA; // Formula: CGPA = Total Grade Points / Total Credits
    cout << "CGPA " << CGPA << endl;
}

// Main function
int main()
{
    int ch;
    SGPA_CAL sgpaCalculator;
    SGPA_CAL CGPACalculator;
    cout << "Enter the choice: \n1. SGPA CALCULATOR \n2. CGPA CALCULATOR \n";
    cin >> ch;

    switch (ch)
    {
    case 1:
        sgpaCalculator.input();
        sgpaCalculator.display();
        sgpaCalculator.External_sub();
        sgpaCalculator.calPractical();
        sgpaCalculator.setCredit();
        sgpaCalculator.setGradePoint();
        sgpaCalculator.CalCulateSGPA();
        break;

    case 2:
        CGPACalculator.CalCulateCGPA();
        break;

    default:
        cout << "Invalid Choice";
        break;
    }

    return 0;
}