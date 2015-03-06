//
//  core.cpp
//
//
//  Created by Márcio Palheta on 19/02/15.
//
//

#include "core.h"

//********** Implementacao de metodos da classe Util **********

int Util::consultarFrequencia(vector<string> palavras, string palavra){
    int retorno = 0;
    for (int i=0; i<palavras.size(); i++) {
        if (palavra.compare(palavras[i])==0) {
            retorno++;
        }
    }
    return retorno;
}

string Util::substituirAcento(string texto){
    string letrasComAcento[] = {"á","é","í","ó","ú","à", "ç", "â", "ê", "ô", "ã", "õ"};
    string letrasSemAcento[] = {"a","e","i","o","u","a", "c", "a", "e", "o", "a", "o"};
    int tam = sizeof(letrasComAcento)/sizeof(string);
    for (int i=0; i<tam; i++) {
        texto = substituirString(texto, letrasComAcento[i], letrasSemAcento[i]);
    }
    return texto;
}

string Util::substituirString(string &texto, string textoAntigo, string textoNovo){
    std::size_t found = texto.find(textoAntigo);
    while (found!=string::npos) {
        texto.replace(found, textoAntigo.length(), textoNovo);
        found = texto.find(textoAntigo);
    }
    return(texto);
}

vector<string> Util::splitString(const string str, const string delimiters){
    vector<string> tokens;
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos = str.find_first_of(delimiters, lastPos);
    
    while (string::npos != pos || string::npos != lastPos){
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
    return tokens;
}


bool Util::isStopWord(string palavra){
    string listaDeStopWords[] = {";",",",".","-", "A","AGORA","AINDA","ALGUÉM","ALGUM","ALGUMA","ALGUMAS","ALGUNS","AMPLA","AMPLAS","AMPLO","AMPLOS","ANTE","ANTES","AO","AOS","APÓS","AQUELA","AQUELAS","AQUELE","AQUELES","AQUILO","AS","ATÉ","ATRAVÉS","CADA","COISA","COISAS","COM","COMO","CONTRA","CONTUDO","DA","DAQUELE","DAQUELES","DAS","DE","DELA","DELAS","DELE","DELES","DEPOIS","DESSA","DESSAS","DESSE","DESSES","DESTA","DESTAS","DESTE","DESTE","DESTES","DEVE","DEVEM","DEVENDO","DEVER","DEVERÁ","DEVERÃO","DEVERIA","DEVERIAM","DEVIA","DEVIAM","DISSE","DISSO","DISTO","DITO","DIZ","DIZEM","DO","DOS","E","É","ELA","ELAS","ELE","ELES","EM","ENQUANTO","ENTRE","ERA","ESSA","ESSAS","ESSE","ESSES","ESTA","ESTÁ","ESTAMOS","ESTÃO","ESTAS","ESTAVA","ESTAVAM","ESTÁVAMOS","ESTE","ESTES","ESTOU","EU","FAZENDO","FAZER","FEITA","FEITAS","FEITO","FEITOS","FOI","FOR","FORAM","FOSSE","FOSSEM","GRANDE","GRANDES","HÁ","ISSO","ISTO","JÁ","LA","LÁ","LHE","LHES","LO","MAS","ME","MESMA","MESMAS","MESMO","MESMOS","MEU","MEUS","MINHA","MINHAS","MUITA","MUITAS","MUITO","MUITOS","NA","NÃO","NAS","NEM","NENHUM","NESSA","NESSAS","NESTA","NESTAS","NINGUÉM","NO","NOS","NÓS","NOSSA","NOSSAS","NOSSO","NOSSOS","NUM","NUMA","NUNCA","O","OS","OU","OUTRA","OUTRAS","OUTRO","OUTROS","PARA","PELA","PELAS","PELO","PELOS","PEQUENA","PEQUENAS","PEQUENO","PEQUENOS","PER","PERANTE","PODE","PUDE","PODENDO","PODER","PODERIA","PODERIAM","PODIA","PODIAM","POIS","POR","PORÉM","PORQUE","POSSO","POUCA","POUCAS","POUCO","POUCOS","PRIMEIRO","PRIMEIROS","PRÓPRIA","PRÓPRIAS","PRÓPRIO","PRÓPRIOS","QUAIS","QUAL","QUANDO","QUANTO","QUANTOS","QUE","QUEM","SÃO","SE","SEJA","SEJAM","SEM","SEMPRE","SENDO","SERÁ","SERÃO","SEU","SEUS","SI","SIDO","SÓ","SOB","SOBRE","SUA","SUAS","TALVEZ","TAMBÉM","TAMPOUCO","TE","TEM","TENDO","TENHA","TER","TEU","TEUS","TI","TIDO","TINHA","TINHAM","TODA","TODAS","TODAVIA","TODO","TODOS","TU","TUA","TUAS","TUDO","ÚLTIMA","ÚLTIMAS","ÚLTIMO","ÚLTIMOS","UM","UMA","UMAS","UNS","VENDO","VER","VEZ","VINDO","VIR","VOS","VÓS"};
    
    int tam = sizeof(listaDeStopWords)/sizeof(string);
    for (int i=0; i<tam; i++) {
        if (listaDeStopWords[i].compare(palavra) == 0) {
            return true;
        }
    }
    
    return false;
}
