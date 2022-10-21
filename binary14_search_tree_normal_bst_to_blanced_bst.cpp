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
void inorder(Node* &root,vector<int>&in){
    if(root==NULL){return ;}
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

Node* inorderToBST(int s,int e,vector<int>&in) {
    //base case 
    if(s>e){
        return NULL;
    }
    //s=start&& e=end
    int mid=(s+e)/2;
    Node* root=new Node(in[mid]);
    root->left=inorderToBST(s,mid-1,in);
    root->right=inorderToBST(mid+1,e,in);
    return root;

}
Node* blancedBST(Node* root){
    vector<int>inorderVal;
    //store inorder->stored value
    inorder(root,inorderVal);
    return inorderToBST(0,inorderVal.size()-1,inorderVal);
}

/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main(){
  
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    levelOrderTraversal(root);
    root=blancedBST(root);
    preOrder(root);
    return 0;

}

