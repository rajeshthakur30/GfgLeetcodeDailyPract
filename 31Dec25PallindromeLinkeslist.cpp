#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    // Reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Check if linked list is palindrome
    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Find middle
        Node* slow = head;
        Node* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* secondHalf = reverse(slow->next);

        // Step 3: Compare both halves
        Node* firstHalf = head;
        Node* temp = secondHalf;

        while (temp != NULL) {
            if (firstHalf->data != temp->data)
                return false;
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;
    }
};

// Helper function to insert node at end
void insert(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new Node(val);
}

// Helper function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example input: 1 2 2 1
    insert(head, 1);
    insert(head, 2);
    insert(head, 2);
    insert(head, 1);

    printList(head);

    Solution obj;
    if (obj.isPalindrome(head))
        cout << "Palindrome Linked List" << endl;
    else
        cout << "Not a Palindrome Linked List" << endl;

    return 0;
}
