#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INPUT_STRING_SIZE 50

int readInt(char *inputString);
void assignID(int **logs,int ID, int arrival, int departure);
bool checkRepeatedInt(int **logs, int hour, int ID);
int compare(const void *a, const void *b);

int main() {

  char inputString[INPUT_STRING_SIZE];
  int IDs = 0, nCases = 0;

  IDs = readInt(inputString);
  if (IDs < 2 || IDs > 100) abort();
  nCases = readInt(inputString);
  if (nCases < 2 || nCases > 5000) abort();

  int **logs = (int**) calloc(24, sizeof(int*));

  for (int i = 0; i < 24; i++) logs[i] = (int*) calloc((IDs + 2), sizeof(int));

  for (int i = 0; i < nCases; i++) {

    int ID = 0, arrival = 0, departure = 0;

    int *info = (int*) calloc(3, sizeof(int));

    if (fgets(inputString, (int) sizeof(inputString), stdin) != NULL) inputString[strcspn(inputString, "\n")] = 0;
    char *data = inputString;
    for(int n = 0, offset; (n < 3) && (sscanf(data, " %d%n", &info[n], &offset) == 1); n++) data += offset;
    memset(inputString, 0, (int) sizeof(inputString));

    ID = info[0];
    arrival = info[1];
    departure = info[2];

    if ((arrival < 0 || arrival > 23) || (departure < 0 || departure > 23) || (arrival > departure)) abort();

    assignID(logs, ID, arrival, departure);

    free(info);
  }

  //[Nº de IDs em cada hora]
  int logSize[24] = {0};
  for(int i = 0, count; i < 24; i++) {
    count = 0;
    for(int j = 0; logs[i][j] != 0; j++) count++;
    logSize[i] = count;
  }

  //[Organizar IDs]
  for(int i = 0; i < 24; i++) qsort(logs[i], logSize[i], sizeof(int), compare);

  //[OUTPUT]
  for(int i = 0, j; i < 24; i++) {

    if(logSize[i] > 1) {
      printf("%d",i);
      for(j = 0; logs[i][j] != 0; j++) printf(" %d",logs[i][j]);
      printf("\n");
    }
  }

  //[Dar free á memory]
  for(int i = 0; i < 24; i++) free(logs[i]);
  free(logs);

  return 0;
}

void assignID(int **logs,int ID, int arrival, int departure) {

  for (int i = arrival; i <= departure; i++) {
    int j = 0;
    if (checkRepeatedInt(logs, i, ID) == 0) {

      for (j = 0; logs[i][j] != 0; j++) {}

      logs[i][j] = ID;
    }
  }
}

bool checkRepeatedInt(int **logs, int hour, int ID) {

  for (int i = 0; logs[hour][i] != 0; i++) {

    if(ID == logs[hour][i]) return true;
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

int compare(const void* a, const void* b) {
  const int *a_int = (const int*) a;
  const int *b_int = (const int*) b;
  return *a_int - *b_int;
}
