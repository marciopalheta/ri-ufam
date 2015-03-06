//
//  documento.h
//  
//
//  Created by Márcio Palheta on 20/02/15.
//
//

#ifndef ____documento__
#define ____documento__

#include "core.h"
#include "vocabulario.h"

class Documento{
public:
    string idDocumento;
    string texto;
    string textoIndexado;
    Documento * proximo;
    float qtdePalavras;
    float norma;
    
    float similaridade;
    //********* Métodos *********
    Documento();
    static Documento * converterTextoParaDocumento(string texto, Vocabulario * vocabulario);
};


class ListaDeDocumentos{
public:
    Documento * inicio;
    Documento * fim;
    float qtdeDocumentos;
    //********* Métodos *********
    ListaDeDocumentos();
    void adicionar(Documento * documento);
};

#endif /* defined(____documento__) */
