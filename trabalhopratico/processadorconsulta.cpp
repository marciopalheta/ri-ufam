//
//  processadorconsulta.cpp
//
//
//  Created by Márcio Palheta on 24/02/15.
//
//

#include "processadorconsulta.h"

Processador::Processador(char * path){
    indexador = new Indexador();
    indexador->indexar(path);
    tamanhoRanking = 10;
}

void Processador::zerarContadores(){
    ranking.erase(ranking.begin(), ranking.end());
    indexador->zerarSimilaridadeDocumentos();
}

void Processador::imprimirRanking(){
    for (int i=0; i<ranking.size(); i++) {
        cout<<"\nDoc: "<<ranking[i]->idDocumento<<" norma: "<<ranking[i]->norma<<" sim: "<<ranking[i]->similaridade;
    }
}

void Processador::ordenarRanking(){
    for (int i=0; i<ranking.size(); i++) {
        for (int j=i+1; j<ranking.size(); j++) {
            if(ranking[i]->similaridade < ranking[j]->similaridade){
                Documento * aux = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = aux;
            }
        }
    }
    if (ranking.size()>tamanhoRanking) {
        ranking.resize(tamanhoRanking);
    }
}

void Processador::atualizarSimilaridade(Termo * termo, float coordenadaConsulta){
    for (ItemLI * item = termo->inicio; item!=NULL; item = item->proximo) {
        Documento * doc = indexador->buscarDocumento(item->docId);
        //incremento da similaridade
        doc->similaridade+=item->coord*coordenadaConsulta;
    }
}

void Processador::atualizarSimilaridade(Documento * doc, float normaConsulta){
    if (doc!=NULL) {
        doc->similaridade = (doc->similaridade)/(doc->norma*normaConsulta);
        ranking.push_back(doc);
        atualizarSimilaridade(doc->proximo, normaConsulta);
    }
}

vector<Documento*> Processador::buscar(string query){
    vector<string> palavras = Util::splitString(query);
    vector<Termo>termosDaConsulta;
    
    float tf = 0;
    float coordenada = 0;
    float normaConsulta = 0;
    
    zerarContadores();
    
    for (int i = 0; i<palavras.size(); i++) {
        string palavra = palavras[i];
        tf = Util::consultarFrequencia(palavras, palavra);
        Termo * termo = indexador->vocabulario->buscar(palavra);
        coordenada = termo->idf * tf;
        normaConsulta+=pow(coordenada, 2);
        atualizarSimilaridade(termo, coordenada);
    }
    
    normaConsulta = sqrt(normaConsulta);
    /*
     cout<<"Documentos com acumuladores:";
     indexador->imprimirDocumentos();
     cout<<"\n";
     */
    atualizarSimilaridade(indexador->listaDeDocumentos->inicio, normaConsulta);
    ordenarRanking();
    
    return ranking;
}

int main(int argc, char **argv) {
    
    if (argc == 1) {
        printf("\tInforme a base de documentos para: %s \n",argv[0]);
        exit(1);
    }else if (argc == 2) {
        printf("\tInforme a base de consultas para: %s \n",argv[0]);
        exit(1);
    }
    
    Processador * processador = new Processador(argv[1]);
    vector<Documento*> resposta = processador->buscar("X B");
    
    cout<<"Documentos:";
    processador->indexador->imprimirDocumentos();
    cout<<"\n\n";
    
    cout<<"Ranking:";
    processador->imprimirRanking();
    cout<<"\n\n";
}