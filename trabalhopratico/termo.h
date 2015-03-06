//
//  termo.h
//  
//
//  Created by Márcio Palheta on 20/02/15.
//
//

#ifndef ____termo__
#define ____termo__

#include<math.h>
#include "core.h"

class ItemLI{
public:
    string docId;
    float tf;
    float coord;
    ItemLI * proximo;
    
    ItemLI(string docId, float freq);
    void atualizarCoord(ItemLI * item, float idf);
};

class Termo{
private:
    ItemLI * buscarItem(ItemLI * item, string docId);
    void imprimirItens(ItemLI * item);
    int contarItens(ItemLI * item);
public:
    string palavra;
    float tf;
    float idf;
    Termo * esquerda;
    Termo * direita;
    ItemLI * inicio;
    ItemLI * fim;
    int contarItens();
    void atualizarCoordenadas();
    
    //********* Métodos *********
    Termo(string texto, string doc);
    void adicionarItem(string docId, float tf);
    void imprimirItens();
    void atualizarIdf(int qtdeDocumentos);
    ItemLI * buscarItem(string docId);
    float buscarCoordenadaDocumento(string idDocumento);
};

#endif /* defined(____termo__) */
