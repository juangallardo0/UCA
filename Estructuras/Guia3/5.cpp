#include<iostream>

using namespace std;

struct nodo
{
	int dato;
	nodo* sig;
}*inicio = nullptr;

void llenarLista()
{
	inicio = new nodo;
	nodo* n = inicio;
	for (int i = 0; i < 10; ++i)
	{
		n->dato = i + 1;
		n->sig = nullptr;
		if (i < 9)
		{
			n->sig = new nodo;
			n = n->sig;
		}
	}
}

void mostrarLista()
{
	if (!inicio)
		cout<<"No hay elementos\n";
	else
	{
		nodo* n = inicio;
		while (n)
		{
			cout<<n->dato<<", ";
			n = n->sig;
		}
		cout<<endl;
	}
}

nodo* invertir(nodo* n)
{
	if (!n)
		return n;
	if (!n->sig)
	{
		inicio = n;
		return n;
	}
	nodo* n1 = invertir(n->sig);
	n1->sig = n;
	n->sig = nullptr;
	return n;
}

int main(void)
{
	llenarLista();
	mostrarLista();
	nodo* n = new nodo;
	invertir(inicio);
	mostrarLista();
	return 0;
}