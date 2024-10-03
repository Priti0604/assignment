//Paras Deshpande
//Roll no:2319
//batch:S2
//DSAL
//..................................................................................................
// Assignment 
/*Implement binary search tree and perform following operations:
a) Insert (Handle insertion of duplicate entry)
b) Delete
c) Search
d) Display tree (Traversal)
e) Display - Depth of tree
f) Display - Mirror image
g) Create a copy
h) Display all parent nodes with their child nodes
i) Display leaf nodes
j) Display tree level wise*/
//.................................................................................................
#include <algorithm>
#include <iostream>

using namespace std;

class node
{ // this class is used to create nodes as tree is implemented using linked list
public:
    int data;    // accepts value for node
    node *left;  // left child stored
    node *right; // right child stored
    node()       // default constructor
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int d) // parameterized constructor
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class tree // class tree where we'll be implementing
{
public:
    node *newNode(int x) // used to create the first node
    {
        node *temp = new node(x);
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }

    node *insert(node *node, int key) // then nodes are added to the main
    {
        if (node == NULL) // if node is null then we are creating a new node
        {
            return newNode(key);
        }
        if (key < node->data) // if the no. entered is smaller than the parent node value is added to the left subtree
            node->left = insert(node->left, key);
        else // if the no. entered is greater than the parent node value is added to the right subtree
            node->right = insert(node->right, key);

        return node;
    }

    void inorder(node *root) // we print the complete binary search tree in ascending order
    {
        if (root != NULL)
        {
            // Traverse left
            inorder(root->left);

            // Traverse root
            int y = root->data;
            cout << y << " -> ";

            // Traverse right
            inorder(root->right);
        }
    }

    node *delete_Node(node *t, int x)
    {
        node *temp;

        if (t == NULL) // we'll first find out whether the element is in the right subtree of left subtree by checking whether the value passed is greater than parent node or less
        {
            cout << "\nElement not found!";
            return t;
        }
        if (x < t->data) // we are checking whether in left subtree
        {
            t->left = delete_Node(t->left, x);
            return t;
        }
        else if (x > t->data) // we are checking whether in right subtree
        {
            t->right = delete_Node(t->right, x);
            return t;
        }
        else // once the node is found we'll come here and check how many child nodes are there and delete the node accordingly
        {
            if (t->left == NULL && t->right == NULL) // the node we want to delete has no child nodes so directly we can delete
            {
                temp = t;
                delete temp;
                return NULL;
            }
            if (t->left == NULL) // the node we want to delete has right child node so we'll bring the right node up in place of the node we want to delete
            {
                temp = t;
                t = t->right;
                delete temp;
                return t;
            }
            if (t->right == NULL) // the node we want to delete has left child node so we'll bring the left node up in place of the node we want to delete
            {
                temp = t;
                t = t->left;
                delete temp;
                return t;
            }
            temp = t->right; // the node we want to delete has both child nodes so we'll bring the right node up in place of the node we want to delete and let left stay where it is
            while (temp->left != NULL)
                temp = temp->left;
            t->data = temp->data;
            t->right = delete_Node(t->right, temp->data);
            return t;
        }
        return NULL;
    }
    node *search(node *root, int key) // we check whether the no. to be serched is lesser or gretaer than the parent node
    {                                 // if it is lesser then we recursively check the left tree for the value and vice versa for right subtree
        if (root == NULL)
            return NULL;
        if (key == root->data)
            return root;
        if (key < root->data)
            return search(root->left, key);
        if (key > root->data)
            return search(root->right, key);
    }

    void print_node(node *root)
    {

        int i, h = height_tree(root);
        /* Iterate from level 0 to height-1 and
     print one level at a time */
        for (i = 0; i < h; i++)
        {
            cout << "Level " << i << ": ";
            Node_At_Level(root, i);
            cout << endl;
        }
    }

    void Node_At_Level( node *root, int level)
    {

        if (root == NULL)
        {
            return;
        }
        if (0 == level)
        {
            cout << root->data << " ";

            return;
        }

        Node_At_Level(root->left, level - 1);
        Node_At_Level(root->right, level - 1);
    }

    height_tree(node *t)
    {
        int hlt, hrt;
        if (t == NULL)
            return 0;
        else
        {
            hlt = height_tree(t->left) + 1;  // we first find value of left subtree by recursively calling height_tree method
            hrt = height_tree(t->right) + 1; // next we find value of right subtree by recursively calling height_tree method
        }
        if (hlt > hrt) // then we find which height is greater and return it accordingly
            return hlt;
        return hrt;
    }
    void mirror(node *t) // we basically swap the left side elements with right side recursively using extra node temp
    {
        node *temp;
        if (t != NULL)
        {
            temp = t->left;
            t->left = t->right;
            t->right = temp;

            mirror(t->left);
            mirror(t->right);
        }
        else
            return;
    }
};
int main()
{
    tree t;
    int x, choice;
    char ch = 'y';
    node *root = NULL;
    int y;
    node *del = new node();
    while (1)
    {
        cout << "\n\nBinary Search Tree Operations ";
        cout << "\n1. Insert.";
        cout << "\n2. Delete.";
        cout << "\n3. Search.";
        cout << "\n4. Mirror Image.";
        cout << "\n5. Inorder Display.";
        cout << "\n6. Display Level-wise.";
        cout << "\n7. Height of the tree.";
        cout << "\n8. Exit.";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\nEnter data for new Node: ";
            cin >> x;
            root = t.insert(root, x);
            while (true)
            {
                cout << "\nEnter y or Y to add more Nodes: ";
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
                cout << "\nEnter data for Node: ";
                cin >> x;
                root = t.insert(root, x);
            }
            break;
        case 2:
            cout << "\nEnter data to delete: ";
            cin >> x;
            del = t.delete_Node(root, x);
            break;
        case 3:
            cout << "\nEnter number to search: ";
            cin >> x;
            del = t.search(root, x);
            y = del->data;
            cout << y << " found" << endl;
            break;
        case 4:
            cout << "\nMirror Image of tree: ";
            t.mirror(root);
            t.inorder(root);
            t.mirror(root);
            break;
        case 5:
            cout << "\nInorder traversal of tree: ";
            t.inorder(root);
            break;

        case 6: 
            cout<<"\nLevel-Order traversal of tree: " << endl; 
            t.print_node(root);
        case 7:
            cout << "\nHeight of the tree: " << t.height_tree(root);
            break;
        case 8:
            return 0;
        }
    }
    return 0;
}