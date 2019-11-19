#include<iostream>
#include<vector>
#include<time.h>
#include <bits/stdc++.h> 

using namespace std;

typedef struct nodo
{
	int dato;
	nodo* izq;
	nodo* der;
}nodo;

nodo* crearNodo(int n)
{
	nodo* nuevo = new nodo;
	nuevo->dato = n;
	nuevo->izq = nullptr;
	nuevo->der = nullptr;
	return nuevo;
}

nodo* insertarNodo(nodo* T, int n)
{
	if (!T)
		return crearNodo(n);
	if (n <= T->dato)
		T->izq = insertarNodo(T->izq, n);
	else 
		T->der = insertarNodo(T->der, n);
	return T;
}

bool buscarNodo(nodo* T, int n)
{
	if (!T)
		return false;
	if (T->dato == n)
		return true;
	if (n <= T->dato)
		return buscarNodo(T->izq, n);
	else 
		return buscarNodo(T->der, n);
}

int minValue(nodo* T)
{
	if (!T->izq)
		return T->dato;
	else
		return minValue(T->izq);
}

int maxValue(nodo* T)
{
	if (!T->der)
		return T->dato;
	else 
		return maxValue(T->der);
}

nodo* borrarNodo(nodo* T, int n)
{
	if (T->dato == n)
	{
		if (!T->izq and !T->der)
		{
			delete T;
			return nullptr;
		}
		if (!T->izq or !T->der)
		{
			nodo* temp = T;
			if (!T->izq)
				T = T->der;
			else
				T = T->izq;
			delete temp;
			return T;
		}
		int sustituto = minValue(T->der);
		T->dato = sustituto;
		T->der = borrarNodo(T->der, sustituto);
		return T;
	}
	if (n < T->dato)
		T->izq = borrarNodo(T->izq, n);
	else
		T->der = borrarNodo(T->der, n);
	return T;
}

void borrar_N_nodos(nodo* T, int n)
{
	while (buscarNodo(T, n))
		T = borrarNodo(T, n);
}

void inOrder(nodo* T)
{
	if (T)
	{
		inOrder(T->izq);
		cout<<T->dato<<"->";
		inOrder(T->der);
	}
}

void preOrder(nodo* T)
{
	if (T)
	{
		cout<<T->dato<<"->";
		preOrder(T->izq);
		preOrder(T->der);
	}
}

bool isBST(nodo* T)
{
	if (!T)
		return true;
	if (T->izq and maxValue(T->izq) > T->dato)
		return false;
	if (T->der and minValue(T->der) < T->dato)
		return false;
	if (!isBST(T->izq) or !isBST(T->der))
		return false;
	return true;
}

void arreglo_a_bst(nodo*& T, vector<int> V)
{
	for (unsigned int i = 0; i < V.size(); ++i)
	{
		T = insertarNodo(T, V.at(i));
	}
}

void arreglo_a_bst_balanceado(nodo*& T, vector<int> V)
{
	unsigned int mid = V.size() / 2;
	int i;
	for (i = mid; i >= 0; i--)
		T = insertarNodo(T, V.at(i));
	for (i = mid + 1; i < V.size(); i++)
		T = insertarNodo(T, V.at(i));
}

nodo* sucesorInorder(nodo* T, int n)
{
	if (T->der)
		
}

int main(void)
{
	srand(time(NULL));
	nodo* T = nullptr;
	T = insertarNodo(T, 8);
	T = insertarNodo(T, 10);
	T = insertarNodo(T, 13);
	T = insertarNodo(T, 3);
	T = insertarNodo(T, 4);
	T = insertarNodo(T, 6);
	T = insertarNodo(T, 7);
	T = insertarNodo(T, 14);
	T = insertarNodo(T, 6);
	T = insertarNodo(T, 1);	
	borrar_N_nodos(T, 6);
	inOrder(T);
	if (isBST(T))
		cout<<"\n\nIt is a BST.\n";
	std::vector<int> V;
	nodo* T2 = nullptr;
	for (int i = 0; i < 10; ++i)
	{
		V.push_back(rand() % 20 + 1);
	}
	arreglo_a_bst(T2, V);
	cout<<endl;
	preOrder(T2);
	cout<<endl<<endl;
	nodo* T3 = nullptr;
	sort(V.begin(), V.end());
	arreglo_a_bst_balanceado(T3, V);
	cout<<endl<<endl;
	preOrder(T3);
	return 0;
}