#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	static int compara(Data d1, Data d2) { 
		return 0;
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class ListaNomes {
	vector<string> lista;
	
	public:
	
	void entradaDeDados() {
		lista.push_back("Teste");
	}
		
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
	}
};

class ListaDatas  {
	vector<Data> lista;
	
	public:
		
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}
};

class ListaSalarios  {
	vector<float> lista;
	
	public:
	
	void entradaDeDados() {
		
	}
			
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o maior dos salarios" << endl;
	}
};


class ListaIdades : public Lista
{
private:
    vector<int> lista;

public:
    void entradaDeDados(const string &valor) override
    {
        int idade;
        sscanf(valor.c_str(), "%d", &idade);
        lista.push_back(idade);
        sort(lista.begin(), lista.end());
    }

    void mostraMediana() const override
    {
        if (lista.empty())
        {
            cout << "";
        }
        else
        {
            size_t posicaoDoMeio = lista.size() / 2;
            if (lista.size() % 2 == 0)
            {
                cout << (lista[posicaoDoMeio - 1] + lista[posicaoDoMeio]) / 2;
            }
            else
            {
                cout << lista[posicaoDoMeio];
            }
        }
    }

    void mostraMaior() const override
    {
        if (!lista.empty())
        {
            cout << lista.back();
        }
    }

    void mostraMenor() const override
    {
        if (!lista.empty())
        {
            cout << lista.front();
        }
    }

    void listarEmOrdem() const override
    {
        for (int idade : lista)
        {
            cout << idade << " ";
        }
        cout << endl;
    }

    void exibirPrimeirosN(size_t quantidade) const override
    {
        for (size_t i = 0; i < min(quantidade, lista.size()); i++)
        {
            cout << lista[i] << " ";
        }
        cout << endl;
    }

    bool estaVazia() const override
    {
        return lista.empty();
    }
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
    

