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

Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}



Node *deleteformBST(Node *root, int val)
{
    // base case
    if (root == NULL){
        return root;
    }
    if (root->data == val)
    {
        // 0(zero) child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1(one) child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            // swaping data
            root->data = mini;
            root->right = deleteformBST(root->right, mini);
            return root;
        }
    }

    else if (root->data > val)
    {
        // left part me jao
        root->left = deleteformBST(root->left, val);
        return root;
    }
    else
    {
        // right part me jao
        root->right = deleteformBST(root->right, val);
        return root;
    }
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

int main()
{
    Node *root = NULL;
    cout << "enter data to create BST" << endl;
    takeInput(root);
    levelOrderTraversal(root);
    cout << "inorder traversal" << endl;
    inOrder(root);
    cout <<endl;
    root= deleteformBST(root, 60);
    cout<<endl;
    levelOrderTraversal(root);
    cout <<endl;
    cout << "inorder traversal" << endl;
    inOrder(root);

    return 0;
}