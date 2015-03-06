//
//  core.h
//  
//
//  Created by Márcio Palheta on 19/02/15.
//
//

#ifndef ____core__
#define ____core__

#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <iostream>

using namespace std;


class Util{
public:
    static bool isStopWord(string texto);
    static string substituirAcento(string texto);
    static string substituirString(string &texto, string textoAntigo, string textoNovo);
    static vector<string> splitString(const string str,const string delimiters = " ,./-\n\t");
    static int consultarFrequencia(vector<string> palavras, string palavra);
};

#endif /* defined(____core__) */
