#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Data
{
    int dia, mes, ano;

public:
    static int compara(Data d1, Data d2)
    {
        if (d1.ano < d2.ano)
        {
            return -1;
        }
        else if (d1.ano > d2.ano)
        {
            return 1;
        }
        else
        {
            if (d1.mes < d2.mes)
            {
                return -1;
            }
            else if (d1.mes > d2.mes)
            {
                return 1;
            }
            else
            {
                if (d1.dia < d2.dia)
                {
                    return -1;
                }
                else if (d1.dia > d2.dia)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }

    Data(int _dia, int _mes, int _ano)
    {
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }

    string toString() const
    {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }

    static void CriaData(string d1, string d2)
    {
        int diaExtraido, mesExtraido, anoExtraido, resultado;

        sscanf(d1.c_str(), "%d/%d/%d", &diaExtraido, &mesExtraido, &anoExtraido);
        Data novaData1(diaExtraido, mesExtraido, anoExtraido);

        sscanf(d2.c_str(), "%d/%d/%d", &diaExtraido, &mesExtraido, &anoExtraido);
        Data novaData2(diaExtraido, mesExtraido, anoExtraido);

        resultado = Data::compara(novaData1, novaData2);
        if (resultado == -1)
        {
            cout << "A data " << d1 << " é menor que a data " << d2 << "." << endl;
        }
        else if (resultado == 1)
        {
            cout << "A data " << d1 << " é maior que a data " << d2 << "." << endl;
        }
        else
        {
            cout << "As datas " << d1 << " e " << d2 << " são iguais." << endl;
        }
    }
};

class Lista
{
public:
    virtual void entradaDeDados(const string &valor) = 0;
    virtual void mostraMediana() const = 0;
    virtual void mostraMaior() const = 0;
    virtual void mostraMenor() const = 0;
    virtual void listarEmOrdem() const = 0;
    virtual void exibirPrimeirosN(size_t quantidade) const = 0;
    virtual bool estaVazia() const = 0;
    virtual ~Lista() {}
};

class ListaData : public Lista
{
private:
    vector<Data> lista;

    static bool comparaDatas(const Data &data1, const Data &data2)
    {
        return Data::compara(data1, data2) < 0;
    }

public:
    void entradaDeDados(const string &valor) override
    {
        int diaExtraido, mesExtraido, anoExtraido;
        sscanf(valor.c_str(), "%d/%d/%d", &diaExtraido, &mesExtraido, &anoExtraido);
        Data novaData(diaExtraido, mesExtraido, anoExtraido);
        lista.push_back(novaData);
        sort(lista.begin(), lista.end(), comparaDatas);
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
                cout << lista[posicaoDoMeio - 1].toString();
            }
            else
            {
                cout << lista[posicaoDoMeio].toString();
            }
        }
    }

    void mostraMaior() const override
    {
        if (!lista.empty())
        {
            cout << lista.back().toString();
        }
    }

    void mostraMenor() const override
    {
        if (!lista.empty())
        {
            cout << lista.front().toString();
        }
    }

    void listarEmOrdem() const override
    {
        for (const Data &data : lista)
        {
            cout << data.toString() << " ";
        }
        cout << endl;
    }

    void exibirPrimeirosN(size_t quantidade) const override
    {
        for (size_t i = 0; i < min(quantidade, lista.size()); i++)
        {
            cout << lista[i].toString() << " ";
        }
        cout << endl;
    }

    bool estaVazia() const override
    {
        return lista.empty();
    }
};

class ListaNomes : public Lista
{
private:
	vector<string> lista;

public:
	void entradaDeDados(const string &valor) override
	{
		lista.push_back(valor);
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
				cout << lista[posicaoDoMeio - 1];
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
		for (const string &nome : lista)
		{
			cout << nome << " ";
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

class ListaSalarios : public Lista
{
private:
    vector<double> lista;

public:
    void entradaDeDados(const string &valor) override
    {
        double salario;
        sscanf(valor.c_str(), "%lf", &salario);
        lista.push_back(salario);
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
                cout << (lista[posicaoDoMeio - 1] + lista[posicaoDoMeio]) / 2.0;
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
        for (double salario : lista)
        {
            cout << salario << " ";
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
    

