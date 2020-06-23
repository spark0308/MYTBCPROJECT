#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* insert_node(struct node *head,int numb)
{
	//cout<<head<<" this"<<endl;
	struct node* temp = head;
	if(temp == NULL)
	{
		temp = new struct node;
		temp->data = numb;
		temp->left = NULL;
		temp->right = NULL;
	}
	else if(numb<=temp->data)
	{
		temp->left = insert_node(temp->left,numb);
	}
	else if(numb>temp->data)
	{
		temp->right = insert_node(temp->right,numb);
	}
	return temp;
}

void display(struct node *temp)
{
	cout<<temp->data<<" ";
	if(temp->left!=NULL)
		display(temp->left);
	else if(temp->right!=NULL)
		display(temp->right);
}

int main()
{
	struct node* root = NULL;
	char ch;
	int num;
	do{
		cout<<"Enter the amount to be inserted in tree:- ";
		cin>>num;
		root = insert_node(root,num);
		cout<<"Do you want to continue to enter item in tree? If yes enter-y\n";
		cin>>ch;
	}while(ch == 'y');
	display(root);
	return 0;

}
