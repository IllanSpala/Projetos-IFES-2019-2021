#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  
    float media,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
        
    printf("Digite o primeiro valor:");
    scanf ("%f", &n1);

    printf("Digite o segundo valor:");
    scanf ("%f", &n2);
       
    printf("Digite o terceiro valor:");
    scanf ("%f", &n3);
    
    printf("Digite o quarto valor:");
    scanf ("%f", &n4);
    
    printf("Digite o quinto valor:");
    scanf ("%f", &n5);
     
    printf("Digite o sexto valor:");
    scanf ("%f", &n6);
     
    printf("Digite o  setimo valor:");
    scanf ("%f", &n7);
     
    printf("Digite o oitavo valor:");
    scanf ("%f", &n8);
     
    printf("Digite o nono valor:");
    scanf ("%f", &n9);
     
    printf("Digite  o decimo valor:");
    scanf ("%f", &n10);
    
    media=(n1+n2+n3+n4+n5+n6+n7+n8+n9+n10)/10;
        
    printf ("media: %f", media);

	return 0;
}
