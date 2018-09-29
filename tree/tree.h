#include<iostream>
#include<conio.h>

using namespace std;

class node 
{  
	node * left;
	int data;
	node * right;
public:
	node(int data);
	void set_left(node*);
	void set_right(node*);
	node* get_left(void);
	node* get_right(void);
	int get_data();
	void set_data(int);

};

class bst 
{
	node * root;
public:
	bst();
	bool insert(int data);
	void pre();
	void post();
	void in();
	node* get_root();

	void prerec(node *root);
	void postrec(node *root);
	bool delete1(int data);
};


