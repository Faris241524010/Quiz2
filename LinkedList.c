/* File        : LinkedList.c */
/* Deskripsi   : ADT linked list dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Faris */

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <malloc.h>
#include "boolean.h"
#include "LinkedList.h"

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
 } ElmtList;

boolean isEmpty(address p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
boolean isEmpty(address p) {
    return p == NULL;
}


void Create_Node (address *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Create_Node(address *p) {
    *p = (address) malloc(sizeof(ElmtList));
    if (*p == NULL) {
        printf("Memory allocation failed!\n");
    }
}

void Isi_Node (address *p , infotype nilai);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
//				*p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Isi_Node(address *p, infotype nilai) {
    if (*p != NULL) {
        (*p)->info = nilai;
        (*p)->next = NULL;
    }
}

void Tampil_List (address p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
void Tampil_List(address p) {
    address temp = p;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void Ins_Awal (address *p, address PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
//             PNew (input)
void Ins_Awal(address *p, address PNew) {
    if (PNew != NULL) {
        PNew->next = *p;
        *p = PNew;
    }
}

void Ins_Akhir (address *p, address PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew;
    } else {
        address temp = *p;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = PNew;
    }
}

address Search (address p, infotype nilai);
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
address Search(address p, infotype nilai) {
    address temp = p;
    while (temp != NULL) {
        if (temp->info == nilai) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void InsertAfter (address * pBef, address PNew);
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
void InsertAfter(address *pBef, address PNew) {
    if (*pBef != NULL) {
        PNew->next = (*pBef)->next;
        (*pBef)->next = PNew;
    }
}

void Del_Awal (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
void Del_Awal(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p;
        *X = temp->info;
        *p = temp->next;
        free(temp);
    }
}

void Del_Akhir (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
void Del_Akhir(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p;
        if (temp->next == NULL) {
            *X = temp->info;
            free(temp);
            *p = NULL;
        } else {
            while (temp->next != NULL && temp->next->next != NULL) {
                temp = temp->next;
            }
            address last = temp->next;
            *X = last->info;
            temp->next = NULL;
            free(last);
        }
    }
}

void Del_After (address * pBef, infotype * X);
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/*      nilai info node yang dihapus disimpan pada X */
/* 	  dan alamat elemen setelah pBef di dealokasi */
void Del_After(address *pBef, infotype *X) {
    if (*pBef != NULL && (*pBef)->next != NULL) {
        address temp = (*pBef)->next;
        *X = temp->info;
        (*pBef)->next = temp->next;
        free(temp);
    }
}

void DeAlokasi (address * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
void DeAlokasi(address *p) {
    if (*p != NULL) {
        free(*p);
        *p = NULL;
    }
}

int NbElmt (address p);
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode
int NbElmt(address p) {
    if (p == NULL) {
        return 0;
    } else {
        return 1 + NbElmt(p->next);
    }
}

infotype Min (address p);
/* Mengirimkan nilai Info(P) yang minimum */
infotype Min(address p) {
    if (p == NULL) {
        return -1; // Misalnya -1 jika list kosong
    }
    infotype min = p->info;
    address temp = p->next;
    while (temp != NULL) {
        if (temp->info < min) {
            min = temp->info;
        }
        temp = temp->next;
    }
    return min;
}

infotype Rerata (address p);
/* Mengirimkan nilai rata-rata Info(P) */
infotype Rerata(address p) {
    int sum = 0, count = 0;
    address temp = p;
    while (temp != NULL) {
        sum += temp->info;
        count++;
        temp = temp->next;
    }
    return count == 0 ? 0 : sum / count;
}

address BalikList (address p);
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
address BalikList(address p) {
    address prev = NULL, curr = p, next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

#endif

