#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

bool areEqual(Node* p, Node* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }

    if (p == nullptr || q == nullptr) {
        return false;
    }

    return (p->data == q->data) && areEqual(p->left, q->left) && areEqual(p->right, q->right);
}

int main() {

    Node* p = createNode(10);
    p->left = createNode(5);
    p->right = createNode(15);
    p->left->left = createNode(2);
    p->left->right = createNode(7);
    p->right->left = createNode(12);
    p->right->right = createNode(17);

    Node* q = createNode(10);
    q->left = createNode(5);
    q->right = createNode(15);
    q->left->left = createNode(2);
    q->left->right = createNode(7);
    q->right->left = createNode(12);
    q->right->right = createNode(17);

    if (areEqual(p, q)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}
