#include <iostream>
// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// Creating a node
Node* create(int num) {
    Node* head;
    head = new Node; // Dynamicly allocated memory
    if (head == NULL) { // If no memory available
        exit(1);
    } else {
        head->data = num;
        head->next = NULL;
        return head;
    }
};

// Insertion at the beginning
void insert_beg(Node* head, Node* newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

//Inserting at the end
void insert_end(Node* head, Node* newNode) {
    Node* temp = head;
    if (head == NULL) {
        head == newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Inserting after an element
void insert_after(Node* head, int index, Node* newNode) {
    Node* temp = head;
    for (int i = 1; i < index; i++) {
        temp = temp->next;
        if (temp == NULL) {
            std::cout << "Less than " << index << " nodes in the list!\n";
            exit(0);
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    std::cout << "Node inserted successfully\n";
}

//Deleting the first node 
void del_first(Node* head) {
    if (head == NULL) {
        std::cout << "List is empty!\n";
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        std::cout << "First node deleted!";
    }
}

//Deleting the last node
void del_last(Node* head) {
    if (head == NULL) {
        std::cout << "List is empty!\n";
    } else {
        Node* temp = head;
        while (temp->next != NULL && temp->next->next != NULL) {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
        std::cout << "Deleted successfully!\n";
    }
}

// Deleting a particular node
void del(Node* head, int index) {
    Node* temp = head;
    int i;
    for (i = 2; i < index; i++) {
        temp = temp->next;
        if (temp == NULL) {
            std::cout << "Node not found!\n";
            exit(0);
        }
    }
    if (i == index) {
        Node* temp2 = temp->next; // Node to be deleted
        temp->next = temp2->next;
        delete temp2;
        std::cout << "Deleted successfully!\n";
    }
}

//Searching in a list 
void search(Node* head, int x) {
    Node* temp = head;
    int i = 1;
    while (temp != NULL) {
        if (temp->data == x) {
            std::cout << "FOUND in index " << i << "\n";
            exit(0);
        }
        temp = temp->next;
        i++;
    }
    std::cout << "Item not found!\n";
}

int main() {
    Node* head;
    int data;
    std::cin >> data;
    head = create(data);
    insert_end(head, create(data));
    search(head, 12);
    del(head, 2);
}