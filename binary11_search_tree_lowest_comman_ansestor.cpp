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

Node *LCAinaBST(Node *root, Node *p, Node *q)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    while (root != NULL){
        if(root->data>p->data&&root->data>q->data){
            root = root->left;
        }
       else if(root->data<p->data&&root->data<q->data){
            root = root->right;
        }
        else{
            return root;
        }
    }

}
int main()
{
    Node *root = NULL;
    cout << "enter data to create BST" << endl;
    takeInput(root);
    levelOrderTraversal(root);
    Node* p=new Node(8);
    Node* q=new Node(14);
    Node* satya=LCAinaBST(root,p,q);
    cout<<satya->data<<endl;

    return 0;
}