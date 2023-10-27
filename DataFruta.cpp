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


class ListaIdades  {
	vector<int> lista;
	
	public:
			
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
};
 
int main()
{
	vector<Lista *> listaDeListas;

	ListaData listaData;
	ListaNomes listaNomes;
	ListaSalarios listaSalarios;
	ListaIdades listaIdades;
	string d1, d2;

	listaDeListas.push_back(&listaData);
	listaDeListas.push_back(&listaNomes);
	listaDeListas.push_back(&listaSalarios);
	listaDeListas.push_back(&listaIdades);

	int opcao;
	do
	{
		cout << "\nMENU - DataFruta\n";
		cout << "1. Adicionar data\n";
		cout << "2. Adicionar nome\n";
		cout << "3. Adicionar salario\n";
		cout << "4. Adicionar idade\n";
		cout << "5. Listar dados em ordem\n";
		cout << "6. Exibir primeiros N elementos\n";
		cout << "7. Exibir mediana, maior e menor valor de cada lista\n";
		cout << "8. Testar datas\n";
		cout << "9. Sair\n";
		cout << "Digite sua opção: ";
		cin >> opcao;
		cin.ignore();

		string valor;
		size_t quantidade;
		switch (opcao)
		{
		case 1:
			cout << "Digite a data(dd/mm/aaaa): ";
			getline(cin, valor);
			listaData.entradaDeDados(valor);
			break;
		case 2:
			cout << "Digite o nome: ";
			getline(cin, valor);
			listaNomes.entradaDeDados(valor);
			break;
		case 3:
			cout << "Digite o salario: ";
			getline(cin, valor);
			listaSalarios.entradaDeDados(valor);
			break;
		case 4:
			cout << "Digite a idade: ";
			getline(cin, valor);
			listaIdades.entradaDeDados(valor);
			break;
		case 5:
			for (Lista *lista : listaDeListas)
			{
				lista->listarEmOrdem();
			}
			break;
		case 6:
			cout << "Digite o número de elementos para exibir: ";
			cin >> quantidade;
			cin.ignore();
			for (Lista *lista : listaDeListas)
			{
				lista->exibirPrimeirosN(quantidade);
			}
			break;
		case 7:
			cout << "Exibindo mediana, maior e menor valor de cada lista:\n\n";

			for (Lista *l : listaDeListas)
			{
				if (!l->estaVazia()) // Suponhamos que 'estaVazia' é um método que verifica se a lista está vazia
				{
					cout << "Mediana: ";
					l->mostraMediana();
					cout << "\nMaior: ";
					l->mostraMaior();
					cout << "\nMenor: ";
					l->mostraMenor();
					cout << "\n-------------------\n";
				}
			}
			break;
		case 8:
			cout << "Insira a primeira data(dd/mm/aaaa): ";
			cin >> d1;
			cout << "Insira a segunda data(dd/mm/aaaa): ";
			cin >> d2;
			Data::CriaData(d1, d2);
			break;
		case 9:
			cout << "Saindo...\n";
			break;
		default:
			cout << "Opção inválida!\n";
		}

	} while (opcao != 9);

	return 0;
}


