#include <iostream>
#include <stdlib.h>
using namespace std;

struct No{
	int info;
	No* prox;
};

struct fila{
	No* primeiro;
	No* ultimo;
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
	return (FL->primeiro==NULL) && (FL->ultimo==NULL) && (FL->tamanho==0);
}

fila* Insere(fila* FL, int dado){
	No* novo;
	novo= new No;
	novo->info= dado;
	novo->prox= NULL;
	if(FilaVazia(FL)){
		FL->primeiro=FL->ultimo= novo;
		FL->tamanho++;
	}
	else{
		FL->ultimo->prox=novo;
		FL->ultimo= novo;
		FL->tamanho++;
	}
	return FL;
}

void Excluir(fila *FL){
	No* copia;
	copia= FL->primeiro;
	int sai;
	if(FilaVazia(FL))
		cout<<"FILA VAZIA!"<<endl;
	else{
		sai= copia->info;
		FL->primeiro= copia->prox;
		cout<<endl;
		cout<<"Elemento "<<sai<<" saindo."<<endl<<endl;
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
		cout<<"IMPRIMINDO FILA COM "<<FL->tamanho<<" ELEMENTOS"<<endl<<endl;
		while(copia!=NULL){
			cout<<cont<<"o da fila: "<<copia->info<<endl;
			copia=copia->prox;
			cont++;
		}
	}
	cout<<endl;
}


int main(){
	fila *teste;
	int opcao, y;
	
	teste=Aloca(teste);
	teste=Inicializa(teste);
	
	do{
		cout<<"========================================"<<endl;
		cout<<"================ MENU =================="<<endl;
		cout<<"========================================"<<endl;
		cout<<"[1] INSERIR ELEMENTO NA FILA"<<endl;
		cout<<"[2] EXCLUIR ELEMENTO DA FILA"<<endl;
		cout<<"[3] MOSTRAR TODOS OS ELEMENTOS DA FILA"<<endl;
		cout<<"[4] SAIR"<<endl<<endl;
		cout<<"QUAL OPCAO DESEJA? ";
		cin>>opcao;
		system("cls");
		
		switch(opcao){
			case(1):
				cout<<"Digite o valor que deseja adicionar: ";
				cin>>y;
				cout<<endl;
				teste=Insere(teste,y);
				cout<<y<<" ADICIONADO COM SUCESSO!"<<endl;
				cout<<endl;
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
				system("cls");
				break;
		}
	}while(opcao>0 && opcao<4);
	
	delete teste;
	
	return 0;
}
