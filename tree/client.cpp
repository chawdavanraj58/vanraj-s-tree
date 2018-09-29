#include"tree.h"

void main()
{
	bst b1;
	cout << b1.insert(50) << endl;
	cout << b1.insert(90) << endl;
	cout << b1.insert(30) << endl;
	cout << b1.insert(20) << endl;
	cout << b1.insert(25) << endl;
	cout << b1.insert(29) << endl;
	cout << b1.insert(40) << endl;
	cout << b1.insert(80) << endl;
	cout << b1.insert(60) << endl;
	cout << b1.insert(70) << endl;
	
	cout << "preorder ususal :";
	b1.pre();
	cout << "inorder ususal :";
	b1.in();
	cout <<"\n"<< "postorder ususal :";
	b1.post();

	cout << "Preorder by recursion :";
	b1.prerec(b1.get_root());
	cout <<"\n" <<"Postorder by recursion :";
	b1.postrec(b1.get_root());

	cout << b1.delete1(25) << endl;
	cout << b1.delete1(80) << endl;
	b1.pre();
	_getch();
}