#include <stdio.h>
#include <string.h>

int main() {
    char tipo[10], nomealuno[20], nomeprofessor[20], disciplina[15];
    int numeromatricula;
    
    printf("=================================\n");
    printf("    SISTEMA ACADEMICO SIMPLES    \n");
    printf("=================================\n\n");
    
    printf("Voce e aluno ou professor? ");
    scanf("%9s", tipo);
    
    if(strcmp(tipo, "aluno") == 0) {
        printf("\nDigite seu nome: ");
        scanf("%19s", nomealuno);
        
        printf("Digite seu numero de matricula: ");
        scanf("%d", &numeromatricula);

        printf("\n---------------------------------");
        printf("\nAluno: %s", nomealuno);
        printf("\nMatricula: %d", numeromatricula);
        printf("\n---------------------------------\n");
    }
    else if(strcmp(tipo, "professor") == 0) {
        printf("\nDigite seu nome: ");
        scanf("%19s", nomeprofessor);
        
        printf("Digite a disciplina que leciona: ");
        scanf("%14s", disciplina);
        
        printf("\n---------------------------------");
        printf("\nProfessor: %s", nomeprofessor);
        printf("\nDisciplina: %s", disciplina);
        printf("\n---------------------------------\n");
    }
    else {
        printf("\nOpcao invalida! Digite 'aluno' ou 'professor'.\n");
    }
    
    return 0;
}