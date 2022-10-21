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
void inorder(Node *root,vector<int>&in){
    if(root==NULL){return;}
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
bool twosuminBST(Node* &root,int target){
    vector<int>inorderVal;
    // store inorder-> stored val
    inorder(root,inorderVal);
    //use two pointer apporoch to chack pair exist
    int i=0,j=inorderVal.size()-1;
    while(i<j){
        int sum=inorderVal[i]+inorderVal[j];
        if(sum==target){return true;}
        else if(sum>target){
         j--;
        }
        else{
            i++;
        }
    }
    return false;
}


int main(){
    Node* root =NULL;
    cout<<"enter data to create BST"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    cout<<"twosum is"<<twosuminBST(root,20);

    return 0;

}