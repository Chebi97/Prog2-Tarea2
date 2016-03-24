/*
  Módulo principal test_info.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#include "include/utils.h"
#include "include/texto.h"
#include "include/info.h"

#include <stdio.h>

#define MAX_TEXTO 100

int main() {
  texto_t texto = cadena_a_texto("-Este dato de texto-");
  info_t info = crear_info(20, texto);
  printf("El dato numerico es %d.\n", numero_info(info));
  fputs("El dato de texto es ", stdout);
  texto_t txt2 = texto_info(info);
  escribir_texto(txt2);
  escribir_nueva_linea();
  fputs("Info a texto es ", stdout);
  txt2 = info_a_texto(info);
  escribir_texto(txt2);
  escribir_nueva_linea();

  liberar_texto(txt2);
  liberar_info(info);

  printf("Ingrese info (con el formato de info_a_texto) seguido de un punto.\n "
         "Ejemplo: (10,hola mundo):\n ");
  info = leer_info(MAX_TEXTO);
  printf("El dato numerico es %d\n", numero_info(info));
  fputs("El dato de texto es ", stdout);
  escribir_texto(texto_info(info));
  escribir_nueva_linea();
  liberar_info(info);

  return 0;
}
