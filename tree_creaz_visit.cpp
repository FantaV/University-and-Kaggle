#include <iostream>
using namespace std;

// struttura per i nodi dell’albero
struct nodo
{  int elem;
	 nodo* left;
	 nodo* right;
};
struct nodo* t;

int SommaAlbero(nodo* a) {
  if(a==NULL)
    return 0;

  return a->elem + SommaAlbero(a->left) + SommaAlbero(a->right);
}

// punta alla struct nodo e inizializza radice con parametro passato e nodo left e right a NULL
nodo* Tree(int x) {
  nodo* p = new nodo;
  p->elem = x;
  p->left = NULL;
  p->right = NULL;
  cout << "Inserimento dei dati    "<< endl;
  return p;
}

// visita in preordine
void preorder_traversal(nodo* root) {
  if (root == NULL) return;

  // Print the data
  cout << root->elem << " ";
  // Visit Left subtree
  preorder_traversal(root->left);
  // Visit right subtree
  preorder_traversal(root->right);
}

void inorder_traversal(nodo* root) {
  if (root == NULL) return;
  // Visit Left subtree
  inorder_traversal(root->left);
  // Print the data
  cout << root->elem << " ";
  // Visit right subtree
  inorder_traversal(root->right);
}

void postorder_traversal(nodo* root) {
  if (root == NULL) return;
  // Visit Left subtree
  postorder_traversal(root->left);
  // Visit right subtree
  postorder_traversal(root->right);
  // Print the data
  cout << root->elem << " ";
}

//La seguente funzione può essere utile per inserire i valori di un albero:
nodo* inserisci(nodo* r, int d) {
  if (r==NULL) {
    r=new nodo;
	  r->elem=d; r->left=NULL; r->right=NULL;
  }
	else if (d < r->elem) r->left=inserisci (r->left,d);
	else if (d > r->elem) r->right=inserisci (r->right,d);
	return r;
};


int main ()
{
  nodo *root;
  root = Tree (17);
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

  nodo * root2;
  nodo * root3;


  root3 = inserisci(root3, 17);
  root3 = inserisci(root3, 10);
  root3 = inserisci(root3, 7);
  root3 = inserisci(root3, 11);
  root3 = inserisci(root3, 27);
  root3 = inserisci(root3, 9);

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
