#include<iostream>
#include<math.h>

using namespace std;

typedef struct poli
{
	int coef;
	int exp;
}poli;

struct nodo
{
	poli dato;
	nodo* sig;
}*inicio = nullptr;

void llenarPoli(int N)
{
	inicio = new nodo;
	nodo* n = inicio;
	for (int i = 0; i < N; ++i)
	{
		cin>>n->dato.coef;
		n->dato.exp = i;
		if (i < N - 1)
		{
			n->sig = new nodo;
			n = n->sig;
			n->sig = nullptr;
		}
	}
}

void mostrarPoli(int x)
{
	if (!inicio)
	{
		cout<<"No hay elementos\n";
	}
	else
	{
		nodo* n = inicio;
		while (n)
		{
			cout<<n->dato.coef<<"*"<<x<<"^"<<n->dato.exp<<" + ";
			n = n->sig;
		}
	}
}

float calcularPoli(int x)
{
	nodo* n = inicio;
	float res = 0;
	while (n)
	{
		res += n->dato.coef * pow(x, n->dato.exp);
		n = n->sig;
	}
	return res;
}

int main(void)
{
	int N = 3; int x = 5;
	cout<<"Ingresar "<<N<<" coeficientes: ";
	llenarPoli(N);
	mostrarPoli(x);	
	cout<<" = "<<calcularPoli(x)<<endl;
	return 0;
}