#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

struct nodo
{
	int dato;
	nodo* sig;
}*inicio = nullptr;
typedef struct nodo nodo;

void llenarLista()
{
	inicio = new nodo;
	inicio->dato = rand()%100 + 1;
	inicio->sig = nullptr;
	nodo* n = inicio;
	for (int i = 0; i < 19; ++i)
	{
		n->sig = new nodo;
		n = n->sig;
		n->dato = rand()%100 + 1;
		n->sig = nullptr;
	}
}

void mostrarLista()
{
	nodo* n = inicio;
	if (!inicio)
	{
		cout<<"No hay elementos en la lista.\n";
	}
	else
	{
		while (n)
		{
			cout<<n->dato<<", ";
			n = n->sig;
		}
		cout<<endl;
	}
}

void mostrarPares()
{
	nodo* n = inicio;
	if (!inicio)
	{
		cout<<"No hay elementos en la lista.\n";
	}
	else
	{
		while (n)
		{
			if (n->dato % 2 == 0)
			{
				cout<<n->dato<<", ";
			}
			n = n->sig;
		}
		cout<<endl;
	}
}

void mostrarImpares()
{
	nodo* n = inicio;
	if (!inicio)
	{
		cout<<"No hay elementos en la lista.\n";
	}
	else
	{
		while (n)
		{
			if (n->dato % 2 != 0)
			{
				cout<<n->dato<<", ";
			}
			n = n->sig;
		}
		cout<<endl;
	}
}

void mostrarInverso(nodo* n)
{
	if (n)
	{
		mostrarInverso(n->sig);
		cout<<n->dato<<", ";
	}
}

int main(void)
{
	srand(time(NULL));
	llenarLista();
	mostrarLista();
	mostrarPares();
	mostrarImpares();
	mostrarInverso(inicio);
	cout<<endl;
	return 0;
}