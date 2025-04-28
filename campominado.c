#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void exibirTabuleiro(int campofake[10][10]) {
    printf("\n    0   1   2   3   4   5   6   7   8   9\n");
    printf("  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ║", i);
        for(int j = 0; j < 10; j++) {
            printf(" %c ║", campofake[i][j]);
        }
        if(i < 9) {
            printf("\n  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
        }
    }
    printf("\n  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n");
}

int main(int argc, char *argv[]) {
    int quantbombas, campo[10][10], contador, contador1, contador3, posi1, posi2, campofake[10][10], pontos, Bperto;
    char ch[10];
    
    while(1) {
        pontos = 0;
        contador3 = 0;
        limparTela();
        
        printf("╔════════════════════════════════════════╗\n");
        printf("║          JOGO CAMPO MINADO             ║\n");
        printf("╚════════════════════════════════════════╝\n\n");
        
        printf("Digite a quantidade de bombas (1-99): ");
        scanf("%d", &quantbombas);
        
        if(quantbombas <= 0 || quantbombas >= 100) {
            printf("\nQuantidade inválida! Digite um número entre 1 e 99.\n");
            getchar(); // Limpa o buffer do teclado
            getchar(); // Espera Enter
            continue;
        }
        
        // Preenche o campo e campo fake
        for(contador = 0; contador < 10; contador++) {
            for(contador1 = 0; contador1 < 10; contador1++) {
                campo[contador][contador1] = 36;  // '$' em ASCII
                campofake[contador][contador1] = 36;
            }
        }
            
        srand(time(NULL));
        // Posiciona as bombas aleatoriamente
        while(contador3 < quantbombas) {
            posi1 = rand() % 10;
            posi2 = rand() % 10;
            if(campo[posi1][posi2] != 225) {  // 'á' em ASCII representa a bomba
                campo[posi1][posi2] = 225;
                contador3++;
            }
        }
        
        while(pontos < 100 - quantbombas) {
            limparTela();
            printf("╔════════════════════════════════════════╗\n");
            printf("║          JOGO CAMPO MINADO             ║\n");
            printf("║ Bombas: %-3d    Pontuação: %-3d/%-3d     ║\n", quantbombas, pontos, 100-quantbombas);
            printf("╚════════════════════════════════════════╝\n");
            
            exibirTabuleiro(campofake);
            
            printf("\nOpções:\n");
            printf("1. Marcar - digite 'marcar [linha] [coluna]'\n");
            printf("2. Revelar - digite 'revelar [linha] [coluna]'\n");
            printf("3. Desistir - digite 'desistir'\n");
            printf("\nSua jogada: ");
            scanf("%s", ch);
            
            if(strcmp(ch, "marcar") == 0) {
                scanf("%d %d", &posi1, &posi2);
                if(posi1 >= 0 && posi1 < 10 && posi2 >= 0 && posi2 < 10) {
                    campofake[posi1][posi2] = 66;  // 'B' em ASCII
                } else {
                    printf("\nCoordenadas inválidas! Use valores entre 0 e 9.\n");
                    getchar(); getchar();
                }
            }
            else if(strcmp(ch, "revelar") == 0) {
                scanf("%d %d", &posi1, &posi2);
                if(posi1 < 0 || posi1 >= 10 || posi2 < 0 || posi2 >= 10) {
                    printf("\nCoordenadas inválidas! Use valores entre 0 e 9.\n");
                    getchar(); getchar();
                    continue;
                }
                
                if(campo[posi1][posi2] == 225) {
                    limparTela();
                    printf("╔════════════════════════════════════════╗\n");
                    printf("║             FIM DE JOGO!               ║\n");
                    printf("║         Você atingiu uma bomba!         ║\n");
                    printf("╚════════════════════════════════════════╝\n");
                    
                    // Mostra o tabuleiro completo com as bombas
                    for(int i = 0; i < 10; i++) {
                        for(int j = 0; j < 10; j++) {
                            if(campo[i][j] == 225) {
                                campofake[i][j] = 225;  // Mostra todas as bombas
                            }
                        }
                    }
                    exibirTabuleiro(campofake);
                    printf("\nPressione Enter para continuar...");
                    getchar(); getchar();
                    break;
                }
                else if(campofake[posi1][posi2] == 36 || campofake[posi1][posi2] == 66) {
                    Bperto = 48;  // '0' em ASCII
                    for(int i = posi1-1; i <= posi1+1; i++) {
                        for(int j = posi2-1; j <= posi2+1; j++) {
                            if(i >= 0 && i < 10 && j >= 0 && j < 10 && campo[i][j] == 225) {
                                Bperto++;
                            }
                        }
                    }
                    campofake[posi1][posi2] = Bperto;
                    pontos++;
                }
            }
            else if(strcmp(ch, "desistir") == 0) {
                printf("\nVocê desistiu do jogo.\n");
                break;
            }
            else {
                printf("\nComando inválido! Use 'marcar', 'revelar' ou 'desistir'.\n");
                getchar(); getchar();
            }
        }
        
        if(pontos == 100 - quantbombas) {
            limparTela();
            printf("╔════════════════════════════════════════╗\n");
            printf("║         PARABÉNS! VOCÊ VENCEU!        ║\n");
            printf("╚════════════════════════════════════════╝\n");
            exibirTabuleiro(campofake);
            printf("\nPressione Enter para continuar...");
            getchar(); getchar();
        }
        
        printf("\nDeseja jogar novamente? (s/n): ");
        char opcao;
        scanf(" %c", &opcao);
        if(opcao != 's' && opcao != 'S') {
            break;
        }
    }
    
    limparTela();
    printf("Obrigado por jogar!\n");
    return 0;
}