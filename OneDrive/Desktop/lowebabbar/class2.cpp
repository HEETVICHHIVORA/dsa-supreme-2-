#include<iostream>
#include<queue>
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
  newNode->left = create();
  newNode->right = create();
  return newNode;
}
void preorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  // n l r
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void post(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  post(root->left);
  post(root->right);
  cout << root->data << " ";
}
void leveltrav(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  while (q.size() > 1)
  {
    Node *front = q.front();
    q.pop();
    if (front == NULL)
    {
      cout << endl;
      q.push(NULL);
    }
    else
    {
      cout << front->data << " ";
      if (front->left != NULL)
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












int searchinorder(int in[],int size,int element){
    for(int i=0;i<size;i++){
        if(in[i]==element){
            return i ;
        }
    }
}

Node * createtree(int pre[],int in[],int &preindex,int inorderstart ,int inorderend,int size){
if(preindex>=size||inorderstart>inorderend){
    return NULL;
}
int element = pre[preindex];
preindex++;
Node* root = new Node(element);
int position  = searchinorder(in,size,element);
root->left = createtree( pre, in, preindex, inorderstart , position-1, size);
root->right= createtree( pre, in, preindex, position+1,inorderend, size);
return root ;
}




int main (){
    int pre[]={2,8,10,6,4,12};
    int in []={10,8,6,2,4,12};
    int size = 6;
    int preindex = 0 ;
    int inoderindex= 0 ;
    int inorderstart = 0 ;
    int  indorderend = 5;
    
Node* root =  createtree( pre, in, preindex, inorderstart , indorderend, size);
leveltrav(root);
    return 0 ;
} 