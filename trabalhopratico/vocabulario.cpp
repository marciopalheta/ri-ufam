//
//  vocabulario.cpp
//  
//
//  Created by Márcio Palheta on 20/02/15.
//
//

#include "vocabulario.h"

Vocabulario::Vocabulario(){
    raiz = NULL;
    qtdeTermos = 0;
}

float Vocabulario::getNorma(string idDocumento){
    return sqrt(somarQuadradoCoordenadas(raiz, idDocumento));
    
}

float Vocabulario::somarQuadradoCoordenadas(Termo * termo, string idDocumento){
    if(termo == NULL){
        return 0;
    }else {
        return pow(termo->buscarCoordenadaDocumento(idDocumento), 2)+
        somarQuadradoCoordenadas(termo->esquerda, idDocumento)+
        somarQuadradoCoordenadas(termo->direita, idDocumento);
    }
}

void Vocabulario::imprimir(Termo * termo, bool itens){
    if (termo!=NULL) {
        imprimir(termo->esquerda, itens);
        cout<<termo->palavra<<" tf:"<<termo->tf<<" idf:"<<termo->idf<<"\n";
        if(itens){
            termo->imprimirItens();
            cout<<"\n";
        }
        imprimir(termo->direita, itens);
    }
}

void Vocabulario::imprimir(bool itens){
    imprimir(raiz, itens);
}

Termo * Vocabulario::adicionar(Termo *raiz, string palavra, string docId){
    if(raiz == NULL){
        qtdeTermos++;
        return new Termo(palavra, docId);
    }else if(palavra.compare(raiz->palavra)<0){
        //Vai para esquerda
        raiz->esquerda = adicionar(raiz->esquerda, palavra, docId);
    }else if(palavra.compare(raiz->palavra)>0){
        raiz->direita = adicionar(raiz->direita, palavra, docId);
    }else{
        //Termo igual
        raiz->adicionarItem(docId, 1);
    }
    return raiz;
}
        
void Vocabulario::adicionar(string palavra, string docId){
    raiz = adicionar(raiz, palavra, docId);
}

Termo * Vocabulario::buscar(Termo* raiz, string palavra){
    if (raiz == NULL){
        return NULL;
    }else if(palavra.compare(raiz->palavra)==0){
        return raiz;
    }else if(palavra.compare(raiz->palavra)<0){
        return buscar(raiz->esquerda, palavra);
    }else{
        return buscar(raiz->direita, palavra);
    }
}

Termo * Vocabulario::buscar(string palavra){
    return buscar(raiz, palavra);
}

void Vocabulario::calcularIdf(Termo * termo, int qtdeDocumentos){
    if (termo!=NULL) {
        termo->atualizarIdf(qtdeDocumentos);
        calcularIdf(termo->esquerda, qtdeDocumentos);
        calcularIdf(termo->direita, qtdeDocumentos);
    }
}

void Vocabulario::calcularIdf(int qtdeDocumentos){
    return calcularIdf(raiz, qtdeDocumentos);
}
