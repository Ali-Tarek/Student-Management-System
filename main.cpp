#include "BST.h"
#include "AVL.h"
#include "student.h"
#include "Maxheap.h"
using namespace std;

int main()
{


    bool stayInOuterLoop = true;

    do{
        cout << "Choose Data Structure:\n";
        cout << "1. BST\n";
        cout << "2. AVL\n";
        cout << "3. Min Heap\n";
        cout << "4. Max Heap\n";
        cout << "5. Exit program\n";

        int option; cin >> option;


        switch (option) {

            case 1:{
                bool stayInInnerLoop = true;
                BST students;
                cout << "\n((Second Menu - choice 1 BST))\n";

                do{

                    cout << "Choose one of the following options:\n";
                    cout << "1. Add student\n";
                    cout << "2. Remove student\n";
                    cout << "3. Search student\n";
                    cout << "4. Print All (sorted by id)\n";
                    cout << "5. Return to main menu\n\n";

                    cout << "Enter number of option: ";
                    int internalOption; cin >> internalOption;
                    cout << '\n';


                    switch (internalOption) {
                        case 1:{
                            student s; cin >> s;

                            students.insert(s);
                            cout << "The student is added.\n\n";
                            break;
                        }
                        case 2:{

                            int id;
                            cout << "Id: ";
                            cin >> id;

                            if(students.has(id)){
                                cout << "Student is found.\n";
                                student removedStudent = students.search(id);
                                cout << removedStudent;
                                students.remove(removedStudent);
                                cout << "Student is deleted.\n\n";
                            }

                            else{
                                cout << "Student is not found.\n\n";
                            }

                            break;
                        }
                        case 3:{

                            int id;
                            cout << "Id: ";
                            cin >> id;

                            if(students.has(id)){
                                cout << "Student is found.\n";
                                cout << students.search(id) << "\n\n";
                            }

                            else{
                                cout << "Student is not found.\n\n";
                            }


                            break;
                        }
                        case 4:{

                            if(students.empty())
                                cout << "No students.\n\n";
                            else {
                                cout << "Print " << students.size() << " Students.\n\n";
                                students.inorder();
                            }

                            break;
                        }
                        case 5:{
                            stayInInnerLoop = false;
                            break;
                        }
                    }

                }while(stayInInnerLoop);

                break;
            }

            case 2:{

                bool stayInInnerLoop = true;
                AVL students;
                cout << "\n((Second Menu - choice 2 AVL))\n";

                do{

                    cout << "Choose one of the following options:\n";
                    cout << "1. Add student\n";
                    cout << "2. Remove student\n";
                    cout << "3. Search student\n";
                    cout << "4. Print All (sorted by id)\n";
                    cout << "5. Return to main menu\n\n";

                    cout << "Enter number of option: ";
                    int internalOption; cin >> internalOption;
                    cout << '\n';


                    switch (internalOption) {
                        case 1:{
                            student s; cin >> s;

                            students.insert(s);
                            cout << "The student is added.\n\n";
                            break;
                        }
                        case 2:{

                            int id;
                            cout << "Id: ";
                            cin >> id;

                            if(students.has(id)){
                                cout << "Student is found.\n";
                                student removedStudent = students.search(id);
                                cout << removedStudent;
                                students.remove(removedStudent);
                                cout << "Student is deleted.\n\n";
                            }

                            else{
                                cout << "Student is not found.\n\n";
                            }

                            break;
                        }
                        case 3:{

                            int id;
                            cout << "Id: ";
                            cin >> id;

                            if(students.has(id)){
                                cout << "Student is found.\n";
                                cout << students.search(id) << "\n\n";
                            }

                            else{
                                cout << "Student is not found.\n\n";
                            }


                            break;
                        }
                        case 4:{

                            if(students.empty())
                                cout << "No students.\n\n";
                            else {
                                cout << "Print " << students.size() << " Students.\n\n";
                                students.inorder();
                            }

                            break;
                        }
                        case 5:{
                            stayInInnerLoop = false;
                            break;
                        }
                    }

                }while(stayInInnerLoop);

                break;
            }

            case 3:{

                break;
            }

            case 4:{

                bool stayInInnerLoop = true;
                Maxheap students;
                cout << "((Second Menu - choice 4 Max Heap))\n";

                do{

                    cout << "Choose one of the following options:\n";
                    cout << "1. Add student\n";
                    cout << "2. Print All (sorted by GPA)\n";
                    cout << "3. Return to main menu\n\n";

                    cout << "Enter number of option: ";
                    int internalOption; cin >> internalOption;
                    cout << '\n';


                    switch (internalOption) {
                        case 1:{
                            student s; cin >> s;

                            students.insert(s);
                            cout << "The student is added.\n\n";
                            break;
                        }
                        case 2:{

                            if(students.empty())
                                cout << "No students.\n\n";
                            else{
                                cout << "Print " << students.size() << " Students.\n\n";
                                students.print();
                            }
                            break;
                        }

                        case 3:{
                            stayInInnerLoop = false;
                            break;
                        }
                    }

                }while(stayInInnerLoop);


                break;
            }

            case 5:{
                stayInOuterLoop = false;
                break;
            }

            default:{
                cout << "Enter valid option\n\n";
                break;
            }

        }

    }while(stayInOuterLoop);

}
