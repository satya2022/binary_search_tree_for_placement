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


void printInorder(Node* &root){
//base case 
  if(root== NULL){return;}
    printInorder(root->left);
    cout<<(root->data);
    printInorder(root->right);
}



// sorte inorder
void inorder(Node *root,vector<int>&in){
    //base case
    if(root== NULL){return;}
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}

vector<int> mergeArrays(vector<int>& a,vector<int>& b){
    vector<int>ans(a.size()+b.size());
    int i=0,j=0;
    int k=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }

    //make sure both array complete or not  
    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }
    return ans;
}

Node* inorderToBST(int s,int e,vector<int>&in){
    //base case
    if(s>e){return NULL;}
    int mid=(s+e)/2;
    Node* root=new Node(in[mid]);
    root->left=inorderToBST(s,mid-1,in);
    root->right=inorderToBST(mid+1,e,in);
    return root;

}

Node* mergeBST(Node* root1, Node* root2){
    //stape1=stote inorder
    vector<int>bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    //stape2=merge both sorted array
    vector<int>mergeArray=mergeArrays(bst1,bst2);
    //stape3=use mergeed inorder array to bild BST
    int s=0,e=mergeArray.size()-1;
    return inorderToBST(s,e,mergeArray);
}


int main(){
    Node* root1 =NULL;
    Node* root2 =NULL;
      root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);
 
    /* Let us create the following tree as second tree
            4
        / \
        2 6
    */
    root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);
 
    // Print sorted nodes of both trees
  Node* satya=  mergeBST(root1, root2);
  printInorder(satya);

    return 0;

}