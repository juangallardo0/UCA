#include<iostream>

using namespace std;

struct nodo
{
	int dato;
	nodo* sig;
}*inicio = nullptr, *iniPar = nullptr, *iniImpar = nullptr;

void llenarLista()
{
	inicio = new nodo;
	nodo* n = inicio;
	for (int i = 0; i < 20; ++i)
	{
		n->dato = i + 1;
		n->sig = nullptr;
		if (i < 19)
		{
			n->sig = new nodo;
			n = n->sig;
		}
	}
}

void mostrarLista(nodo* ini)
{
	if (!ini)
		cout<<"No hay elementos\n";
	else
	{
		nodo* n = ini;
		while (n)
		{
			cout<<n->dato<<", ";
			n = n->sig;
		}
		cout<<endl;
	}
}

void repartir(nodo* n, nodo* np, nodo* ni)
{
	if (n)
	{
		if (n->dato % 2 == 0)
		{
			np->dato = n->dato;
			np->sig = new nodo;
			repartir(n->sig, np->sig, ni);
		}
		else
		{
			ni->dato = n->dato;
			ni->sig = new nodo;
			repartir(n->sig, np, ni->sig);
		}
	}
	else
	{
		np->sig = nullptr;
		ni->sig = nullptr;
	}
}

int main(void)
{
	llenarLista();
	mostrarLista(inicio);
	iniPar = new nodo;
	iniImpar = new nodo;
	repartir(inicio, iniPar, iniImpar);
	mostrarLista(iniPar);
	mostrarLista(iniImpar);
	return 0;
}