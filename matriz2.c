#include <stdio.h>
char Matriz[4][4]= {254, 254, 254, 254,
254, 254, 254, 254,
254, 254, 254, 254,
254, 254, 254, 254,

};
int main()
{
int i,z;
for(z=0;z<4;z++){
for(i=0;i<4;i++){
printf("%c ", Matriz[z][i]);

    }
    printf("\n");
}
return 0;
}