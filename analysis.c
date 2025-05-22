#include <stdio.h>
#include "analysis.h"

void frequencyAnalysis(const char *inputFile) {
    FILE *file = fopen(inputFile, "r");
    if (!file) {
        printf("Dosya açılamadı.\n");
        return;
    }

    int freq[256] = {0}, ch;

    while ((ch = fgetc(file)) != EOF)
        freq[ch]++;

    fclose(file);

    printf("\nKarakter Frekansları:\n");
    for (int i = 32; i < 127; i++) {
        if (freq[i] > 0)
            printf("'%c': %d\n", i, freq[i]);
    }
}
