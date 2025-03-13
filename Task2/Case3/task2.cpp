#include <iostream>

using namespace std;

struct StudentAssessment {
    char FIO[20];
    char date[20];
    int score;
};

struct Container {
    StudentAssessment** firstElement;
    size_t size;
    int count;
};

void resize(Container* cont) {
    StudentAssessment** newArray = new StudentAssessment*[cont->size * 2];
    
    for (size_t i = 0; i < cont->count; i++) {
        newArray[i] = cont->firstElement[i];
    }
    
    delete[] cont->firstElement;
    
    cont->firstElement = newArray;
    cont->size *= 2;
}

void push_back(Container* cont, StudentAssessment* elem) {
    if (cont->count >= cont->size) {
        resize(cont);
    }
    
    cont->firstElement[cont->count] = elem;
    cont->count++;
}

void erase(Container* cont, unsigned int index) {
    if (index >= cont->count) {
        return;
    }
    
    delete cont->firstElement[index];
    
    for (size_t i = index; i < cont->count - 1; i++) {
        cont->firstElement[i] = cont->firstElement[i + 1];
    }
    
    cont->count--;
}

int main() {
    
    return 0;
}