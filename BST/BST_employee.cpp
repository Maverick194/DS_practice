#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
    int id;
    string name;
    double salary;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int i, string n, double s) {
        id = i;
        name = n;
        salary = s;
        left = right = NULL;
    }
};

class BST {
private:
    TreeNode* root;

public:
    BST() {
        root = NULL;
    }

    void insert(int id, string name, double salary) {
        root = insertRecursive(root, id, name, salary);
    }

    void displayInOrder() {
        inOrderRecursive(root);
    }

    void displayPreOrder() {
        preOrderRecursive(root);
    }

    void displayPostOrder() {
        postOrderRecursive(root);
    }

private:
    TreeNode* insertRecursive(TreeNode* root, int id, string name, double salary) {
        if (root == NULL) {
            return new TreeNode(id, name, salary);
        }

        if (id < root->id) {
            root->left = insertRecursive(root->left, id, name, salary);
        } else if (id > root->id) {
            root->right = insertRecursive(root->right, id, name, salary);
        }
        return root;
    }

    void inOrderRecursive(TreeNode* root) {
        if (root != NULL) {
            inOrderRecursive(root->left);
            cout << "Id: " << root->id << ", Name: " << root->name <<  ", Salary: " << root->salary<<endl;
            inOrderRecursive(root->right);
        }
    }

    void preOrderRecursive(TreeNode* root) {
        if (root != NULL) {
            cout << "Id: " << root->id << ", Name: " << root->name <<  ", Salary: " << root->salary<<endl;
            preOrderRecursive(root->left);
            preOrderRecursive(root->right);
        }
    }

    void postOrderRecursive(TreeNode* root) {
        if (root != NULL) {
            postOrderRecursive(root->left);
            postOrderRecursive(root->right);
            cout << "Id: " << root->id << ", Name: " << root->name <<  ", Salary: " << root->salary<<endl;
        }
    }
};

int main() {
    BST bst;

    // Adding initial keywords and meanings
    bst.insert(1, "Sushant", 100000);
    bst.insert(2, "Ajay", 75000);
    bst.insert(3, "Zoro", 50000);

    // Displaying in ascending order
    cout << "In Order Traversal:" << endl;
    bst.displayInOrder();

    cout << "Pre Order Traversal:" << endl;
    bst.displayPreOrder();

    cout << "Post Order Traversal:" << endl;
    bst.displayPostOrder();

    return 0;
}
