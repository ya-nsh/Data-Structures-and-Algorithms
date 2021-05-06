#include<iostream>
using namespace std ;

class node
{
	node *left ;
	int data ;
	node *right;
	public:
		node(int n)
		{
			data = n ;
			left = right =NULL;
		}
		friend class tree ;
};

class tree
{
	node *root;
//private member function
void preorder (node *currentnode);
void inorder (node *currentnode);
void postorder (node *currentnode);
public:
	tree() //constructot
	{
		root = NULL;
	}
	void create() ;
	void preorder() ;
	void inorder() ;
	void postorder() ;
	void insert(char c) ;
	void delet(char c) ;
	int totalnodes();
	int	leafnode();
	void mirror(tree &);
	void copy(tree &);

};

void tree::create()
	{
		node *temp, *newnode;
		int c, choice;
		char ans;
		
		do
		{
		cout<<"Enter Elements to be attached: ";
		cin>>c;
		newnode= new node(c);
		
		if(root==NULL)
		root=newnode;
		
		else
		{
			temp=root;
			
			while(1)
			{
				cout<<"Left or Right (l/r) of "<<temp->data;
				cin>>ans;
				
				if(ans=='l')
				
				if(temp->left==NULL)
				{
					temp->left=newnode;
					break;
				}
				
				else
					temp=temp->left;
				
				if(temp->right==NULL)
				{
					temp->right=newnode;
					break;
				}
				
				else
				temp=temp->right;
			}
		}
		cout<<"Do u want to insert more nodes(1/0)?: ";
		cin>>choice;
		
		}while(choice==1);
		}


void tree::preorder(){
	preorder(root)
}




int main()
{
	tree k;
	k.create();
}

