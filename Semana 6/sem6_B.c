#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INPUT_STRING_SIZE 40

int readInt(char *inputString);

char inputString[INPUT_STRING_SIZE];

typedef struct {
  char name[15];
  int weight;
  int height;
  int weightDiff;
} cookID;

int main() {

  int nCooks = 0;
  nCooks = readInt(inputString);
  
  cookID cookInfo[nCooks];
  cookID swapAux;
  
  for (int i = 0; i < nCooks; i++) {
    
    if (fgets(inputString, (int) sizeof(inputString), stdin) != NULL) {}
    if (sscanf(inputString, "%s %d %d", cookInfo[i].name, &cookInfo[i].weight, &cookInfo[i].height) == 1) {}
    //number = (int) strtol(inputString, NULL, 10);
    memset(inputString, 0, (int) sizeof(inputString));
    cookInfo[i].weightDiff = abs(90 - cookInfo[i].weight);
  }

  //[ORDENAR OS PESOS]
  for (int i = 0; i < nCooks; i++) {
    for (int j = i + 1; j < nCooks; j++) {
      if (cookInfo[i].weightDiff > cookInfo[j].weightDiff) {
        swapAux =  cookInfo[i];
        cookInfo[i] = cookInfo[j];
        cookInfo[j] = swapAux;
      }
    }
  }

  //[ORDENAR AS ALTURAS]
  for (int i = 0; i < nCooks; i++) {
    for (int j = i + 1; j < nCooks; j++) {
      if ((cookInfo[i].height < cookInfo[j].height) && (cookInfo[i].weightDiff >= cookInfo[j].weightDiff)) {
        swapAux =  cookInfo[i];
        cookInfo[i] = cookInfo[j];
        cookInfo[j] = swapAux;
      }
    }
  }

//[ORDENAR OS NOMES]
  for (int i = 0; i < nCooks; i++) {
    for (int j = i + 1; j < nCooks; j++) {
      if ((cookInfo[i].height <= cookInfo[j].height) && (cookInfo[i].weightDiff >= cookInfo[j].weightDiff) && (strcmp(cookInfo[i].name, cookInfo[j].name) > 0)) {
        swapAux =  cookInfo[i];
        cookInfo[i] = cookInfo[j];
        cookInfo[j] = swapAux;
      }
    }
  }

  //[OUTPUT]
  for(int i = 0; i < nCooks; i++) {

    printf("%s %d %d\n", cookInfo[i].name, cookInfo[i].weight, cookInfo[i].height);
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
