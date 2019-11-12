#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<time.h>
#include<vector>
#include<sstream>
#include<unistd.h>

using namespace std;

typedef struct hashEntry
{
	string palabra;
	hashEntry* sig;
}hashEntry;

class hashTable
{
public:
	int buckets;
	hashEntry** table;

	hashTable(int n)
	{
		buckets = n;
		table = new hashEntry*[buckets];
		for (int i = 0; i < buckets; ++i)
			table[i] = new hashEntry;
	}

	hashEntry* crearPalabra(string str);
	void insertarPalabra(hashEntry* ini, string str);
	int hashFunction(string str, int n);
	void llenarTabla(string file);
	bool buscarPalabra(string word);
};

hashEntry* hashTable::crearPalabra(string str)
{
	hashEntry* n;
	n = new hashEntry;
	n->palabra = str;
	n->sig = nullptr;
	return n;
}

void hashTable::insertarPalabra(hashEntry* ini, string str)
{
	if (!ini)
		ini = crearPalabra(str);
	else 
	{
		hashEntry* temp;
		for (temp = ini; temp->sig; temp = temp->sig);
		temp->sig = crearPalabra(str);
	}
}


int hashTable::hashFunction(string str, int n)
{
	int key = 0;
	for (int i = 0; i < str.length(); ++i)
		key = 37 * key + str[i];
	key %= n;
	if (key < 0)
		key += n;
	return key;  
}

void hashTable::llenarTabla(string file)
{
	int key = 0;
	string temp;
	ifstream dictionary;
	dictionary.open(file);
	while (getline(dictionary, temp))
	{
		key = hashFunction(temp, buckets);
		insertarPalabra(table[key], temp);
	}
	dictionary.close();
}

bool hashTable::buscarPalabra(string word)
{
	int key = hashFunction(word, buckets);
	hashEntry* temp = table[key];
	if (temp)
	{
		while (temp)
		{
			if (temp->palabra == word)
				return true;
			temp = temp->sig;
		}
	}
	return false;
}

void llenarArreglo(string file, string A[])
{
	ifstream dictionary;
	dictionary.open(file);
	string temp;
	int i = 0;
	while (getline(dictionary, temp))
	{
		A[i] = temp;
		i++;
	}
	dictionary.close();
}

bool buscarFuerzaBruta(string word, string A[])
{
	int i = 0;
	while (!A[i].empty())
	{
		if (A[i] == word)
			return true;
		i++;
	}
	return false;
}

int main(void)
{
	hashTable h(pow(2,16));
	bool menu = true, bruteForce;
	string dictionary = "usa.txt";
	h.llenarTabla(dictionary);
	string word;
 	string A[70000] = {};
 	llenarArreglo(dictionary, A);
	string frase;
	std::vector<string> words;
	std::vector<string> errors;
	int count, i;

	cout<<"\t\tSPELL CHECK\n\n";
	while (menu)
	{
		count = 0;
		cout<<"Ingresar frase para revision otrografica (ingresar 'end' para cerrar):\n\n";
		getline(cin, frase);
		if (frase == "end")
			break;
		istringstream iss(frase);
		for(frase; iss >> frase; )
    		words.push_back(frase);
    	clock_t tempsExecutionH = clock();
    	for (i = 0; i < words.size(); ++i)
    	{
    		if (!h.buscarPalabra(words.at(i)))
    		{
    			count++;
    			errors.push_back(words.at(i));
    		}
    	}
    	tempsExecutionH = clock() - tempsExecutionH;
    	cout<<"\nNumero de errores: "<<count;
    	cout<<"\n\nPalabras mal escritas:\n";
    	for (i = 0; i < errors.size(); ++i)
    	{
    		cout<<errors.at(i)<<"\t";
    	}
    	cout << "\n\nEjecucion en " << ((float)tempsExecutionH)/CLOCKS_PER_SEC << " segundos usando hashing chainning.\n";
    	clock_t tempsExecutionB = clock();
    	for (i = 0; i < words.size(); ++i)
    	{
    		bruteForce = buscarFuerzaBruta(words.at(i), A);
    	}
    	tempsExecutionB = clock() - tempsExecutionB;
    	cout << "Ejecucion en " << ((float)tempsExecutionB)/CLOCKS_PER_SEC << " segundos usando fuerza bruta.\n";
    	cout<<"Hashing chainning es "<<(((float)tempsExecutionB)/CLOCKS_PER_SEC) / (((float)tempsExecutionH)/CLOCKS_PER_SEC)<<" veces mas rapido.\n";
    	for (int i = 0; i < 80; ++i)
    	{
    		cout<<"_";
    	}
    	frase.clear();
    	words.clear();
    	errors.clear();
    	cout<<endl<<endl;
    }
	return 0;
}