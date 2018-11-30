#include <iostream>
#include <stdlib.h>
using namespace std;

struct No{
	int info;
	No* prox;
};

struct pilha{
	No* topo;
	int tamanho;
};

pilha *aloca(pilha *PL){
	return new pilha;
}


pilha *inicializa(pilha *PL){
	PL->topo = NULL;
	PL->tamanho=0;
	return PL;
}

int PilhaVazia(pilha *PL){
	return (PL->topo == NULL) && (PL->tamanho==0);
}

pilha *Inserir(pilha *PL, int dado){
	No* novo;
	novo= new No;
	novo->info= dado;
	novo->prox= PL->topo;
	PL->topo= novo;
	PL->tamanho++;
	return PL;
}

pilha *Excluir(pilha *PL){
	No* copia;
	int sai;
	if(PilhaVazia(PL))
		cout<<"PILHA VAZIA"<<endl;
	else{
		copia= PL->topo;
		PL->topo= copia->prox;
		sai=copia->info;
		cout<<endl;
		cout<<"----> "<<sai<<" SAINDO DA PILHA <----"<<endl;
		delete copia;
		PL->tamanho--;
	}
	return PL;
}

void Mostrar(pilha *PL){
	No* copia;
	copia= PL->topo;
	int contador= 1;
	if(PilhaVazia(PL))
		cout<<"PILHA VAZIA"<<endl;
	else{
		cout<<"IMPRIMINDO PILHA COM "<<PL->tamanho<<" ELEMENTOS:"<<endl<<endl;
		while(copia!=NULL){
			cout<<"Pilha ["<<contador<<"]= "<<copia->info<<endl;
			copia=copia->prox;
			contador++;
		}
	}
	cout<<endl;
}

int main(){
	pilha *teste;
	int opcao, y;
	
	teste=aloca(teste);
	teste=inicializa(teste);
	
	do{
		cout<<"========================================"<<endl;
		cout<<"================ MENU =================="<<endl;
		cout<<"========================================"<<endl;
		cout<<"[1] INSERIR ELEMENTO NA PILHA"<<endl;
		cout<<"[2] EXCLUIR ELEMENTO DA PILHA"<<endl;
		cout<<"[3] MOSTRAR TODOS OS ELEMENTOS DA PILHA"<<endl;
		cout<<"[4] SAIR"<<endl<<endl;
		cout<<"QUAL OPCAO DESEJA? ";
		cin>>opcao;
		system("cls");
		
		switch(opcao){
			case(1):
				cout<<"Digite o valor que deseja adicionar: ";
				cin>>y;
				cout<<endl;
				teste=Inserir(teste,y);
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
	
	delete[] teste;
	
	return 0;
}
