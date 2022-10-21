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


pair<int,int>predecussorsuccessor(Node *root,int key){
    //find key 
    int pred=-1;
    int succ=-1;
    Node*temp=root;
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }


    //pred
    Node* leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }

   //succ
   Node* rightTree=temp->right;
   while(rightTree!=NULL){
    succ=rightTree->data;
    rightTree=rightTree->left;
   }
   pair<int,int>ans=make_pair(pred,succ);
   return ans;
}

void inorder(Node* root){
    if(root==NULL){
        return ;
    }
   inorder(root->left);
   cout <<root->data << endl;
   inorder(root->right);
}
int main(){
    Node* root =NULL;
    cout<<"enter data to create BST"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    cout<<endl;
   inorder(root);
   cout<<endl;
   cout<<endl;
   pair<int,int>satya=predecussorsuccessor(root,30);
    cout <<"predecussor"<< satya.first << " ";
    cout <<"successor"<< satya.second << " ";
    return 0;

}