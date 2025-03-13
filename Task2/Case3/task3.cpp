#include <iostream>
#include <cstring>

using namespace std;

struct StudentAssessment {
    char FIO[20];
    char date[20];
    int score;
    StudentAssessment* next; // Указатель на следующий элемент списка
};

struct Container {
    StudentAssessment* firstElement; // Указатель на первый элемент
    size_t size;                     // Размер контейнера
    int count;                       // Количество текущих элементов
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
        current->next = toDelete->next; // Перенаправляем указатель
    }
    
    delete toDelete; // Освобождаем память
    cont->count--;
}

void displayContainer(Container* cont) {
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
    initContainer(&students, 2); // Начальный размер 2
    
    StudentAssessment* student1 = new StudentAssessment();
    strcpy(student1->FIO, "Ivanov I.I.");
    strcpy(student1->date, "2023-09-10");
    student1->score = 5;
    push_back(&students, student1);
    
    StudentAssessment* student2 = new StudentAssessment();
    strcpy(student2->FIO, "Petrov P.P.");
    strcpy(student2->date, "2023-09-10");
    student2->score = 4;
    push_back(&students, student2);
    
    StudentAssessment* student3 = new StudentAssessment();
    strcpy(student3->FIO, "Sidorov S.S.");
    strcpy(student3->date, "2023-09-11");
    student3->score = 3;
    push_back(&students, student3); // Должен вызвать resize
    
    displayContainer(&students);

    cout << "\nDeleting the element with the index 1:" << endl;
    erase(&students, 1);
    displayContainer(&students);
    
    freeContainer(&students);
    
    return 0;
}