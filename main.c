#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
Gunakan pseudocode ADT Linked List anda menjadi program dengan mengikuti
spesifikasi pembuatan deret bilangan ganjil dengan langkah berikut:
1) masukan bilangan 7 sebagai elemen pertama {insert first}
> F.S. : elemen List = {7}
2) masukan bilangan 11 sebagai elemen kedua {insert last}
> F.S. : elemen List = {7, 11}
3) masukan bilangan 9 diantara bilangan 7 dan 11 {insert after}
> F.S. : elemen List = {7, 9, 11}
4) masukan bilangan 5 di awal list {insert first}
> F.S. : elemen List = {5, 7, 9, 11}
5) masukan bilangan 13 di akhir list {insert last}
> F.S. : elemen List = {5, 7, 9, 11, 13}
6) hapus elemen terakhir (bilangan 13) pada list {delete last}
> F.S. : elemen List = {5, 7, 9, 11}
7) hapus bilangan 7 pada list
> F.S. : elemen List = {5, 9, 11}
8) hapus elemen pertama (bilangan 5) pada list {delete first}
> F.S. : elemen List = {9, 11}
9) hapus semua elemen list deret bilangan ganjil
> F.S. : elemen List = {} */

int main(int argc, char *argv[]) {
	address list = NULL;
	address gnjl1, gnjl2, gnjl3, gnjl4, gnjl5;
	infotype nilaiTerhapus;
	address nodeTujuan;
	
	Create_Node(&gnjl1); Create_Node(&gnjl2); Create_Node(&gnjl3); Create_Node(&gnjl4); Create_Node(&gnjl5);
	Isi_Node(&gnjl1, 7); Isi_Node(&gnjl2, 11); Isi_Node(&gnjl3, 9); Isi_Node(&gnjl4, 5); Isi_Node(&gnjl5, 13);
	
	printf("masukan bilangan 7 sebagai elemen pertama {insert first} \n");
	Ins_Awal(&list, gnjl1);
	Tampil_List(list);
	
	printf("\nmasukan bilangan 11 sebagai elemen kedua {insert last} \n");
	Ins_Akhir(&list, gnjl2);
	Tampil_List(list);
	
	printf("\nmasukan bilangan 9 diantara bilangan 7 dan 11 {insert after} \n");
	nodeTujuan = Search(list, 7);
	InsertAfter(&nodeTujuan, gnjl3);
	Tampil_List (list);
	
	printf("\nmasukan bilangan 5 di awal list {insert first} \n");
	Ins_Awal(&list, gnjl4);
	Tampil_List (list);
	
	printf("\nmasukan bilangan 13 di akhir list {insert last} \n");
	Ins_Akhir(&list, gnjl5);
	Tampil_List (list);
	
	printf("\nhapus elemen terakhir (bilangan 13) pada list {delete last} \n");
	Del_Akhir(&list, &nilaiTerhapus);
	Tampil_List (list);
	
	printf("\nhapus bilangan 7 pada list \n");
	nodeTujuan = Search(list, 5);
	Del_After(&nodeTujuan, &nilaiTerhapus);
	Tampil_List (list);
	
	printf("\nhapus elemen pertama (bilangan 5) pada list {delete first} \n");
	Del_Awal(&list, &nilaiTerhapus);
	Tampil_List (list);
	
	printf("\nhapus semua elemen list deret bilangan ganjil \n");
	DeAlokasi(&list);
	Tampil_List (list);
}
