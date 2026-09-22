#include <iostream>

struct Node {
    char data;
    Node* next;

    Node(char d = '\0') : data(d), next(NULL) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NIL\n";
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;     
    }
    return prev;
}

int main() {
    int n;
    std::cout << "Enter list length (1-26):";
    std::cin >> n;

    if (n < 1 || n > 26) {
        std::cout << "Length must be between 1 and 26";
        return 1;
    }

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; ++i) {
        Node* newNode = new Node((char)('A' + i));
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    std::cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    std::cout << "Reversed List: ";
    printList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}