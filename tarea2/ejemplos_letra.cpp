/*
  Módulo principal ejemplos_letra.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#include "include/utils.h"
#include "include/texto.h"
#include "include/info.h"
#include "include/lista.h"
#include "include/uso_lista.h"

#include <stddef.h>
#include <stdio.h>

int main() {
  lista lst, lst2, sgm;
  info_t info;
  localizador loc, loc2;

  // insertar-antes
  printf("insertar-antes. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();

  info = crear_info(3, cadena_a_texto("t"));
  loc = inicio_lista(lst);
  insertar_antes(info, loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(8, cadena_a_texto("o"));
  insertar_despues(info, final_lista(lst), lst);

  info = crear_info(3, cadena_a_texto("t"));
  loc = inicio_lista(lst);
  insertar_antes(info, loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // tercer ejemplo
  printf("3:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(8, cadena_a_texto("o"));
  insertar_despues(info, final_lista(lst), lst);

  info = crear_info(3, cadena_a_texto("t"));
  loc = anterior(final_lista(lst), lst);
  insertar_antes(info, loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // remover_de_lista
  printf("remover_de_lista. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();

  loc = inicio_lista(lst);
  remover_de_lista(loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(8, cadena_a_texto("o"));
  insertar_despues(info, final_lista(lst), lst);

  loc = inicio_lista(lst);
  remover_de_lista(loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // tercer ejemplo
  printf("3:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(8, cadena_a_texto("o"));
  insertar_despues(info, final_lista(lst), lst);

  loc = final_lista(lst);
  remover_de_lista(loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // cuarto ejemplo
  printf("4:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(8, cadena_a_texto("o"));
  insertar_despues(info, final_lista(lst), lst);

  loc = anterior(final_lista(lst), lst);
  remover_de_lista(loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // intercambiar
  printf("intercambiar. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  loc = siguiente(inicio_lista(lst), lst);
  loc2 = anterior(final_lista(lst), lst);
  intercambiar(loc, loc2, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // siguiente_clave
  printf("siguiente_clave. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();
  loc = inicio_lista(lst);
  loc = siguiente_clave(8, loc, lst);
  if (es_localizador_lista(loc)) {
    texto_t t = info_a_texto(info_lista(loc, lst));
    escribir_texto(t);
    liberar_texto(t);
  }
  escribir_nueva_linea();
  liberar_lista(lst);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(4, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst), lst);

  loc = siguiente(inicio_lista(lst), lst);
  loc = siguiente_clave(3, loc, lst);
  if (es_localizador_lista(loc)) {
    texto_t t = info_a_texto(info_lista(loc, lst));
    escribir_texto(t);
    liberar_texto(t);
  }
  escribir_nueva_linea();
  liberar_lista(lst);

  // tercer ejemplo
  printf("3:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(4, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(11, cadena_a_texto("o"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);

  loc = siguiente(inicio_lista(lst), lst);
  loc = siguiente_clave(11, loc, lst);
  if (es_localizador_lista(loc)) {
    texto_t t = info_a_texto(info_lista(loc, lst));
    escribir_texto(t);
    liberar_texto(t);
  }
  escribir_nueva_linea();
  liberar_lista(lst);

  // separar_segmento
  printf("separar_segmento. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  loc = inicio_lista(lst);
  loc2 = anterior(final_lista(lst), lst);
  sgm = separar_segmento(loc, loc2, lst);

  imprimir_lista(sgm);
  imprimir_lista(lst);
  liberar_lista(lst);
  liberar_lista(sgm);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  loc = siguiente(siguiente(inicio_lista(lst), lst), lst);
  loc2 = final_lista(lst);
  sgm = separar_segmento(loc, loc2, lst);

  imprimir_lista(sgm);
  imprimir_lista(lst);
  liberar_lista(lst);
  liberar_lista(sgm);

  // tercer ejemplo
  printf("3:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  loc = siguiente(inicio_lista(lst), lst);
  loc2 = anterior(final_lista(lst), lst);
  sgm = separar_segmento(loc, loc2, lst);

  imprimir_lista(sgm);
  imprimir_lista(lst);
  liberar_lista(lst);
  liberar_lista(sgm);

  // reversa
  printf("reversa. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();

  sgm = reversa(lst);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(sgm);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  sgm = reversa(lst);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(sgm);

  // retroceder
  printf("retroceder. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  loc = inicio_lista(lst);
  retroceder(loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  loc = final_lista(lst);
  retroceder(loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // tercer ejemplo
  printf("3:");
  lst = crear_lista();
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(9, cadena_a_texto("n"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  loc = anterior(final_lista(lst), lst);
  retroceder(loc, lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // unificar
  printf("unificar. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  unificar(lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("u"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("t"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(5, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(6, cadena_a_texto("s"));
  insertar_despues(info, final_lista(lst), lst);

  unificar(lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // tercer ejemplo
  printf("3:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("e"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(1, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(1, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(1, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(1, cadena_a_texto("a"));
  insertar_despues(info, final_lista(lst), lst);

  unificar(lst);

  imprimir_lista(lst);
  liberar_lista(lst);

  // mezcla
  printf("mezcla. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();
  lst2 = crear_lista();

  sgm = mezcla(lst, lst2);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(lst2);
  liberar_lista(sgm);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  lst2 = crear_lista();
  info = crear_info(1, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst2), lst2);
  info = crear_info(2, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst2), lst2);
  info = crear_info(7, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst2), lst2);

  sgm = mezcla(lst, lst2);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(lst2);
  liberar_lista(sgm);

  // tercer ejemplo
  printf("3:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("a"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("j"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("r"));
  insertar_despues(info, final_lista(lst), lst);
  lst2 = crear_lista();
  info = crear_info(1, cadena_a_texto("d"));
  insertar_despues(info, final_lista(lst2), lst2);
  info = crear_info(2, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst2), lst2);
  info = crear_info(7, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst2), lst2);

  sgm = mezcla(lst, lst2);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(lst2);
  liberar_lista(sgm);

  // filtrado
  printf("filtrado. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();
  info = crear_info(7, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(1, cadena_a_texto("a"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst), lst);

  sgm = filtrado(2, menor, lst);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(sgm);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(7, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(1, cadena_a_texto("a"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst), lst);

  sgm = filtrado(8, igual, lst);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(sgm);

  // tercer ejemplo
  printf("3:");
  lst = crear_lista();
  info = crear_info(7, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(1, cadena_a_texto("a"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst), lst);

  sgm = filtrado(1, mayor, lst);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(sgm);

  // sublista
  printf("sublista. \n");
  // primer ejemplo
  printf("1:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("a"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(7, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);

  sgm = sublista(1, 2, lst);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(sgm);

  // segundo ejemplo
  printf("2:");
  lst = crear_lista();
  info = crear_info(1, cadena_a_texto("a"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(2, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("a"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(3, cadena_a_texto("b"));
  insertar_despues(info, final_lista(lst), lst);
  info = crear_info(7, cadena_a_texto("c"));
  insertar_despues(info, final_lista(lst), lst);

  sgm = sublista(3, 7, lst);

  imprimir_lista(sgm);
  liberar_lista(lst);
  liberar_lista(sgm);

  return 0;
}
