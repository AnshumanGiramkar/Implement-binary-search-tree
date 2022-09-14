// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BinaryST {
 int data;
 BinaryST *left, *right;

public:
 // Default constructor.
 BinaryST();

 // Parameterized constructor.
 BinaryST(int);

 // Insert function.
 BinaryST* Insert(BinaryST*, int);

 // Inorder traversal.
 void Inorder(BinaryST*);
};

// Default Constructor definition.
BinaryST ::BinaryST()
 : data(0)
 , left(NULL)
 , right(NULL)
{
}

// Parameterized Constructor definition.
BinaryST ::BinaryST(int value)
{
 data = value;
 left = right = NULL;
}

// Insert function definition.
BinaryST* BinaryST ::Insert(BinaryST* root, int value)
{
 if (!root) {
  // Insert the first node, if root is NULL.
  return new BinaryST(value);
 }

 // Insert data.
 if (value > root->data) {
  // Insert right node data, if the 'value'
  // to be inserted is greater than 'root' node data.

  // Process right nodes.
  root->right = Insert(root->right, value);
 }
 else if (value < root->data){
  // Insert left node data, if the 'value'
  // to be inserted is smaller than 'root' node data.

  // Process left nodes.
  root->left = Insert(root->left, value);
 }

 // Return 'root' node, after insertion.
 return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BinaryST ::Inorder(BinaryST* root)
{
 if (!root) {
  return;
 }
 Inorder(root->left);
 cout << root->data << endl;
 Inorder(root->right);
}

// Driver code
int main()
{
 BinaryST b, *root = NULL;
 root = b.Insert(root, 50);
 b.Insert(root, 30);
 b.Insert(root, 20);
 b.Insert(root, 40);
 b.Insert(root, 70);
 b.Insert(root, 60);
 b.Insert(root, 80);

 b.Inorder(root);
 return 0;
}


