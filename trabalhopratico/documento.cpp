//
//  documento.cpp
//  
//
//  Created by Márcio Palheta on 20/02/15.
//
//

#include "documento.h"

Documento::Documento(){
    idDocumento = "";
    texto = "";
    textoIndexado = "";
    proximo = NULL;
    qtdePalavras = 0;
    norma = 0;
    similaridade = 0;
}

Documento * Documento::converterTextoParaDocumento(string texto, Vocabulario * vocabulario){
    Documento * doc = new Documento();
    vector<string> palavras = Util::splitString(texto);
    string palavra;
    
    doc->idDocumento = palavras[0];
    doc->texto = texto;
    doc->proximo = NULL;
    
    //cout<<"\nPalavras***********\n";
    
    for (int i=1; i<palavras.size(); i++) {
        palavra = palavras[i];
        //cout<<palavra<<" ";
        if (!Util::isStopWord(palavra)) {
            vocabulario->adicionar(palavra, doc->idDocumento);
            doc->textoIndexado += palavra+" ";
            doc->qtdePalavras++;
        }
    }
    
    //cout<<"\nPalavras***********\n";
    
    return doc;
}

ListaDeDocumentos::ListaDeDocumentos(){
    inicio = NULL;
    fim = NULL;
    qtdeDocumentos = 0;
}

void ListaDeDocumentos::adicionar(Documento * documento){
    qtdeDocumentos++;
    if(inicio == NULL){
        inicio = documento;
        fim = documento;
    }else{
        fim->proximo = documento;
        fim = documento;
    }
}
