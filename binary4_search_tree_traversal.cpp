#include <bits\stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *insertintoBST(Node *&root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        // right part m insert karna hai
        root->right = insertintoBST(root->right, data);
    }
    else
    {
        // left part m insert karna hai
        root->left = insertintoBST(root->left, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertintoBST(root, data);
        cin >> data;
    }
}

bool searchinBST(Node *root, int X)
{
    // base case
    Node *temp = root;
    while (temp != NULL)
    {

        if (temp->data == X)
        {
            return true;
        }
        if (temp->data > X)
        {
            // left side
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

// inorder traversal  (LNR)
void inOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// preorder NLR
void preOrder(Node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// postOrder traverse in tree is(LRN)
void postOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    cout << "enter data to create BST" << endl;
    takeInput(root);
    levelOrderTraversal(root);
    cout <<endl;
    cout << searchinBST(root, 10);
    cout << endl;
    cout << "inorder traversal" << endl;
    inOrder(root);
    cout << endl;
    cout << "preorder traversal" << endl;
    preOrder(root);
    cout << endl;
    cout << "postorder traversal" << endl;
    postOrder(root);
    return 0;
}