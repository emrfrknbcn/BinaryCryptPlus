#ifndef CRYPT_H
#define CRYPT_H

void xorEncrypt(const char *input, const char *output, int key);
void xorDecrypt(const char *input, const char *output, int key);
void caesarEncrypt(const char *input, const char *output, int shift);
void caesarDecrypt(const char *input, const char *output, int shift);

#endif
