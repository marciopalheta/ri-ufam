//
//  vocabulario.h
//  
//
//  Created by Márcio Palheta on 20/02/15.
//
//

#ifndef ____vocabulario__
#define ____vocabulario__

#include "core.h"
#include "termo.h"
#include <math.h>

class Vocabulario{
    void imprimirEmOrdem(Termo* raiz);
    void calcularIdf(Termo * termo, int qtdeDocumentos);
public:
    Termo * raiz;
    float qtdeTermos;
    //********* Métodos *********
    Vocabulario();
    void adicionar(string palavra, string docId);
    Termo * adicionar(Termo *raiz, string palavra, string docId);
    Termo * buscar(string palavra);
    Termo * buscar(Termo* raiz, string palavra);
    void imprimir(bool itens=false);
    void imprimir(Termo *termo, bool itens);
    void calcularIdf(int qtdeDocumentos);
    float getNorma(string idDocumento);
    float somarQuadradoCoordenadas(Termo * termo, string idDocumento);
};

#endif /* defined(____vocabulario__) */
