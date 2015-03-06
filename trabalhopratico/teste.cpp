//
//  teste.cpp
//  
//
//  Created by Márcio Palheta on 19/02/15.
//
//

#include "teste.h"
#include "core.h"
#include "vocabulario.h"

int main(int argc, char **argv) {
    
    if (argc!= 2) {
        printf("\tInforme a base de dados para o programa: %s \n",argv[0]);
        exit(1);
    }
    
    string a("Absss");
    string b("b");
    
    cout<<"\na.compare(b)"<<a.compare(b);
    cout<<"\na.compare(a)"<<a.compare(a);
    cout<<"\nb.compare(a)"<<b.compare(a);
    
    Vocabulario * voc = new Vocabulario();
    voc->adicionar("e");
    voc->adicionar("h");
    voc->adicionar("c");
    voc->adicionar("i");
    voc->adicionar("f");
    voc->adicionar("a");
    voc->adicionar("d");
    voc->adicionar("b");
    voc->adicionar("g");
    voc->adicionar("h");
    voc->adicionar("c");
    
    cout<<"\nVocabulario\n";
    voc->imprimir();
    
    cout<<"\nCONSULTA\n";
    Termo * t1 = voc->buscar("h");
    t1->adicionarItem("d1", 4);
    t1->adicionarItem("d1", 4);
    t1->adicionarItem("d2", 3);
    t1->adicionarItem("d3", 5);

    
    Termo * t2 = voc->buscar("i");
    t2->adicionarItem("d1", 6);
    t2->adicionarItem("d2", 4);
    t2->adicionarItem("d3", 30);
    t2->adicionarItem("d3", 20);
    
    Termo * t3 = voc->buscar("x");
    
    if(t1!= NULL){
        cout<<"T1: "<<t1->palavra<<" - tf: "<<t1->tf<<"\n";
        t1->imprimirItens();
    }else{
        cout<<"T1: null"<<"\n";
    }
    
    if(t2!= NULL){
        cout<<"\nT2: "<<t2->palavra<<" - tf: "<<t2->tf<<"\n";
        t2->imprimirItens();
    }else{
        cout<<"T2: null"<<"\n";
    }
    
    if(t3!= NULL){
        cout<<"T3: "<<t3->palavra<<" - tf: "<<t3->tf<<"\n";
    }else{
        cout<<"\nT3: null"<<"\n";
    }
    
    cout<<"\n************************************************\n";
    
    voc = new Vocabulario();
    voc->adicionar("b");
    voc->adicionar("a");
    voc->adicionar("c");
    
    
    
}