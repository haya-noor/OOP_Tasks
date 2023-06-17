#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student_SGPA
{
    string name, degree_program, id;
    int courses;
    int *course_marks; // Dynamic array
    float sgpa;

    void Student_Info()
    {
        cout << "Enter the number of students: ";
        int size;
        cin >> size;

        Student_SGPA *students = new Student_SGPA[size];

        for (int i = 0; i < size; i++)
        {
            cout << "Enter the details of student " << i + 1 << ":\n";

            cout << "Enter the id: ";
            cin.ignore();
            getline(cin, students[i].id);

            cout << "Enter name: ";
            getline(cin, students[i].name);

            cout << "Enter degree program: ";
            getline(cin, students[i].degree_program);

            cout << "Enter number of courses: ";
            cin >> students[i].courses;

            students[i].course_marks = new int[students[i].courses];

            for (int j = 0; j < students[i].courses; j++)
            {
                cout << "Enter marks of course " << j + 1 << ": ";
                cin >> students[i].course_marks[j];
            }

            students[i].sgpa = Calculate_SGPA(students[i]);

            delete[] students[i].course_marks;
        }

        Sort_Students(students, size);
        Display_Students(students, size);

        delete[] students;
    }

    float Calculate_SGPA(const Student_SGPA &student)
    {
        // for simplicity, we take the CH (credit hours) to be 3 for each course
        int total_CH = student.courses * 3;
        float total_GPA = 0.0;
        for (int i = 0; i < student.courses; i++)
        {
            total_GPA += Calculate_GPA(student.course_marks[i]) * 3;
        }

        return total_GPA / total_CH;
    }

    double Calculate_GPA(int marks)
    {
        double gpa;
        if (marks > 86)
            gpa = 4;
        else if (marks > 82 && marks <= 86)
            gpa = 3.67;
        else if (marks > 78 && marks <= 82)
            gpa = 3.33;
        else if (marks > 74 && marks <= 78)
            gpa = 3;
        else if (marks > 70 && marks <= 74)
            gpa = 2.67;
        else if (marks > 66 && marks <= 70)
            gpa = 2.33;
        else if (marks > 50 && marks <= 66)
            gpa = 2;
        else
            gpa = 1.67;

        return gpa;
    }

    void Sort_Students(Student_SGPA *students, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (students[j].sgpa < students[j + 1].sgpa)
                {
                    // Swap the positions of students[j] and students[j+1]
                    Student_SGPA temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    void Display_Students(const Student_SGPA *students, int size)
    {
        cout << "S.No \t ID \t Name \t Degree Program \tSGPA \n";
        for (int i = 0; i < size; i++)
        {
        cout << i + 1 << "\t" << students[i].id << "\t" << students[i].name << "\t" << students[i].degree_program << setw(15) << students[i].sgpa << "\n";
        }

        cout<<"Best of students is: \n";
        cout<<"1"<< "\t" << students[0].id << "\t" << students[0].name << "\t" << students[0].degree_program << setw(15) << students[0].sgpa << "\n"; 
    }
};
    int main()
    {
        Student_SGPA s;
        s.Student_Info();
        return 0;
    }
