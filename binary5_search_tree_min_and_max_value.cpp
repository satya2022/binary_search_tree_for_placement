//time complexity and space complexity is= O(N)
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


bool searchinBST(Node *root,int X){
    // base case 
    if(root== NULL){
        return false;
    }
    if(root->data==X){
        return true;
    }
    if(root->data>X){
        //left side 
      return  searchinBST(root->left,X);
    }
    else{
      return  searchinBST(root->right,X);
    }

}
Node* minValue(Node* root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
return temp;
}

Node* maxValue(Node* root){
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
return temp;
}
int main(){
    Node* root =NULL;
    cout<<"enter data to create BST"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
   cout<< searchinBST(root,10);
   cout<<endl;
   Node *satya=minValue(root);
   cout<<"min value is"<<satya->data<<endl;

   Node *satya1=maxValue(root);
   cout<<"max value is"<<satya1->data<<endl;
    return 0;

}