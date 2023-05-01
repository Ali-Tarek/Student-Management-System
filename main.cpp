#include "BST.h"
#include "student.h"

using namespace std;

int main()
{


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
                bool stay = 1;
                BST<student> students;
                cout << "((Second Menu - choice 1 BST))\n";

                do{

                    cout << "Choose one of the following options:\n";
                    cout << "1. Add student\n";
                    cout << "2. Remove student\n";
                    cout << "3. Search student\n";
                    cout << "4. Print All (sorted by id)\n";
                    cout << "5. Return to main menu\n";

                    cout << "Enter number of option: ";
                    int internalOption; cin >> internalOption;

                    switch (internalOption) {
                        case 1:{
                            student s; cin >> s;

                            students.insert(s);
                            cout << "The student is added.\n";
                            break;
                        }
                        case 2:{

                            int id;
                            cout << "Id: ";
                            cin >> id;

                            

                            break;
                        }
                        case 3:{

                            break;
                        }
                        case 4:{

                            break;
                        }
                        case 5:{
                            stay = 0;
                            break;
                        }
                    }

                }while(stay);

                break;
            }

            case 2:{

                break;
            }

            case 3:{

                break;
            }

            case 4:{

                break;
            }

            case 5:{

                break;
            }

            default:{
                cout << "Enter valid option\n";
            }

        }


    }while(true);




}
