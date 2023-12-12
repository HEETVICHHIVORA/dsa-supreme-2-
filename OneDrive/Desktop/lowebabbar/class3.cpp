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

int main (){
     Node* root= create();
     leveltrav(root);

    return 0 ;
}