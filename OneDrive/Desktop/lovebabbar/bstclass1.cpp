#include <iostream>
#include <queue>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int n)
    {
        this->data = n;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
}
Node* maxValue(Node* root) {
	if(root == NULL) {
		return NULL;
	}

	//if tree has nodes > 0 count
	Node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}
Node* minValue(Node* root) {
	if(root == NULL) {
		cout << "NO MIN VALUE" << endl;
		return NULL; 
	}
	Node* temp = root;

	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}
void create(Node *&root)
{
    cout << "enter"
         << "" << endl;
    int dat;
    cin >> dat;
    while (dat != -1)
    {
        root = insert(root, dat);
        cin >> dat;
    }
}
void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *deletetarget(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        if(root->right==NULL && root->left == NULL){
            delete root ;
            return NULL;
        }
     else   if(root->right== NULL && root->left!=NULL){
            Node* child = root ->left;
            delete root ;
            return child ;
        }
     else   if(root ->left ==NULL && root ->right!=NULL){
            Node * child = root->right ;
            delete root ;
            return child ;
        }
     else{
            Node* maxleft = maxValue(root->left);
            root->data = maxleft->data;
            root->left = deletetarget(root->left,maxleft->data);
            return root ;
         }
    }
    else if (root->data > target)
    {
       root->left=  deletetarget(root->left, target);
    }
    else
    {
        root->right= deletetarget(root->right, target);
    }
}
int main()
{
    Node *root = NULL;
    create(root);
    levelorder(root);
    
    int target ;
	cout << "Enter the value of target: " << endl;
	cin >> target;

	while(target != -1) {
		root = deletetarget(root,  target);
		cout << endl << "Printing Level Order Traversal: " << endl;
		levelorder(root);

		cout << "Enter the value of target: " << endl;
		cin >> target;
		
	}
   
    return 0;
}
