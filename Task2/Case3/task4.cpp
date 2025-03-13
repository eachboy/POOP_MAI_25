#include <iostream>
#include <cstring>

using namespace std;

struct StudentAssessment {
    char FIO[20];
    char date[20];
    int score;
    StudentAssessment* next;
};

struct Container {
    StudentAssessment* firstElement;
    size_t size;
    int count;
};

void initContainer(Container* cont, size_t initialSize) {
    cont->firstElement = nullptr;
    cont->size = initialSize;
    cont->count = 0;
}

void resize(Container* cont) {
    cont->size *= 2;
    cout << "Container size increased to " << cont->size << endl;
}

void push_back(Container* cont, StudentAssessment* elem) {
    if (cont->count >= cont->size) {
        resize(cont);
    }
    
    elem->next = nullptr;
    
    if (cont->firstElement == nullptr) {
        cont->firstElement = elem;
    } else {
        StudentAssessment* current = cont->firstElement;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = elem;
    }
    
    cont->count++;
}

void insert(Container* cont, StudentAssessment* elem, unsigned int index) {
    if (index > cont->count) {
        cout << "Invalid index or empty list" << endl;
        return;
    }
    
    if (cont->count >= cont->size) {
        resize(cont);
    }
    
    if (index == 0) {
        elem->next = cont->firstElement;
        cont->firstElement = elem;
    } else {
        StudentAssessment* current = cont->firstElement;
        for (unsigned int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        elem->next = current->next;
        current->next = elem;
    }
    
    cont->count++;
}

void erase(Container* cont, unsigned int index) {
    if (index >= cont->count || cont->firstElement == nullptr) {
        cout << "Invalid index or empty list" << endl;
        return;
    }
    
    StudentAssessment* toDelete;
    
    if (index == 0) {
        toDelete = cont->firstElement;
        cont->firstElement = cont->firstElement->next;
    } else {
        StudentAssessment* current = cont->firstElement;
        for (unsigned int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        
        toDelete = current->next;
        current->next = toDelete->next;
    }
    
    delete toDelete;
    cont->count--;
}

void edit(Container* cont, unsigned int index, const char* newFIO, const char* newDate, int newScore) {
    if (index >= cont->count) {
        cout << "Invalid index" << endl;
        return;
    }
    
    StudentAssessment* current = cont->firstElement;
    for (unsigned int i = 0; i < index; i++) {
        current = current->next;
    }
    
    strcpy(current->FIO, newFIO);
    strcpy(current->date, newDate);
    current->score = newScore;
}

void move(Container* cont, unsigned int fromIndex, unsigned int toIndex) {
    if (fromIndex >= cont->count || toIndex >= cont->count) {
        cout << "Invalid indexs" << endl;
        return;
    }
    
    if (fromIndex == toIndex) {
        return;
    }
    
    StudentAssessment* elem = nullptr;
    
    if (fromIndex == 0) {
        elem = cont->firstElement;
        cont->firstElement = elem->next;
    } else {
        StudentAssessment* current = cont->firstElement;
        for (unsigned int i = 0; i < fromIndex - 1; i++) {
            current = current->next;
        }
        elem = current->next;
        current->next = elem->next;
    }
    
    cont->count--;
    
    insert(cont, elem, toIndex);
}

void swap(Container* cont, unsigned int index1, unsigned int index2) {
    if (index1 >= cont->count || index2 >= cont->count) {
        cout << "Invalid indexs" << endl;
        return;
    }
    
    if (index1 == index2) {
        return;
    }
    
    if (index1 > index2) {
        unsigned int temp = index1;
        index1 = index2;
        index2 = temp;
    }
    
    StudentAssessment* prev1 = nullptr;
    StudentAssessment* elem1 = cont->firstElement;
    for (unsigned int i = 0; i < index1; i++) {
        prev1 = elem1;
        elem1 = elem1->next;
    }
    
    StudentAssessment* prev2 = nullptr;
    StudentAssessment* elem2 = cont->firstElement;
    for (unsigned int i = 0; i < index2; i++) {
        prev2 = elem2;
        elem2 = elem2->next;
    }
    
    if (prev1) {
        prev1->next = elem2;
    } else {
        cont->firstElement = elem2;
    }
    
    if (prev2) {
        prev2->next = elem1;
    } else {
        cont->firstElement = elem1;
    }
    
    StudentAssessment* temp = elem1->next;
    elem1->next = elem2->next;
    elem2->next = temp;
    
    if (index1 + 1 == index2) {
        elem2->next = elem1;
    }
}

void sortName(Container* cont) {
    if (cont->count <= 1) {
        return;
    }
    
    bool swapped;
    do {
        swapped = false;
        StudentAssessment* prev = nullptr;
        StudentAssessment* current = cont->firstElement;
        StudentAssessment* next = current->next;
        
        while (next != nullptr) {
            if (strcmp(current->FIO, next->FIO) > 0) {
                swapped = true;
                
                current->next = next->next;
                next->next = current;
                
                if (prev == nullptr) {
                    cont->firstElement = next;
                } else {
                    prev->next = next;
                }
                
                prev = next;
                next = current->next;
            } else {
                prev = current;
                current = next;
                next = next->next;
            }
        }
    } while (swapped);
}

void sortDate(Container* cont) {
    if (cont->count <= 1) {
        return;
    }
    
    bool swapped;
    do {
        swapped = false;
        StudentAssessment* prev = nullptr;
        StudentAssessment* current = cont->firstElement;
        StudentAssessment* next = current->next;
        
        while (next != nullptr) {
            if (strcmp(current->date, next->date) > 0) {
                swapped = true;
                
                current->next = next->next;
                next->next = current;
                
                if (prev == nullptr) {
                    cont->firstElement = next;
                } else {
                    prev->next = next;
                }
                
                prev = next;
                next = current->next;
            } else {
                prev = current;
                current = next;
                next = next->next;
            }
        }
    } while (swapped);
}

void display(Container* cont) {
    if (cont->count == 0) {
        cout << "The container is empty" << endl;
        return;
    }
    
    cout << "Container Elements (" << cont->count << "):" << endl;
    StudentAssessment* current = cont->firstElement;
    int index = 0;
    
    while (current != nullptr) {
        cout << "Element " << index << ": " << current->FIO 
             << ", Date: " << current->date 
             << ", Score: " << current->score << endl;
        current = current->next;
        index++;
    }
}

void displaySelName(Container* cont, const char* name) {
    if (cont->count == 0) {
        cout << "The container is empty" << endl;
        return;
    }
    
    cout << "Elements with a name \"" << name << "\":" << endl;
    StudentAssessment* current = cont->firstElement;
    int index = 0;
    bool found = false;
    
    while (current != nullptr) {
        if (strcmp(current->FIO, name) == 0) {
            cout << "Element " << index << ": " << current->FIO 
                 << ", Date: " << current->date 
                 << ", Score: " << current->score << endl;
            found = true;
        }
        current = current->next;
        index++;
    }
    
    if (!found) {
        cout << "No elements with that name were found." << endl;
    }
}

void displaySelDate(Container* cont, const char* date) {
    if (cont->count == 0) {
        cout << "The container is empty" << endl;
        return;
    }
    
    cout << "Elements with a date \"" << date << "\":" << endl;
    StudentAssessment* current = cont->firstElement;
    int index = 0;
    bool found = false;
    
    while (current != nullptr) {
        if (strcmp(current->date, date) == 0) {
            cout << "Element " << index << ": " << current->FIO 
                 << ", Date: " << current->date 
                 << ", Score: " << current->score << endl;
            found = true;
        }
        current = current->next;
        index++;
    }
    
    if (!found) {
        cout << "No elements with that date were found." << endl;
    }
}

void freeContainer(Container* cont) {
    StudentAssessment* current = cont->firstElement;
    
    while (current != nullptr) {
        StudentAssessment* next = current->next;
        delete current;
        current = next;
    }
    
    cont->firstElement = nullptr;
    cont->count = 0;
}

int main() {
    Container students;
    initContainer(&students, 5);
    
    int choice = 0;
    
    do {
        cout << "\n====== Program menu ======" << endl;
        cout << "1. Add record" << endl;
        cout << "2. Add record with index" << endl;
        cout << "3. Delete record" << endl;
        cout << "4. Edit record" << endl;
        cout << "5. Replace record" << endl;
        cout << "6. Swich records" << endl;
        cout << "7. Sort with FIO" << endl;
        cout << "8. Sort with date" << endl;
        cout << "9. Show all list" << endl;
        cout << "10. Show all list with name" << endl;
        cout << "11. Show all list with date" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose task number: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                StudentAssessment* newStudent = new StudentAssessment();
                cout << "Enter name: ";
                cin.ignore();
                cin.getline(newStudent->FIO, 20);
                cout << "Enter date (EX. YYYY-MM-DD): ";
                cin.getline(newStudent->date, 20);
                cout << "Enter score: ";
                cin >> newStudent->score;
                push_back(&students, newStudent);
                break;
            }
            case 2: {
                unsigned int index;
                cout << "Enter index to paste: ";
                cin >> index;
                
                StudentAssessment* newStudent = new StudentAssessment();
                cout << "Enter name: ";
                cin.ignore();
                cin.getline(newStudent->FIO, 20);
                cout << "Enter date (EX. YYYY-MM-DD): ";
                cin.getline(newStudent->date, 20);
                cout << "Enter score: ";
                cin >> newStudent->score;
                
                insert(&students, newStudent, index);
                break;
            }
            case 3: {
                unsigned int index;
                cout << "Enter index for removing: ";
                cin >> index;
                erase(&students, index);
                break;
            }
            case 4: {
                unsigned int index;
                cout << "Enter index for edit: ";
                cin >> index;
                
                char newFIO[20];
                char newDate[20];
                int newScore;
                
                cout << "Enter new name: ";
                cin.ignore();
                cin.getline(newFIO, 20);
                cout << "Enter new date (EX. YYYY-MM-DD): ";
                cin.getline(newDate, 20);
                cout << "Enter new score: ";
                cin >> newScore;
                
                edit(&students, index, newFIO, newDate, newScore);
                break;
            }
            case 5: {
                unsigned int fromIndex, toIndex;
                cout << "Enter index for replacing: ";
                cin >> fromIndex;
                cout << "Enter index replace: ";
                cin >> toIndex;
                move(&students, fromIndex, toIndex);
                break;
            }
            case 6: {
                unsigned int index1, index2;
                cout << "Enter index (first record): ";
                cin >> index1;
                cout << "Enter index (second record): ";
                cin >> index2;
                swap(&students, index1, index2);
                break;
            }
            case 7: {
                sortName(&students);
                cout << "Sort with name" << endl;
                break;
            }
            case 8: {
                sortDate(&students);
                cout << "Sort with date" << endl;
                break;
            }
            case 9: {
                display(&students);
                break;
            }
            case 10: {
                char name[20];
                cout << "Enter name for searhing: ";
                cin.ignore();
                cin.getline(name, 20);
                displaySelName(&students, name);
                break;
            }
            case 11: {
                char date[20];
                cout << "Enter date for searching: ";
                cin.ignore();
                cin.getline(date, 20);
                displaySelDate(&students, date);
                break;
            }
            case 0:
                cout << "Exit program..." << endl;
                break;
            default:
                cout << "Incorrect choose. Try again..." << endl;
        }
    } while (choice != 0);
    
    freeContainer(&students);
    
    return 0;
}