#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    int data; 
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left =NULL;
        this->right =NULL;
    }
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

Node* insertintoBST(Node* &root,int data){
//base case
if(root==NULL){
    root=new Node(data);
    return root;
}
if(data>root->data){
    //right part m insert karna hai
root->right=insertintoBST(root->right,data);
}
else{
      //left part m insert karna hai
root->left=insertintoBST(root->left,data);
}
return root;
}


void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
       root= insertintoBST(root,data);
        cin>>data;
    }
}
void inorder(Node* &root,vector<int>&in){
    if(root==NULL){return ;}
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

Node* Flaten(Node* &root){
    vector<int>inorderVal;
    //store inorder-> stored val
    inorder(root,inorderVal);
    Node* newRoot=new Node(inorderVal[0]);
    Node* curr=newRoot;
    
    int n=inorderVal.size();
    for(int i=1;i<n;i++){
        Node* temp=new Node(inorderVal[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    //3rd stape
    curr->left=NULL; 
    curr->right=NULL;

    return newRoot;
}
// Function to print flattened
// binary Tree
void print(Node* parent)
{
    Node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}
int main(){
    Node* root =NULL;
    cout<<"enter data to create BST"<<endl;
    takeInput(root);
    levelOrderTraversal(root);

   print(Flaten(root));
    return 0;

}