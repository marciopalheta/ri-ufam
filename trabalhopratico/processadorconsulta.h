//
//  processadorconsulta.h
//  
//
//  Created by Márcio Palheta on 24/02/15.
//
//

#ifndef ____processadorconsulta__
#define ____processadorconsulta__
#include <math.h>
#include "core.h"
#include "indexador.h"

class Processador{
private:
    int tamanhoRanking;
    vector<Documento*> ranking;
    void ordenarRanking();
    void zerarContadores();
public:
    Indexador * indexador;
    Processador(char * path);
    vector<Documento*> buscar(string query);
    void atualizarSimilaridade(Termo * termo, float coordenadaConsulta);
    void atualizarSimilaridade(Documento * doc, float normaConsulta);
    void imprimirRanking();
};

#endif /* defined(____processadorconsulta__) */
