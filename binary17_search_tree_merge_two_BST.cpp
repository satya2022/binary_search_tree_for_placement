
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

void printInorder(Node *&root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << (root->data);
    printInorder(root->right);
}

void convertInToSortedDLL(Node *root, Node *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    convertInToSortedDLL(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    convertInToSortedDLL(root->left, head);
}

Node *mergeLinkedList(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                // insert at end
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                // insert at end
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNode(Node *head){
    int cnt = 0;
    Node* temp =head;
    while(temp != NULL){
        cnt++; 
        temp = temp->right;
    }
    return cnt;
}

Node* SortedLLToBST(Node *&head,int n){
    //base case 
    if(n<=0||root==NULL){
        return NULL;
    }
    Node * left=SortedLLToBST(head,n/2);

    Node* root=head;
    root->left=left;

    head=head->next;
    root->right=SortedLLToBST(head,n-n/2-1);
    return root;
}

Node *mergeBST(Node *root1, Node *root2)
{
    //stape1=convert BST into sorted DLL in-place
    Node *head1=NULL;
    convertInToSortedDLL(root1,head1);
    head1->left=NULL;


    Node *head2=NULL;
    convertInToSortedDLL(root2,head2);
    head2->left=NULL;

    //merge sorted linked list 
    Node* head=mergeLinkedList(head1,head2);

    //stape3=convert sorted linked list into BST
    return  SortedLLToBST(head,countNode(head));

}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    
    root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    // Print sorted nodes of both trees
    Node *satya = mergeBST(root1, root2);
    printInorder(satya);

    return 0;
}




