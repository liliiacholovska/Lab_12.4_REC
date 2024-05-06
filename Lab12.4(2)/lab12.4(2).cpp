#include <iostream>
#include <sstream>

using namespace std;

typedef int Info;
struct Elem {
    Elem* link;
    Info info;
};

void insertRec(Elem*& L, Elem*& curr, Info value) {
    if (L == NULL) {
        Elem* tmp = new Elem{ NULL, value };
        tmp->link = tmp;
        L = tmp;
    }
    else if (curr->link == L) {
        Elem* tmp = new Elem{ L, value };
        curr->link = tmp;
    }
    else {
        insertRec(L, curr->link, value);
    }
}

void printListRec(Elem* L, Elem* curr = NULL) {
    if (L == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (curr == NULL) curr = L;
    cout << curr->info << " ";
    if (curr->link != L) {
        printListRec(L, curr->link);
    }
    else {
        cout << endl;
    }
}

void increaseListValuesRec(Elem* L, Info increaseBy, Elem* curr = NULL) {
    if (L == NULL) return;
    if (curr == NULL) curr = L;
    curr->info += increaseBy;
    if (curr->link != L) {
        increaseListValuesRec(L, increaseBy, curr->link);
    }
}

int main() {
    Elem* L = NULL;
    cout << "Enter the values:" << endl;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        stringstream ss(line);
        int a;
        while (ss >> a) {
            if (L == NULL) {
                insertRec(L, L, a);
            }
            else {
                insertRec(L, L, a);
            }
        }
    }

    cout << "Original list: ";
    printListRec(L);

    int increaseBy;
    cout << "Enter the increase value: ";
    cin >> increaseBy;
    increaseListValuesRec(L, increaseBy);

    cout << "Modified list: ";
    printListRec(L);

    return 0;
}