#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
public:
    // Traverse bottom list and store values
    void bottomTrav(Node* root, vector<int> &v) {
        while (root != NULL) {
            v.push_back(root->data);
            root = root->bottom;
        }
    }

    // Function to flatten the linked list
    Node* flatten(Node* root) {
        vector<int> node;

        // Traverse main list
        while (root != NULL) {
            node.push_back(root->data);
            if (root->bottom)
                bottomTrav(root->bottom, node);
            root = root->next;
        }

        // Sort all collected elements
        sort(node.begin(), node.end());

        // Create new flattened list using bottom pointer
        Node* head = new Node(node[0]);
        Node* curr = head;

        for (int i = 1; i < node.size(); i++) {
            curr->bottom = new Node(node[i]);
            curr = curr->bottom;
        }

        return head;
    }
};

// Utility function to print flattened list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Driver code
int main() {
    /*
        Constructing the linked list:
        5 -> 10 -> 19 -> 28
        |    |     |     |
        7    20    22    35
        |          |     |
        8          50    40
        |                |
        30               45
    */

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution obj;
    Node* flatHead = obj.flatten(head);

    cout << "Flattened Linked List:\n";
    printList(flatHead);

    return 0;
}

