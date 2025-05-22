#include <stdio.h>
#include "crypt.h"

void xorEncrypt(const char *input, const char *output, int key) {
    FILE *in = fopen(input, "rb");
    FILE *out = fopen(output, "wb");
    if (!in || !out) {
        printf("Dosya açılamadı.\n");
        return;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF)
        fputc(ch ^ key, out);

    fclose(in);
    fclose(out);
    printf("XOR şifreleme tamamlandı.\n");
}

void xorDecrypt(const char *input, const char *output, int key) {
    xorEncrypt(input, output, key); // Aynı işlem
}

void caesarEncrypt(const char *input, const char *output, int shift) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");
    if (!in || !out) {
        printf("Dosya açılamadı.\n");
        return;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        if (ch >= 'a' && ch <= 'z')
            ch = ((ch - 'a' + shift) % 26) + 'a';
        else if (ch >= 'A' && ch <= 'Z')
            ch = ((ch - 'A' + shift) % 26) + 'A';
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
    printf("Caesar şifreleme tamamlandı.\n");
}

void caesarDecrypt(const char *input, const char *output, int shift) {
    caesarEncrypt(input, output, 26 - (shift % 26));
}
