#include "llist2.h"
#include <iostream>
using namespace std;

int main() {
    List list1, list2, list3;
    int option, data;
    
    cout << "Menu:\n";
    cout << "1. Insert List1\n";
    cout << "2. Insert List2\n";
    cout << "3. Merge into List3\n";
    cout << "4. Display Lists\n";
    cout << "5. Exit\n";

    while (true) {
        cout << "Enter your option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                cout << "Enter value to insert into List1: ";
                cin >> data;
                list1.insertAscending(data);
                break;
            case 2:
                cout << "Enter value to insert into List2: ";
                cin >> data;
                list2.insertAscending(data);
                break;
            case 3:
                list3 = List::merge(list1, list2);
                cout << "Lists merged into List3.\n";
                break;
            case 4:
                cout << "List1: ";
                list1.display();
                cout << "List2: ";
                list2.display();
                cout << "List3: ";
                list3.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option. Try again!\n";
        }
    }
}
