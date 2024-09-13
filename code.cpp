#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T data;
    Node* next;

public:
    Node() : data(T()), next(nullptr) {}
    Node(T d) : data(d), next(nullptr) {}

    template <typename U>
    friend class singlylinkedlist;
};

template <typename T>
class singlylinkedlist {
private:
    Node<T>* head;

public:
    singlylinkedlist() : head(nullptr) {}

    ~singlylinkedlist() {                     // Destructor for memory management
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtStart(T d) {                 // O(1)
        Node<T>* newnode = new Node<T>(d);
        newnode->next = head;
        head = newnode;
        cout << "Value added at start." << endl;
    }

    void insertAtEnd(T d) {                   // O(n)
        Node<T>* newnode = new Node<T>(d);
        if (!head) {
            head = newnode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cout << "Value added at end." << endl;
    }

    void print() {                            // O(n)
        if (head) {
            Node<T>* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        } else {
            cout << "List is empty." << endl;
        }
    }

    bool search(T d) {                        // O(n)
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == d) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isEmpty() {                          // O(1)
        return head == nullptr;
    }

    bool insertBefore(T v1, T v2) {           // O(n)
        Node<T>* newnode = new Node<T>(v1);
        if (!head) return false;              // Empty list, return false

        if (head->data == v2) {               // Insert at head if head matches v2
            newnode->next = head;
            head = newnode;
            return true;
        }

        Node<T>* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == v2) {     // Insert before the node with value v2
                newnode->next = temp->next;
                temp->next = newnode;
                return true;
            }
            temp = temp->next;
        }
        return false;                         // v2 not found
    }

    void deleteAll(T d) {                     // O(n)
        while (head != nullptr && head->data == d) {
            Node<T>* toDelete = head;
            head = head->next;
            delete toDelete;
        }

        Node<T>* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data == d) {
                Node<T>* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
        cout << "All occurrences of " << d << " deleted." << endl;
    }

    void deleteAtStart() {                    // O(1)
        if (head) {
            Node<T>* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted from start." << endl;
        } else {
            cout << "List is already empty." << endl;
        }
    }
};

int main() {
    singlylinkedlist<int> sll;
    int x = 1, val = 0, val1 = 0;

    while (x != 0) {
        cout << "\nPress 1 to insert at start.\n";
        cout << "Press 2 to insert at end.\n";
        cout << "Press 3 to print.\n";
        cout << "Press 4 to search value.\n";
        cout << "Press 5 to check if empty.\n";
        cout << "Press 6 to insert value before.\n";
        cout << "Press 7 to delete all occurrences.\n";
        cout << "Press 8 to delete from start.\n";
        cout << "Press 0 to end.\n";
        cin >> x;

        switch (x) {
        case 1:
            cout << "Enter value= ";
            cin >> val;
            sll.insertAtStart(val);
            break;

        case 2:
            cout << "Enter value= ";
            cin >> val;
            sll.insertAtEnd(val);
            break;

        case 3:
            sll.print();
            break;

        case 4:
            cout << "Enter value= ";
            cin >> val;
            if (sll.search(val)) {
                cout << "Value found." << endl;
            } else {
                cout << "Value not found." << endl;
            }
            break;

        case 5:
            if (sll.isEmpty()) {
                cout << "List is empty." << endl;
            } else {
                cout << "List is not empty." << endl;
            }
            break;

        case 6:
            cout << "Insert value to add= ";
            cin >> val;
            cout << "Insert value before= ";
            cin >> val1;
            if (sll.insertBefore(val, val1)) {
                cout << "Value added before " << val1 << "." << endl;
            } else {
                cout << "Value not added. " << val1 << " not found." << endl;
            }
            break;

        case 7:
            cout << "Enter value= ";
            cin >> val;
            sll.deleteAll(val);
            break;

        case 8:
            sll.deleteAtStart();
            break;

        default:
            break;
        }
    }

    return 0;
}
