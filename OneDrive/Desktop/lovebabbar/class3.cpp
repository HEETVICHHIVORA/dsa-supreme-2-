#include <iostream>
#include <queue>
#include<map>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *create()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *newNode = new Node(data);
    newNode->right = create();
    newNode->left = create();
    return newNode;
}
void leveltrav(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *front = q.front();
            q.pop();

            if (i == 1)
            {
                cout << front->data << " ";
            }

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
// for rhs also same , but make right call first

void printlhs(Node* root,int level , vector<int> &lhs){
    if(root==NULL){
        return ;
    }
    if(level==lhs.size()){
       lhs.push_back(root->data);    
    }
    printlhs(root->left,level+1,lhs);
    printlhs(root->right,level+1,lhs);

}
void printingTopView(Node* root){
    map<int,int> topview ;
    queue<pair<Node*,int> >q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();
        Node* fnode= temp.first;
        int hlevel = temp .second ;
        if(topview.find(hlevel)==topview.end()){
            topview[hlevel]= fnode->data; 

        }
        if(fnode->left ){
            q.push(make_pair(fnode->left , hlevel-1));

        }
        if(fnode->right){
            q.push(make_pair(fnode->right,hlevel +1));
        }
    }
    for(auto i : topview){
        cout<<i.second<<" ";
    }

}
void printingBottomView(Node* root){
            map<int,int> topview ;
    queue<pair<Node*,int> >q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();
        Node* fnode= temp.first;
        int hlevel = temp .second ;
      
            topview[hlevel]= fnode->data; 

    
        if(fnode->left ){
            q.push(make_pair(fnode->left , hlevel-1));

        }
        if(fnode->right){
            q.push(make_pair(fnode->right,hlevel +1));
        }
    }
    for(auto i : topview){
        cout<<i.second<<" ";
    }

}
void printleftboundary(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right ==NULL){
        return ;
    }
    ans.push_back(root->data);
    if(root->left!=NULL){
        printleftboundary(root->left,ans);
    }
    else{
         printleftboundary(root->right,ans);
    }
}
void printleaf(Node * root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->right ==NULL && root->left==NULL){
        ans.push_back(root->data);
        return ;
    }
    printleaf(root->left,ans);
    printleaf(root->right,ans);
}
void printrightboundary(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right ==NULL){
        return ;
    }
   
    if(root->right!=NULL){
        printrightboundary(root->right,ans);
    }
    else{
         printrightboundary(root->left,ans);
    }
     ans.push_back(root->data);
}
void boundary (Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    // if(root->left==NULL&&root->right==NULL){
    //     ans.push_back(root->data);
    //     return ;
    // }
    if(root->left){
        printleftboundary(root->left,ans);
    }
    printleaf(root,ans);
    if(root->right){
         printrightboundary(root->right,ans);
    }
    
}
int  main()
{
    //10 20 40 -1 -1 50 70 110 -1  -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1//
    
    Node *root = create();
    vector<int> ans ;
        ans.push_back(root->data);
        if(root->right!=NULL || root->left!=NULL){
              boundary(root,ans);
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
      
        return 0 ;
    
}

