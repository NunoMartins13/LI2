/*
- Inicialmente começa na casa 5;
- Comandos: C (cima), B (baixo), E (esquerda) e D (direita).
- Caso não seja possível mover-se numa dada direção, continua na casa em que está;
- Cada nova linha mantém a posição anterior.

[INPUT]
-> Uma linha com um número N que corresponde ao número de linhas;
-> N linhas tendo cada uma comandos de direção (no máximo são 20 comandos);

[OUTPU]
-> N números, cada um sendo o nº em que se ficou depois de cada sequencia de comandos.
*/

#include <stdio.h>
#include <string.h>

int main() {
    
    static int x = 2, y = 2;
    int currentKey = 0, totalSequences = 0;
    int keyPad[5][5] = {{0,0,0,0,0}, {0,7,8,9,0}, {0,4,5,6,0}, {0,1,2,3,0}, {0,0,0,0,0}};
    char keyPadSequence[22];
    
    if (scanf("%d",&totalSequences) == 1) { }
    getchar();

    int closureCode[totalSequences];

    for (int i = 0; i < totalSequences; i++) {

        memset(keyPadSequence, 0, sizeof(keyPadSequence));
        
        if (fgets(keyPadSequence, (int) sizeof(keyPadSequence), stdin) != NULL) { }

        for (int j = 0; keyPadSequence[j] != '\n'; j++) {

            switch (keyPadSequence[j]) {

                case 'B': 
                    if (keyPad[x+1][y] != 0) x++;
                    break;

                case 'C': 
                    if (keyPad[x-1][y] != 0) x--;
                    break;

                case 'D': 
                   if (keyPad[x][y+1] != 0) y++;
                    break;
                
                case 'E': 
                  if (keyPad[x][y-1] != 0) y--;
                    break;

                default: printf("error\n");
            }
            currentKey = keyPad[x][y];
        }
        closureCode[i] = currentKey;
    }
    for (int k=0; k < totalSequences; k++)  printf("%d",closureCode[k]);

    printf("\n");

    return 0;
}
