#include "tree.h"

node::node(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;

}

void node::set_left(node *x)
{
	this->left = x;
}

void node::set_right(node *y)
{
	this->right = y;
}

node * node::get_left(void)
{
	return this->left;
}

node * node::get_right(void)
{
	return this->right;
}

int node::get_data()
{
	return data;
}

void node::set_data(int data)
{
	this->data = data;
}

node * bst::get_root()
{
	return this->root;
}

bst::bst()
{

	this -> root = NULL;
}

bool bst::insert(int data)
{
	node * newnode = new node(data);

	if (newnode == NULL)
	{
		return false;
	}

	if (root == NULL)
	{
		root = newnode;
		return true;
	}

	node * temp = root;
	while (temp->get_data()!= data)
	{
		if (temp->get_data() > data)
		{
			if (temp->get_left() != NULL)
			{
				temp = temp->get_left();
			}
			else
			{
				temp->set_left(newnode);
				return true;
			}
		}
		else if (temp->get_data() < data)
		{
			if (temp->get_right() != NULL)
			{
				temp = temp->get_right();
			}
			else
			{
				temp->set_right(newnode);
				return true;

			}
		}

		
	}
	delete newnode;
	return false; 

}

void bst::pre()
{
	node * temp = root;
	node * stack[100];
	int top = -1;
	while(temp != NULL || top != -1)
	{
		while (temp != NULL)
		{
			cout << temp->get_data() << " ";
			stack[++top] = temp;
			temp = temp->get_left();
		}

		temp = stack[top--];
		temp = temp->get_right();
	}
	cout << endl;
}


void bst::post()
{
		node * temp = root;
		typedef struct
		{
			node* address;
			char flag = 'L';
		
		}pair;
		pair  stack[100];
		int top = -1;
		pair p1;
		while (temp != NULL || top != -1)
		{

			while (temp != NULL)
			{
				pair p;
				p.address = temp;
				p.flag = 'L';
				stack[++top] = p;
				temp = temp->get_left();
			}


			p1 = stack[top--];
			if (p1.flag == 'L')
			{
				temp = p1.address->get_right();
				p1.flag = 'R';
				stack[++top] = p1;

			}
			else
			{
				cout << p1.address->get_data() << " ";
			}



		}
		cout << endl;
}

void bst::in()
{
	{
		node * temp = root;
		node * stack[100];
		int top = -1;
		while (temp != NULL || top != -1)
		{
			while (temp != NULL)
			{
				
				stack[++top] = temp;
				temp = temp->get_left();
			}

			temp = stack[top--];
			cout << temp->get_data() << " ";
			temp = temp->get_right();
		}
	}
}

void bst::prerec(node * root)
{

	if (root == NULL)
		return;

	cout << root->get_data() << " ";
	prerec(root->get_left());
	prerec(root->get_right());
}

void bst::postrec(node * root)
{

	if (root == NULL)
		return;
	postrec(root->get_left());
	postrec(root->get_right());
	cout << root->get_data() << " ";
}

bool bst::delete1(int data)
{
	if (root == NULL)
		return false;

	node * baap = root; // to stay behind beta so that we can delete it //
	node * beta = root; // to get deletable node //

	//to locate data//
	while (beta->get_data() != data)
	{
		if (data < beta->get_data())
		{
			baap = beta;
			beta = beta->get_left();
		}
		else
		{
			baap = beta;
			beta = beta->get_right();
		}
	}

	//to delete terminal node that has left and right as NULL //
	if (beta->get_left() == NULL && beta->get_right() == NULL)
	{
		if (baap->get_left() == beta)
			baap->set_left(NULL);
		else
			baap->set_right(NULL);
	}
	else if(beta->get_left() != NULL )
	{
		node * max = beta->get_left();
		baap = beta;
		if (max->get_right() != NULL)
		{
			while (max->get_right() != NULL)
			{
				baap = max;
				max = max->get_right();
			}
		}
		else
		{
			int temp = max->get_data();
		int remp = beta->get_data();
		max->set_data(remp);
		beta->set_data(temp);
		baap->set_left(NULL);
		delete max;
		return true;
		}
		
		int temp = max->get_data();
		int remp = beta->get_data();
		max->set_data(remp);
		beta->set_data(temp);
		baap->set_right(NULL);
		delete max;
		return true;
	}
	else if (beta->get_left() == NULL)
	{
		node * min = beta->get_right();
		baap = beta;

		if (beta->get_left() != NULL)
		{
			while (beta->get_left() != NULL)
			{
				baap = min;
				min = min->get_left();
			}
		}
		else
		{
			int temp = min->get_data();
			int remp = beta->get_data();
			min->set_data(remp);
			beta->set_data(temp);
			baap->set_right(NULL);
			delete min;
			return true;

		}


		int temp = min->get_data();
		int remp = beta->get_data();
		min->set_data(remp);
		beta->set_data(temp);
		baap->set_left(NULL);
		delete min;
		return true;


	}

	delete beta;
	return true;
}
