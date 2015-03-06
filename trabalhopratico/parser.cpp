#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "core.h"

/********************************************************************************************************************************************************************/
char *getContentFile(char *path){
    int indic,tam;
    char *arquivo;
    struct stat buffer; /* Estrutura para descobrir o tamanho do arquivo*/
    
    indic = open(path,O_RDONLY);  /* Abre o arquivo */
    
    if (indic == -1) /* Verifica a abertura do arquivo */
    {
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }
    
    fstat(indic, &buffer); /* Grava a estrutura stat */
    tam = buffer.st_size;  /* Retorna o tamanho do arquivo */
    arquivo = (char *)malloc(sizeof(char) * (tam+1)); /* Aloca o tamanho do arquivo + 1 */
    read (indic,arquivo, tam);  /* Ler para o buffer o conteudo do arquivo */
    arquivo[tam]='\0';  /* Transforma em string */
    close(indic); /* Fecha o arquivo */
    
    return arquivo;  /* Retorna o conteudo */
}
/********************************************************************************************************************************************************************/
int buscaTag (char *tag, char *tagsDesejadas[], int tam) {
    int x;
    
    for (x=0;x<tam;x++) {
        if (strcasecmp(tag, tagsDesejadas[x])==0) return 1;
    }
    
    return 0;
}
/********************************************************************************************************************************************************************/
void parserCFC (const char *cfc, char *tagFinal, char *tagsDesejadas[], int tam){
    int indiceTexto = 0, tamTexto = strlen(cfc), indiceTag = 0, indiceConteudo = 0;
    
    char *tag = (char *)malloc(sizeof(char)*tamTexto);
    char *conteudo = (char *)malloc(sizeof(char)*tamTexto);
    char *texto = (char *)malloc(sizeof(char)*tamTexto);
    char recordNUM[500];
    strcpy(texto,"");
    
    string str(cfc);
    str = Util::substituirAcento(str);
    cfc = str.c_str();
    //cout<<"***********************************************************************\n";
    //cout<<cfc;
    //cout<<"\n***********************************************************************\n";
    
    while (indiceTexto<tamTexto) {
        
        if (cfc[indiceTexto] == '<') { // Comeca uma tag
            indiceTag = 0;
            while (cfc[indiceTexto]!='>'){ // armazena a tag
                tag[indiceTag] = cfc[indiceTexto];
                indiceTag++;
                indiceTexto++;
            }
            tag[indiceTag] = cfc[indiceTexto];
            indiceTag++;
            tag[indiceTag] = '\0';
        }
        
        if (buscaTag (tag, tagsDesejadas, tam) == 1){
            indiceTexto++;
            indiceConteudo = 0;
            while (cfc[indiceTexto]!='<'){ // armazena a tag
                conteudo[indiceConteudo] = toupper(cfc[indiceTexto]);
                indiceConteudo++;
                indiceTexto++;
            }
            conteudo[indiceConteudo] = '\0';
            strcat(texto, conteudo);
            strcat(texto," ");
            indiceTexto--;
            if (strcmp("<id>",tag)==0) { // Identificador do documento
                strcpy(recordNUM,conteudo);
            }
        }
        
        if (strcmp(tag,tagFinal)==0) { // indica que um documento terminou
            if (strlen(texto)!=0) {
                printf("%s\n", texto);
                strcpy(texto,"");
                strcpy(recordNUM,"");
            }	
        }
        indiceTexto++;
    }
    
    //printf("Documento: %s\n\n\n",texto); // Imprime o ultimo documento
}

int main(int argc, char **argv) {
    
    char *tagsDesejadas[] = {"<categoria>","<titulo>","<descricao>","<id>"};
    
    if (argc!= 2) {
        printf("\tusage: %s <cfc>\n",argv[0]); 
        exit(1);
    }
    
    // Path do arquivo, TAG onde o split deve ser realizado, Vetor de tags das quais deseja-se extrair o texto, tamanho do vetor
    parserCFC (getContentFile(argv[1]),"</produto>", tagsDesejadas, 4);
    
    
}


