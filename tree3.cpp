#include <iostream>
#include <queue>
#include <vector>


using namespace std;

class Node{
 public:
     int val;
     Node *left, *right;
    Node(){right = NULL; left = NULL;}
};

Node* build(Node* root, int val){
      if(root == NULL){
           root = new Node();
           root->val = val;
           return root;
      }
      if(val < root->val) root->left = build(root->left, val);
	  else if(val > root->val) root->right = build(root->right, val);
     return root;
}
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
int main(){
    Node *root = NULL;
    int t[] = {5,4,6,3,7};
	vector<int> v1;
	for(int i=100;i>0;i--)
		v1.push_back(i);
    for(int i = 0; i < v1.size(); i++) root = build(root, v1[i]);
    levelOrder(root);
return 0;}
