#include <stdio.h>
#include <stdlib.h>

#include "cifra.h"
#include "decifra_string.h"
#include "decifra_chars.h"

#define N_TEXTS 2
int main()
{
  Cifra *cifras = (Cifra *)malloc(sizeof(Cifra) * N_TEXTS);
  short texto_cifrado1[] = {12105, 2136, 7692, 8009, 23405, 10621, 14460};
  short texto_cifrado2[] = {15956, 6721, 7692, 8009, 23405, 10621, 14460};
  cifras[0].texto_cifrado = texto_cifrado1;
  cifras[1].texto_cifrado = texto_cifrado2;

  const short key = 31532;

  for (int i = 0; i < N_TEXTS; i++)
  {
    cifras[i].tamanho_cifrado = 7;
    cifras[i].texto_original = (char *)malloc(sizeof(char) * cifras[i].tamanho_cifrado * 2 + 1); // +1 for \0
    decifra_string(&cifras[i], key);
  }

  for (int i = 0; i < N_TEXTS; i++)
    printf("cifras[%d].texto_original = %s\n", i, cifras[i].texto_original);

  // cleanup
  for (int i = 0; i < N_TEXTS; i++)
    free(cifras[i].texto_original);

  free(cifras);

  return 0;
}
