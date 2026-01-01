#include <iostream>
using namespace std;

// Definition of Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Solution class
class Solution {
public:
    Node* intersectPoint(Node* head1, Node* head2) {
        // If either list is empty
        if (head1 == NULL || head2 == NULL)
            return NULL;

        Node* x1 = head1;
        Node* x2 = head2;

        // Traverse both lists
        while (x1 != x2) {
            x1 = (x1 == NULL) ? head2 : x1->next;
            x2 = (x2 == NULL) ? head1 : x2->next;
        }

        // Either intersection node or NULL
        return x1;
    }
};

// Helper function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    /*
        List 1: 1 -> 2 -> 3 \
                              -> 6 -> 7 -> NULL
        List 2:       4 -> 5 /
    */

    // Common part
    Node* common = new Node(6);
    common->next = new Node(7);

    // First linked list
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    // Second linked list
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Solution sol;
    Node* intersection = sol.intersectPoint(head1, head2);

    if (intersection)
        cout << "Intersection Point Data: " << intersection->data << endl;
    else
        cout << "No Intersection Found" << endl;

    return 0;
}
