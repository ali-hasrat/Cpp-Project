/* A C++ Project which involves a saved(private) password in a file 
   and when we enter the right password then we can able to access data inside the file */


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int choice, i = 0;
    string text, old, password1, password2, pass, name, password0, age, branch, user, word, word1,collegename,DOB;
    string creds[2], cp[2];

    cout <<endl<<"      Security System" << endl;

        // Menu options
        cout << " _____________________________" << endl;
        cout << "|        1.Register           |" << endl;
        cout << "|        2.Login              |" << endl;
        cout << "|        3.Change Password    |" << endl;
        cout << "|________4.End Program________|" << endl;

    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice:- ";
        cin >> choice;


        switch (choice)
        {
            case 1: // Register
            {
                cout << "Please enter Username: ";
                cin >> name;
                cout << "Please enter the Password: ";
                cin >> password0;
                cout << "Please Enter your age: ";
                cin >> age;
                cout << "Please Enter your Date of Birth: ";
                cin >> DOB;
                cout << "Please Enter your Branch: ";
                cin >> branch;
                cout << "Please Enter your College Name: ";
                cin >> collegename;

                // Open file in write mode and save user data
                ofstream of1("file.txt");
                if (of1.is_open())
                {
                    of1 << name << endl;
                    of1 << password0;
                    cout << "-------Registration successful-------" << endl;
                    of1.close();
                }
                else
                {
                    cout << "Error: Unable to open file for registration" << endl;
                }
                break;
            }

            case 2: // Login
            {
                i = 0;

                cout << "Please Enter the Username: ";
                cin >> user;
                cout << "Please Enter the password: ";
                cin >> pass;

                // Open file in read mode and check credentials
                ifstream of2("file.txt");
                if (of2.is_open())
                {
                    while (getline(of2, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }

                    if (user == creds[0] && pass == creds[1])
                    {
                        cout << "---------Login Successful---------" << endl<<endl;
                        cout << "Your details are below!" <<endl;
                        cout << "Username: " + name << endl;
                        cout << "Password: " + pass << endl;
                        cout << "Age: " + age << endl;
                        cout << "Date of Birth: "+ DOB <<endl;
                        cout << "Branch: "+ branch <<endl;
                        cout << "College Name: "+ collegename <<endl;
                    }
                    else
                    {
                        cout << "Incorrect username or Password. Please provide correct credentials." << endl;
                    }

                    of2.close();
                }
                else
                {
                    cout << "Error: Unable to open file for login" << endl;
                }
                break;
            }

            case 3: // Change Password
            {
                i = 0;

                // Open original file for reading and a temporary file for writing
                ifstream of0("file.txt");
                ofstream of1("temp.txt");

                cout << "Enter the Old Password: ";
                cin >> old;

                if (of0.is_open() && of1.is_open())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }

                    if (old == cp[1])
                    {
                        cout << "Enter your new Password: ";
                        cin >> password1;
                        cout << "Enter Your Password again: ";
                        cin >> password2;

                        if (password1 == password2)
                        {
                            // Write updated password to temporary file
                            of1 << cp[0] << endl;
                            of1 << password1;
                            cout << "Password Changed successfully" << endl;
                        }
                        else
                        {
                            cout << "Passwords do not match. Password remains unchanged." << endl;
                            of1 << cp[0] << endl;
                            of1 << cp[1];
                        }
                    }
                    else
                    {
                        cout << "Please Enter a valid Old Password. Password remains unchanged." << endl;
                        of1 << cp[0] << endl;
                        of1 << cp[1];
                    }

                    of0.close();
                    of1.close();

                    // Rename temp file to original file and replace it
                    remove("file.txt");
                    rename("temp.txt", "file.txt");
                }
                else
                {
                    cout << "Error: Unable to open files for password change" << endl;
                }
                break;
            }

            case 4: // End Program
            {
                cout << "Thank You. Exiting Program." << endl;
                break;
            }

            default: // Invalid Choice
            {
                cout << "Invalid Choice. Please try again." << endl;
            }
        }

    } 
    while (choice != 4);
    return 0;
}
