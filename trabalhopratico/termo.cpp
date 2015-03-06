//
//  termo.cpp
//  
//
//  Created by Márcio Palheta on 20/02/15.
//
//

#include "termo.h"

ItemLI::ItemLI(string doc, float freq){
    docId = doc;
    tf = freq;
    coord = 0;
    proximo = NULL;
}

float Termo::buscarCoordenadaDocumento(string idDocumento){
    ItemLI * item = buscarItem(idDocumento);
    if(item == NULL){
        return 0;
    }else{
        return item->coord;
    }
}

void Termo::atualizarCoordenadas(){
    for (ItemLI * item = inicio; item!=NULL; item = item->proximo) {
        item->coord = idf * item->tf;
    }
}

Termo::Termo(string texto, string doc){
    palavra = texto;
    idf = 0;
    esquerda = NULL;
    direita = NULL;
    inicio = NULL;
    fim = NULL;
    
    //frequencia na colecao
    tf = 0;
    //frequencia no documento
    adicionarItem(doc, 1);
}

void Termo::atualizarIdf(int qtdeDocumentos){
    idf = log((float)qtdeDocumentos / (float)contarItens());
    atualizarCoordenadas();
}

void Termo::imprimirItens(ItemLI * item){
    if(item != NULL){
        cout<<" li("<<item->docId<<","<<item->tf<<") w("<<item->coord<<") ; ";
        imprimirItens(item->proximo);
    }
}

void Termo::imprimirItens(){
    imprimirItens(inicio);
}

ItemLI * Termo::buscarItem(string docId){
    return buscarItem(inicio, docId);
}

ItemLI * Termo::buscarItem(ItemLI * item, string docId){
    if (item==NULL) {
        return NULL;
    }else if(item->docId.compare(docId)==0){
        return item;
    }else{
        return buscarItem(item->proximo, docId);
    }
}

int Termo::contarItens(ItemLI * item){
    if (item == NULL) {
        return 0;
    }else{
        return 1+contarItens(item->proximo);
    }
}

int Termo::contarItens(){
    return contarItens(inicio);
}

void Termo::adicionarItem(string docId, float freq){
    //TF na Colecao
    tf+=freq;
    //busca por item
    ItemLI * item = buscarItem(inicio, docId);
    if (item==NULL) {
        item = new ItemLI(docId, freq);
        if (inicio == NULL) {
            inicio = item;
            fim = inicio;
        }else{
            fim->proximo = item;
            fim = item;
        }
    }else{
        item->tf++;
    }
}