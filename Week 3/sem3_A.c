/*
[INPUT]
1º Input: Uma linha com as posições das letras (máx 8 posições).
          Cada posição aparece uma só vez na lista

2º Input: Uma linha com a mensagem (máx 1000 caracteres).

O número de dígitos do 1ºinput é quantas vezes vamos dividor o 2º input

Ex:
31254 - 5 digitos (podemos ver o numero maximo para saber quantos codigos vamos precisar dividir)

ATACA MOSAO AMANH ECERP REPAR EMAAG UARDE NTEEA MANTE IGA

1 AMAEREUNMI
2 TOMCEMATAG
3 ASAEPARENA
4 CANRAADET
5 AOHPRGEAE

Reornedação

3 ASAEPARENA
1 AMAEREUNMI
2 TOMCEMATAG
5 AOHPRGEAE
4 CANRAADET

[OUTPUT]

Deve imprimir a mensagem com todas as letras da 3ª posição primeiro, depois da 1ª posição, etc.
*/

#include <stdio.h>
#include <string.h>

int main() {

	int codePosition, block, messageSize;
	static int encryptedPosition=0;
	char codeOrder[10], initialMessage[1001];

	if (fgets(codeOrder, (int) sizeof(codeOrder), stdin) != NULL) codeOrder[strcspn(codeOrder, "\n")] = 0;
	
	block = strlen(codeOrder);

	if (fgets(initialMessage, (int) sizeof(initialMessage), stdin) != NULL) initialMessage[strcspn(initialMessage,"\n")] = 0;
	
	messageSize = strlen(initialMessage);

	char encryptedMessage[messageSize + 1];

	for (int i = 0; i < block; i++) {

		codePosition = (int) codeOrder[i] - 48;

		for (int j = 0, k = 0; j + block < messageSize; k++) {

			j = (k * block) + codePosition - 1;

			encryptedMessage[encryptedPosition] = initialMessage[j];

			encryptedPosition++;
		}
	}
	encryptedMessage[messageSize] = '\0';

	puts(encryptedMessage);

	return 0;
}
