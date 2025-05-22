#include <stdio.h>
#include "crypt.h"
#include "log.h"
#include "analysis.h"

int main(void) {
    int secim, anahtar;
    char input[100], output[100];

    while (1) {
        printf("\n=== BinaryCrypt+ ===\n");
        printf("1. XOR Şifrele\n2. XOR Çöz\n3. Caesar Şifrele\n4. Caesar Çöz\n5. Frekans Analizi\n0. Çıkış\nSeçiminiz: ");
        scanf("%d", &secim);

        if (secim == 0) break;

        if (secim == 5) {
            printf("Giriş dosyası: ");
            scanf("%s", input);
            frequencyAnalysis(input);
            continue;
        }

        printf("Giriş dosyası: ");
        scanf("%s", input);
        printf("Çıkış dosyası: ");
        scanf("%s", output);
        printf("Anahtar (sayı): ");
        scanf("%d", &anahtar);

        switch (secim) {
            case 1:
                xorEncrypt(input, output, anahtar);
                logOperation("XOR_ENCRYPT", input, output, anahtar);
                break;
            case 2:
                xorDecrypt(input, output, anahtar);
                logOperation("XOR_DECRYPT", input, output, anahtar);
                break;
            case 3:
                caesarEncrypt(input, output, anahtar);
                logOperation("CAESAR_ENCRYPT", input, output, anahtar);
                break;
            case 4:
                caesarDecrypt(input, output, anahtar);
                logOperation("CAESAR_DECRYPT", input, output, anahtar);
                break;
            default:
                printf("Geçersiz seçim.\n");
        }
    }

    printf("Programdan çıkılıyor.\n");
    return 0;
}
