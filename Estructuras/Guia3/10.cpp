#include<iostream>
#include<fstream>
#include<unistd.h>

using namespace std;

struct nodo
{
	string placa;
	int moves;
	nodo* sig;
}*inicio;
typedef struct nodo nodo;

nodo* crearNodo (string pla, int mov)
{
	nodo* n = new nodo;
	n->placa = pla;
	n->moves = mov;
	n->sig = nullptr;
	return n;
}

void push (string pla, int mov)
{
	nodo* n = crearNodo(pla, mov);
	n->sig = inicio;
	inicio = n;
}

void pop ()
{
	nodo* temp = inicio;
	inicio = inicio->sig;
	delete temp;
}

void peek (string& s, int& x)
{
	s = inicio->placa;
	x = inicio->moves;
}

bool read (string& s, istream& f)
{
	string temp;
	f>>s;
	f>>temp;
	if (temp == "ARRIVE")
		return true;
	else return false;
}

void order(int count)
{
	if (count == 0)
		pop();
	else
	{
		string s;
		int x;
		peek(s, x);
		pop();
		order(count - 1);
		push(s, x + 1);
	}
}

void park(istream& f)
{
	string s; 
	nodo* temp;
	int count = 0;
	if (!inicio and read(s, f))
	{
		push(s, 0);
	}
	else if (read(s, f))
	{
		for (temp = inicio; temp->sig; temp = temp->sig)
			count++;
		if (count < 10)
		{
			push(s, 0);
		}
		else
			cout<<"No hay espacio de parqueo.\n\n";
	}
	else
	{
		temp = inicio;
		while (temp->placa != s)
		{
			count++;
			temp = temp->sig;
		}
		order(count);
	}
}

void mostrarLista()
{
	nodo* temp = inicio;
	while (temp)
	{
		cout<<"Placa: "<<temp->placa<<"\tMoves: "<<temp->moves<<endl;
		temp = temp->sig;
	}
}

int main (void)
{
	ifstream f;
	f.open("file.txt");
	for (int i = 0; i < 32; ++i)
	{
		park(f);
		mostrarLista();
		cout<<endl;
	}
	f.close();
	return 0;
}