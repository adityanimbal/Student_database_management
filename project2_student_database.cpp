#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char data[15]; // max length of data to be 15
    int n = 0, option = 0, count_n = 0;
    string empty = "00";
    string examID = "";
    ifstream f("Example.txt"); // Database is stored in file
    string line;
    for (int i = 0; std::getline(f, line); ++i)
    {
        // total number of lines in the file
        count_n++;
    }

    while (option != 6)
    {
        cout << "\nAvailable operations: \n1. Add New "
                "Students\n2."
             << "Student Login\n3. Faculty Login\n4. "
                "ExamID Login\n5. Admin View\n"
             << "6. Exit\nEnter option: ";
        cin >> option;

        if (option == 1)
        {
            cout << "Enter the number of students: ";
            cin >> n;

            count_n = count_n + n;

            for (int i = 0; i < n; i++)
            {
                ofstream outfile;
                outfile.open("Example.txt", ios::app);
                // The entire data of a single student is
                // stored line-by-line.
                cout << "Enter your registration number: ";
                cin >> data;
                outfile << data << "\t";

                cout << "Enter your name: ";
                cin >> data;
                int len = strlen(data);

                while (len < 15)
                {
                    data[len] = ' ';
                    len = len + 1;
                }
                outfile << data << "\t";
                // Inserting empty data initially into the
                // file
                outfile << empty << "\t";
                outfile << empty << "\t";

                cout << "Enter your ExamID ID: ";
                cin >> examID;

                outfile << examID << endl;
            }
        }

        else if (option == 2)
        {
            char regno[15];
            cout << "Enter your registration number: ";
            cin >> regno;
            ifstream infile;
            int check = 0;
            infile.open("Example.txt", ios::in);

            // This loop prints out the data according to
            // the registration number specified.
            while (infile >> data)
            {
                if (strcmp(data, regno) == 0)
                {
                    cout
                        << "\nRegistration Number: " << data
                        << endl;
                    infile >> data;
                    cout << "Name: " << data << endl;

                    infile >> data;
                    cout << "EE1234 mark: " << data
                         << endl;

                    infile >> data;
                    cout << "EE5678 mark: " << data
                         << endl;

                    infile >> data;
                    cout << "ExamID: " << data << endl;

                    infile.close();
                    check = 1;
                }
            }

            if (check == 0)
            {
                cout << "No such registration number found!"
                     << endl;
            }
        }

        // This loop is used to view and add marks to the
        // database of a student.
        else if (option == 3)
        {
            char subcode[7];
            cout << "Enter your subject code: ";
            cin >> subcode;
            string code1 = "EE1234", code2 = "EE5678",
                   mark = "";
            ifstream infile;
            int check = 0;

            cout << "\nAvailable operations: \n1. Add data "
                    "about marks\n"
                 << "2. View data\nEnter option: ";
            cin >> option;

            if (option == 1)
            {
                cout
                    << "Warning! You would need to add mark"
                    << "details for all the students!"
                    << endl;
                for (int i = 0; i < count_n; i++)
                {
                    fstream file("Example.txt");

                            if (strcmp(subcode, code1.c_str()) == 0)
                    {
                        file.seekp(26 + 37 * i,
                                   std::ios_base::beg);
                        cout << "Enter the mark of student#"
                             << (i + 1) << " : ";
                        cin >> mark;
                        file.write(mark.c_str(), 2);
                    }

                    if (strcmp(subcode, code2.c_str()) == 0)
                    {
                        file.seekp(29 + 37 * i,
                                   std::ios_base::beg);
                        cout << "Enter the mark of student#"
                             << (i + 1) << " : ";
                        cin >> mark;
                        file.write(mark.c_str(), 2);
                    }
                }
            }

            // This loop is used to view marks of a student.
            // The extra infile commands have been used to
            // get a specific mark only since the data has
            // been separated by a tabspace.

            else if (option == 2)
            {
                infile.open("Example.txt", ios::in);
                if (strcmp(subcode, code1.c_str()) == 0)
                {
                    cout << "Registration number - Marks\n"
                         << endl;
                    while (infile >> data)
                    {
                        cout << data;
                        infile >> data;
                        infile >> data;
                        cout << " - " << data << endl;
                        infile >> data;
                        infile >> data;
                        check = 1;
                    }
                }

                infile.close();
                infile.open("Example.txt", ios::in);

                if (strcmp(subcode, code2.c_str()) == 0)
                {
                    cout << "Registration number - Marks\n"
                         << endl;
                    while (infile >> data)
                    {
                        cout << data;
                        infile >> data;
                        infile >> data;
                        infile >> data;
                        cout << " - " << data << endl;
                        infile >> data;
                        check = 1;
                    }
                }
            }

            infile.close();

            if (check == 0)
            {
                cout << "No such subject code found!"
                     << endl;
            }
        }
        else if (option == 4)  //displaying the info of the students under the same examID.
        {
            char procid[7];
            cout << "Enter your examID: ";
            cin >> procid;
            int check = 0;
            char temp1[100], temp2[100], temp3[100];
            char temp4[100], id[100];
            ifstream infile;
            infile.open("Example.txt", ios::in);

            while (infile >> temp1)
            {
                infile >> temp2;
                infile >> temp3;
                infile >> temp4;
                infile >> id;

                if (strcmp(id, procid) == 0)
                {
                    cout << "\nRegistration Number: "
                         << temp1 << endl;
                    cout << "Name: " << temp2 << endl;
                    cout << "EE1234 Mark: " << temp3
                         << endl;
                    cout << "EE5678 Mark: " << temp4
                         << endl;
                    check = 1;
                }
            }

            if (check == 0)
            {
                cout << "No such examID found!" << endl;
            }
        }

        else if (option == 5) //loop for admin view
        {
            char password[25];
            cout << "Enter the admin password: ";
            cin >> password;
            string admin_pass = "admin"; //passsword: admin

            if (strcmp(password, admin_pass.c_str()) == 0)
            {
                cout << "Reg No.       "
                        "\tName\tEE1234\tEE5678\tExamID "
                        "ID"
                     << endl;
                ifstream infile;
                infile.open("Example.txt", ios::in);
                char data[20];

                while (infile >> data)
                {
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << endl;
                }
            }
        }
    }
}