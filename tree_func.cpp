#include<bits/stdc++.h>
using namespace std;
// struttura per i nodi dell’albero

struct nodo
{  int elem;
	 nodo* left;
	 nodo* right;
};

typedef   nodo* albero;
albero t;

int SommaAlbero (nodo* a) {
  if(a==NULL)
    return 0;

  return a->elem+SommaAlbero(a->left)+SommaAlbero(a->right);
}


int ContaNodi(nodo* a)
{
if(a==NULL) return(0);
// Per ogni nodo visitato somma 1 alle chiamate ricorsive
else return(1 + ContaNodi(a->left) + ContaNodi(a->right));
}


bool Is_Empty(nodo* a)
// Restituisce true se l'abero è vuoto
{
return(a==NULL);
}

nodo*  Sinistro(nodo* a)
// Restituisce il sottoalbero sinistro
{
if (Is_Empty(a)) return(NULL);
else return(a->left);
}

albero Destro(nodo* a)
// Restituisce il sottoalbero destro
{
if (Is_Empty(a)) return(NULL);
else return(a->right);
}
//Queste due funzioni restituiscono rispettivamente
//il sottoalbero sinistro e destro dell'albero
//o del nodo passato come argomento

int ContaFoglie(nodo* a)
{
if(a==NULL) return(0);
// Per ogni nodo visitato somma 1 alle chiamate ricorsive
else
 if ((Sinistro(a)==NULL) && (Destro(a)==NULL))
 return(1);
 else return( ContaFoglie(Sinistro(a)) + ContaFoglie(Destro(a)) );
 }

// creazione albero con radice x

albero Tree(int x)
{
albero p = new nodo;
p->elem=x;
p->left=NULL;
p->right=NULL;
cout<<"Inserimento dei dati    "<<endl;
return p; }


void preorder_traversal (albero root)
{
  if (root == NULL)
    return;
  // Print the data
  cout << root->elem << " ";
  // Visit Left subtree
  preorder_traversal (root->left);
  // Visit right subtree
  preorder_traversal (root->right);
}

void inorder_traversal (nodo* root)
{
  if (root == NULL)
    return;
  // Visit Left subtree
  inorder_traversal (root->left);
  // Print the data
  cout << root->elem << " ";
  // Visit right subtree
  inorder_traversal (root->right);
}

void postorder_traversal (nodo* root)
{
  if (root == NULL)
    return;
  // Visit Left subtree
  postorder_traversal (root->left);
  // Visit right subtree
  postorder_traversal (root->right);
  // Print the data
  cout << root->elem << " ";
}

nodo* inserisci (nodo* r, int d)
{	if (r==NULL)
	{ r=new nodo;
	  r->elem=d; r->left=NULL; r->right=NULL; }
	else if (d<r->elem) r->left=inserisci (r->left,d);
	else if (d>r->elem) r->right=inserisci (r->right,d);
	return r;
};


//La seguente funzione può essere utile per inserire i valori di un albero:





int main ()
{
  nodo *root;
  root= Tree (17);
  root->left = Tree (10);
  root->right = Tree (11);
  root->left->left = Tree (7);
  root->right->left = Tree (27);
  root->right->right =  Tree (9);
  cout << "Preorder => ";
  preorder_traversal (root);
  cout << endl;
  cout << "Inorder => ";
  inorder_traversal (root);
  cout << endl;
  cout << "Postorder => ";
  postorder_traversal (root);
  cout<<endl;
  cout<<"somma nodi albero = "<<SommaAlbero(root)<<endl;
  cout<<"numero nodi albero = "<<ContaNodi(root)<<endl;
  cout<<"numero foglie albero = "<<ContaFoglie(root)<<endl;
  nodo * root2;
  nodo * root3;




  root3=inserisci ( root3, 17);
  root3=inserisci ( root3, 10);
  root3=inserisci ( root3, 7);
  root3=inserisci ( root3, 11);
  root3=inserisci ( root3, 27);
  root3=inserisci ( root3, 9);
  cout << "Preorder => ";
  preorder_traversal (root3);
  cout << endl;
  cout << "Inorder => ";
  inorder_traversal (root3);
  cout << endl;
  cout << "Postorder => ";
  postorder_traversal (root3);
  cout<<endl;
  cout<<"somma nodi albero = "<<SommaAlbero(root3)<<endl;

  cout << endl;
  return 0;
}
