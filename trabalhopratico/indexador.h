//
//  indexador.h
//  
//
//  Created by Márcio Palheta on 19/02/15.
//
//

#ifndef ____indexador__
#define ____indexador__

#include "core.h"
#include "documento.h"
#include "vocabulario.h"

class Indexador {
private:
    void imprimirDocumentos(Documento *inicio);
public:
    ListaDeDocumentos *listaDeDocumentos;
    Vocabulario * vocabulario;
    void zerarSimilaridadeDocumentos();
    
    Indexador();
    void indexar (char *path);
    void atualizarNormaDocumento();
    void imprimirDocumentos();
    Documento * buscarDocumento(string idDocumento);
};

#endif /* defined(____indexador__) */
