/*
  Módulo de implementación de 'uso_listas'.
  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"
#include "../include/texto.h"
#include "../include/info.h"
#include "../include/lista.h"
#include "../include/uso_lista.h"

#include <stddef.h>
#include <stdio.h>

bool esta_ordenada(const lista lst) {
  bool res = true;
  if (!es_vacia_lista(lst)) {
    localizador loc = inicio_lista(lst);
    while (res && es_localizador_lista(siguiente(loc, lst))) {
      localizador sig_loc = siguiente(loc, lst);
      if (numero_info(info_lista(loc, lst)) >
          numero_info(info_lista(sig_loc, lst)))
        res = false;
      else
        loc = siguiente(loc, lst);
    }
  }
  return res;
}

void retroceder(localizador loc, lista &lst) {
  localizador pto_ins = primer_mayor(loc, lst);
  mover_antes(pto_ins, loc, lst);
}

void unificar(lista &lst) {
  if (!es_vacia_lista(lst)) {
    localizador loc = inicio_lista(lst);
    // se cumplen las precondiciones de `siguiente`
    localizador sig_loc = siguiente(loc, lst);

    while (es_localizador_lista(sig_loc)) {
      if (numero_info(info_lista(loc, lst)) ==
          numero_info(info_lista(sig_loc, lst)))
        remover_de_lista(sig_loc, lst);
      else
        loc = sig_loc;
      sig_loc = siguiente(loc, lst);
    }
  }
}

void cambiar_todos(const int original, const int nuevo, lista &lst) {
  localizador loc = inicio_lista(lst);
  while (es_localizador_lista(loc)) {
    if (numero_info(info_lista(loc, lst)) == original) {
      info_t info = info_lista(loc, lst);
      info_t nueva_info = crear_info(nuevo, copiar_texto(texto_info(info)));
      cambiar_en_lista(nueva_info, loc, lst);
      // libera la info que no libera cambiar_en_lista
      liberar_info(info);
    }
    loc = siguiente(loc, lst);
  }
}


bool pertenece(const int i, const lista lst) {
  bool res = false;
  localizador cursor = inicio_lista(lst);
  if (!es_vacia_lista(lst)){
    res = i == numero_info(info_lista(cursor, lst));
    while(!res && siguiente(cursor, lst) != NULL){
      cursor = siguiente(cursor, lst);
      res = i == numero_info(info_lista(cursor, lst));
    }
  }
  return res;
}

nat longitud(const lista lst) {
  nat res = 0;
  localizador cursor = inicio_lista(lst);
  while(cursor != NULL) {
    res++;
    cursor = siguiente(cursor, lst);
  }
  return res;
}

nat cantidad(const int i, const lista lst) {
  nat res = 0;
  localizador cursor = inicio_lista(lst);
  while(cursor != NULL) {
    if (numero_info(info_lista(cursor, lst)) == i) {
      res++;
    }
    cursor = siguiente(cursor, lst);
  }
  return res;
}

bool son_numeros_iguales(const lista l1, const lista l2) {
  bool res = false;

  if (longitud(l1) == longitud(l2)) {
    localizador cursor1 = inicio_lista(l1);
    localizador cursor2 = inicio_lista(l2);
    while (numero_info(info_lista(cursor1, l1)) == numero_info(info_lista(cursor2, l2))
            && siguiente(cursor1, l1) != NULL) {
      cursor1 = siguiente(cursor1, l1);
      cursor2 = siguiente(cursor2, l2);
    }
    res = (cursor1 == NULL) && (cursor2 == NULL);
  }
  return res;
}

lista concatenar(const lista l1, const lista l2) {
  lista res = segmento_lista(inicio_lista(l1), final_lista(l1), l1);
  lista lst2 = segmento_lista(inicio_lista(l2), final_lista(l2), l2);

  insertar_segmento_despues(lst2, final_lista(res), res);

  return res;
}

lista reversa(const lista lst) {
  lista res = crear_lista();
  if (!es_vacia_lista(lst)) {
    localizador loc = inicio_lista(lst);
    while (loc != final_lista(lst)) {
      info_t info = crear_info(numero_info(info_lista(loc, lst)),
                               copiar_texto(texto_info(info_lista(loc, lst))));
      insertar_antes(info, inicio_lista(res), res);
      loc = siguiente(loc, lst);
    }
  }
  return res;
}

localizador primer_mayor(const localizador loc, const lista lst) {
  localizador res = loc;
  localizador cursor = inicio_lista(lst);
  bool encontrado = false;
  while (numero_info(info_lista(cursor, lst)) != numero_info(info_lista(loc, lst))
         && !encontrado) {
    if (numero_info(info_lista(cursor, lst)) > numero_info(info_lista(loc, lst))) {
      res = cursor;
      encontrado = true;
    }
    cursor = siguiente(cursor, lst);
  }
  return res;
}

void ordenar(lista &lst) {
  localizador cursor = inicio_lista(lst);
  while (cursor != NULL) {
    retroceder(cursor, lst);
    cursor = siguiente(cursor, lst);
  }
}

lista mezcla(const lista l1, const lista l2) {
  localizador cursor = inicio_lista(l2);
  lista res = concatenar(l1, l2);
  while (cursor != NULL) {
    retroceder(cursor, res);
    cursor = siguiente(cursor, res);
  }
  return res;
}

lista filtrado(const int clave, const comp_t criterio, const lista lst) {
  lista res = crear_lista();
  localizador cursor = inicio_lista(lst);
  localizador destino = inicio_lista(res);
  switch (criterio) {
    case (menor): {
      while (cursor != NULL) {
        if (numero_info(info_lista(cursor, lst)) < clave) {
          insertar_despues(info_lista(cursor, lst), destino, res);
          destino = siguiente(destino, res);
        }
        cursor = siguiente(cursor, res);
      }
      break;
    }
    case (igual): {
      while (cursor != NULL) {
        if (numero_info(info_lista(cursor, lst)) == clave) {
          insertar_despues(info_lista(cursor, lst), destino, res);
          destino = siguiente(destino, res);
        }
        cursor = siguiente(cursor, res);
      }
      break;
    }
    case (mayor): {
      while (cursor != NULL) {
        if (numero_info(info_lista(cursor, lst)) < clave) {
          insertar_despues(info_lista(cursor, lst), destino, res);
          destino = siguiente(destino, res);
        }
        cursor = siguiente(cursor, res);
      }
      break;
    }
  }
  return res;
}

lista sublista(const nat menor, const nat mayor, const lista lst) {

  localizador desde = inicio_lista(lst);
  bool encontrado_desde = false;

  while (!encontrado_desde) {
    nat a = numero_info(info_lista(desde, lst));
    if ( a >= menor)
      encontrado_desde = true;
    else
      desde = siguiente(desde, lst);
  }
  localizador hasta = final_lista(lst);
  bool encontrado_hasta = false;

  while (!encontrado_hasta) {
    nat b = numero_info(info_lista(hasta, lst));
    if( b <= mayor)
      encontrado_hasta = true;
    else
      hasta = siguiente(hasta, lst);
  }
  lista res = segmento_lista(desde, hasta, lst);

  return res;
}

void imprimir_lista(const lista lst) {
  localizador cursor = inicio_lista(lst);
  while (cursor != NULL) {
    escribir_texto(info_a_texto(info_lista(cursor, lst)));
    cursor = siguiente(cursor, lst);
  }
  printf("\n");
}
