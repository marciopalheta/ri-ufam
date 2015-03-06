//
//  indexador.cpp
//  
//
//  Created by Márcio Palheta on 19/02/15.
//
//

#include "indexador.h"

Indexador::Indexador(){
    listaDeDocumentos = new ListaDeDocumentos();
    vocabulario = new Vocabulario();
}

void Indexador::imprimirDocumentos(Documento * doc){
    if (doc!=NULL) {
        cout<<"\nDoc: "<<doc->idDocumento<<" norma: "<<doc->norma<<" sim: "<<doc->similaridade;
        imprimirDocumentos(doc->proximo);
    }
}
void Indexador::imprimirDocumentos(){
    imprimirDocumentos(listaDeDocumentos->inicio);
}

Documento * Indexador::buscarDocumento(string idDocumento){
    for (Documento * doc = listaDeDocumentos->inicio; doc != NULL; doc = doc->proximo) {
        if (idDocumento.compare(doc->idDocumento)==0) {
            return doc;
        }
    }
    return NULL;
}

void Indexador::atualizarNormaDocumento(){
    for (Documento * doc = listaDeDocumentos->inicio; doc != NULL; doc = doc->proximo) {
        doc->norma = vocabulario->getNorma(doc->idDocumento);
    }
}

void Indexador::zerarSimilaridadeDocumentos(){
    for (Documento * doc = listaDeDocumentos->inicio; doc != NULL; doc = doc->proximo) {
        doc->similaridade = 0;
    }
}

void Indexador::indexar (char *path){
    FILE *arquivo;
    int tamTexto = 6000;
    char texto[tamTexto];
    Documento * doc = NULL;
    
    arquivo = fopen(path,"r");
    
    fgets(texto,tamTexto,arquivo);
    
    while(!feof(arquivo)){
        string str(texto);
        doc = Documento::converterTextoParaDocumento(str, vocabulario);
        cout<<"\nIndexado: ["<<doc->idDocumento<<"] "<<doc->textoIndexado;
        listaDeDocumentos->adicionar(doc);
        fgets(texto,tamTexto,arquivo);
    }
    
    vocabulario->calcularIdf(listaDeDocumentos->qtdeDocumentos);
    atualizarNormaDocumento();
    
    cout<<"\n\nTotal de documentos indexados: "<<listaDeDocumentos->qtdeDocumentos<<"\n";
    
    cout<<"Documentos:";
    imprimirDocumentos();
    
    cout<<"\n\nTotal de termos do vocabulario: "<<vocabulario->qtdeTermos<<"\n\n";
    
    cout<<"Vocabulário: \n";
    
    vocabulario->imprimir(true);
    
    cout<<"\n\n";
    fclose(arquivo);
    
}
/*
int main(int argc, char **argv) {
    
    if (argc!= 2) {
        printf("\tInforme a base de dados para o programa: %s \n",argv[0]);
        exit(1);
    }
    // Path do arquivo, TAG onde o split deve ser realizado, Vetor de tags das quais deseja-se extrair o texto, tamanho do vetor
    Indexador * indexador = new Indexador();
    indexador->indexar(argv[1]);
}
*/