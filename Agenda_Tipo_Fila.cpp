#include <iostream>
using namespace std;

struct agenda{
	char nome[40];
	char email[40];
	char numero[15];
};

struct No{
	agenda info;
	No* prox;
};

struct fila{
	No* ultimo;
	No* primeiro;
	int tamanho;
};

fila* Aloca(fila *FL){
	return new fila;
}

fila *Inicializa(fila* FL){
	FL->primeiro=FL->ultimo=NULL;
	FL->tamanho=0;
	return FL;
}

int FilaVazia(fila* FL){
	return (FL->primeiro==NULL)
	&& (FL->ultimo==NULL)
	&& (FL->tamanho==0);
}

fila* Insere(fila* FL){
	No* novo;
	novo= new No;
	cout<<"Nome: ";
	cin.ignore();
	cin.getline(novo->info.nome, 40);
	cout<<"Numero: ";
	cin.ignore();
	cin.getline(novo->info.numero, 15);
	cout<<"Email: ";
	cin.ignore();
	cin.getline(novo->info.email, 40);
	novo->prox=NULL;
	if(FilaVazia(FL)){
		FL->primeiro=FL->ultimo=novo;
		FL->tamanho++;
	}
	else{
		FL->ultimo->prox= novo;
		FL->ultimo= novo;
		FL->tamanho++;
	}

	return FL;
}

void Excluir(fila *FL){
	No* copia;
	copia= FL->primeiro;
	if(FilaVazia(FL))
		cout<<"FILA VAZIA!"<<endl;
	else{
		FL->primeiro= copia->prox;
		delete copia;
		FL->tamanho--;
	}
}

void Mostrar (fila* FL){
	No* copia;
	copia= FL->primeiro;
	int cont=1;
	if(FilaVazia(FL))
		cout<<"FILA VAZIA!"<<endl;
	else{
		cout<<"AGENDA COM "<<FL->tamanho<<" CONTATOS"<<endl<<endl;
		while(copia!=NULL){
			cout<<"==========="<<endl;
			cout<<"Contato: "<<cont<<endl;
			cout<<"==========="<<endl;
			cout<<"Nome: "<<copia->info.nome<<endl;
			cout<<"Numero: "<<copia->info.numero<<endl;
			cout<<"Email: "<<copia->info.email<<endl<<endl;
			copia=copia->prox;
			cont++;
		}
	}
	cout<<endl;
}

void Buscar(fila* FL, string dado){
	No* CP; int cont=1;
	CP= FL->primeiro;
	while(CP!=NULL){
		if(CP->info.nome == dado){
			cout<<"CONTATO ENCONTRADO!"<<endl<<endl;
			cout<<"==========="<<endl;
			cout<<"CONTATO "<<cont<<":"<<endl;
			cout<<"==========="<<endl;
			cout<<"Nome: "<<CP->info.nome<<endl;
			cout<<"Numero: "<<CP->info.numero<<endl;
			cout<<"Email: "<<CP->info.email<<endl<<endl;
			system("pause");
			system("cls");
			break;
		}
		else if(CP->info.nome!=dado){
			CP=CP->prox;
			cont++;
		}
	}
	if(CP==NULL){
		cout<<"NAO ENCONTRADO"<<endl;
		system("pause");
		system("cls");
	}
}

int main(){
	fila *teste;
	int opcao, y;
	string busca;
	
	teste=Aloca(teste);
	teste=Inicializa(teste);
	
	do{
		cout<<"========================================"<<endl;
		cout<<"================ MENU =================="<<endl;
		cout<<"========================================"<<endl;
		cout<<"[1] INSERIR CONTATO NA AGENDA"<<endl;
		cout<<"[2] EXCLUIR CONTATO"<<endl;
		cout<<"[3] MOSTRAR TODOS OS CONTATOS"<<endl;
		cout<<"[4] BUSCAR CONTATO"<<endl;
		cout<<"[5] SAIR"<<endl<<endl;
		cout<<"QUAL OPCAO DESEJA? ";
		cin>>opcao;
		system("cls");
		
		switch(opcao){
			case(1):
				teste=Insere(teste);
				cout<<endl<<"ADICIONADO COM SUCESSO!"<<endl;
				cout<<endl;
				system("pause");
				system("cls");
				break;
			case(2):
				Excluir(teste);
				cout<<endl;
				system("pause");
				system("cls");
				break;
			case(3):
				Mostrar(teste);
				cout<<endl;
				system("pause");
				system("cls");
				break;
			case(4):
				cout<<"Digite o nome do contato: ";
				cin>>busca;
				cout<<endl;
				Buscar(teste, busca);
				break;
			case(5):
				system("cls");
				break;
		}
	}while(opcao>0 && opcao<5);
	
	delete teste;
	
	return 0;
}
