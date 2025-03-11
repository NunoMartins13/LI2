#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INPUT_STRING_SIZE 301

int readInt(char *inputString);
bool checkRepeatedInt(int **results, int ROW, int guiche);
int guichePath(int **results, int *guicheList, int totalGuiches, int initialGuiche, int ROW);

int main() {

  char inputString[INPUT_STRING_SIZE];
  int nCases = 0, initialGuiche = 0;

  nCases = readInt(inputString);

  int **results = (int**) calloc(nCases, sizeof(int*));
  int *totalGuiches = (int*) calloc(nCases, sizeof(int));
  int *flags = (int*) calloc(nCases, sizeof(int));

  for (int i = 0; i < nCases; i++) {

    totalGuiches[i] = readInt(inputString);
    if (totalGuiches[i] < 1 || totalGuiches[i] > 100) abort();
    initialGuiche = readInt(inputString);

    int *guicheList = (int*) calloc(totalGuiches[i], sizeof(int));

    if (fgets(inputString, (int) sizeof(inputString), stdin) != NULL) inputString[strcspn(inputString, "\n")] = 0;
    char *data = inputString;

    for(int n = 0, offset; (n < totalGuiches[i]) && (sscanf(data, " %d%n", &guicheList[n], &offset) == 1); n++) data += offset;
    memset(inputString, 0, (int) sizeof(inputString));

    results[i] = (int*) calloc((totalGuiches[i] + 1), sizeof(int));

    flags[i] = guichePath(results, guicheList, totalGuiches[i], initialGuiche, i);

    free(guicheList);
  }
  //[OUTPUT]
  for(int i = 0, j; i < nCases; i++) {

    for(j = 0; results[i][j + 1] != 0; j++) printf("%d ",results[i][j]);

    printf("%d",results[i][j]);

    if(flags[i] == 0) printf(" CICLO INFERNAL");

    printf("\n");
  }
  //[Dar free á memory]
  free(flags);
  free(totalGuiches);
  for(int i = 0; i < nCases; i++) free(results[i]);
  free(results);

  return 0;
}

int guichePath(int **results, int *guicheList, int totalGuiches, int initialGuiche, int ROW) {

  results[ROW][0] = initialGuiche;

  if (guicheList[initialGuiche - 1] == 0) return 1;
  results[ROW][1] = guicheList[initialGuiche - 1];

  for(int i = 2; i < totalGuiches; i++) {

    if(guicheList[results[ROW][i-1] - 1] == 0) return 1;
    if (checkRepeatedInt(results, ROW, guicheList[results[ROW][i-1] - 1])) return 0;

    else results[ROW][i] = guicheList[results[ROW][i-1] - 1];
  }

  if (checkRepeatedInt(results, ROW, guicheList[results[ROW][totalGuiches-1] - 1])) return 0;

  return 1;
}

bool checkRepeatedInt(int **results, int ROW, int guiche) {

  for (int i = 0; results[ROW][i] != 0; i++) {

    if(guiche == results[ROW][i]) return true;
  }
  return false;
}

int readInt(char *inputString) {

  int number = 0;

  if (fgets(inputString, (int) sizeof(inputString), stdin) != NULL) {}
  if (sscanf(inputString, "%d", &number) == 1) {}
  //number = (int) strtol(inputString, NULL, 10);
  memset(inputString, 0, (int) sizeof(inputString));

  return number;
}
