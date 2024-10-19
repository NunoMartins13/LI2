#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_STRING_SIZE 40

int readInt(char *inputString);

char inputString[INPUT_STRING_SIZE];

typedef struct {
  int number;
  char difficulty;
  int price;
} orderID;

int main() {

  int nOrders = 0;
  nOrders = readInt(inputString);
  
  orderID orderInfo[nOrders];
  orderID swapAux;
  
  for (int i = 0; i < nOrders; i++) {
    
    if (fgets(inputString, (int) sizeof(inputString), stdin) != NULL) {}
    if (sscanf(inputString, "%d %c %d", &orderInfo[i].number, &orderInfo[i].difficulty, &orderInfo[i].price) == 1) {}
    //number = (int) strtol(inputString, NULL, 10);
    memset(inputString, 0, (int) sizeof(inputString));
  }

  //[ORDENAR OS MAIS CAROS]
  for (int i = 0; i < nOrders; i++) {
    for (int j = i + 1; j < nOrders; j++) {
      if (orderInfo[i].price < orderInfo[j].price) {
        swapAux =  orderInfo[i];
        orderInfo[i] = orderInfo[j];
        orderInfo[j] = swapAux;
      }
    }
  }

  //[ORDENAR AS DIFICULDADES]
  for (int i = 0; i < nOrders; i++) {
    for (int j = i + 1; j < nOrders; j++) {
      if ((orderInfo[i].price == orderInfo[j].price) && (orderInfo[i].difficulty > orderInfo[j].difficulty)) {
        swapAux =  orderInfo[i];
        orderInfo[i] = orderInfo[j];
        orderInfo[j] = swapAux;
      }
    }
  }

//[ORDENAR OS NUMEROS DOS PEDIDOS]
  for (int i = 0; i < nOrders; i++) {
    for (int j = i + 1; j < nOrders; j++) {
      if ((orderInfo[i].price == orderInfo[j].price) && (orderInfo[i].difficulty == orderInfo[j].difficulty) && (orderInfo[i].number > orderInfo[j].number)) {
        swapAux =  orderInfo[i];
        orderInfo[i] = orderInfo[j];
        orderInfo[j] = swapAux;
      }
    }
  }

  //[OUTPUT]
  for(int i = 0; i < nOrders; i++) {

    printf("%d %c %d\n", orderInfo[i].number, orderInfo[i].difficulty, orderInfo[i].price);
  }
  
  return 0;
}

int readInt(char *inputString) {

  int number = 0;

  if (fgets(inputString, (int) sizeof(inputString), stdin) != NULL) {}
  if (sscanf(inputString, "%d", &number) == 1) {}
  //number = (int) strtol(inputString, NULL, 10);
  memset(inputString, 0, (int) sizeof(inputString));

  return number;
}
