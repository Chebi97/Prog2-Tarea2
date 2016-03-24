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
  bool res;
  localizador cursor = lst->inicio;
  if (!es_lista_vacia(lst)){
    res = i == cursor->dato->numero;
    while(!res && cursor->siguiente != NULL){
      cursor = siguiente(cursor, lst);
      res = i == cursor->dato->numero;
    }
  }
  return res;
}

nat longitud(const lista lst) {
  nat res = 0;
  localizador cursor = lst->inicio;
  while(cursor != NULL) {
    res++;
    cursor = siguiente(cursor, lst);
  }
  return res;
}

nat cantidad(const int i, const lista lst) {
  nat res = 0;
  localizador cursor = lst->inicio;
  while(cursor != NULL) {
    if (cursor->dato->numero == i) {
      res++;
    }
    cursor = siguiente(cursor, lst);
  }
  return res;
}

bool son_numeros_iguales(const lista l1, const lista l2) {
  localizador cursor1 = l1->inicio;
  localizador cursor2 = l2->inicio;
  while (cursor1 == cursor2) {
    cursor1 = siguiente(cursor1, l1);
    cursor2 = siguiente(cursor2, l2);
  }
  bool res = cursor1 == cursor2 == NULL;

  return res;
}

lista concatenar(const lista l1, const lista l2) {
  lista res = crear_lista();

  lista lst1 = segmento_lista(l1->inicio, l1->final, l1);
  lista lst2 = segmento_lista(l2->inicio, l2->final, l2);

  res->inicio = lst1->inicio;
  res->final = lst2->final;
  lst1->final->siguiente = lst2->inicio;
  lst2->inicio->anterior = lst1->final;

  return res;
}

lista reversa(const lista lst) {
  lista res = crear_lista();
  if (!es_vacia_lista(lst)) {
    localizador loc = lst->inicio;
    while (loc != lst->final) {
      info_t info = crear_info(numero_info(loc->dato),
                               copiar_texto(texto_info(loc->dato)));
      insertar_antes(info, inicio_lista(res), res);
      loc = siguiente(loc, lst);
    }
  }
  return res;
}

localizador primer_mayor(const localizador loc, const lista lst) {
  localizador res = loc;
  localizador cursor = lst->inicio;
  while (cursor != loc) {
    if (cursor->dato->numero > loc->dato->numero) {
      res = cursor;
    }
  }
  return res;
}

void ordenar(lista &lst) {
  localizador cursor = lst->inicio;
  while (cursor != NULL) {
    retroceder(cursor, lst);
    cursor = siguiente(cursor, lst);
  }
}

lista mezcla(const lista l1, const lista l2) {
}

lista filtrado(const int clave, const comp_t criterio, const lista lst) {
}

lista sublista(const nat menor, const nat mayor, const lista lst) {
}

void imprimir_lista(const lista lst) {
}

