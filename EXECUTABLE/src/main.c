/* Stevo Dobranic RA234/2018


 	 	 	 	 	 	 	 	 **Zadatak**
	Napraviti modul koji predstavlja dvostruko spregnutu list. Modul izvesti kao
	dinamicku biblioteku. Zatim napraviti funkciju koja prolazi kroz listu i
	ispisuje svaki n-ti element. Nakon ispisa, izbacuje ga iz lise i nastavlja
	dalje sa brojanjem ali u suprotnom smeru. Broj n se zadaje sa ulaza. Funkcija
	se zavrsava kada se izbace svi elementi iz liste.

								**Resenje**
	Prvo sam napravio dinamicku biblioteku u koju sam smestio "dlcl.h" i "dlcl.c."
	U "dlcl.h" se nalazi struktura koja predstavljaju element liste kao i struktura
	pokazivaca na kraj i pocetak liste, zatim deklaracije funkcija za kreiranje liste,
	dodavanje elemenata u listu, brisanje elemenata liste u zavisnosi od pozicije
	na kojoj se nalazi element koji zelimo izbrisati i glavna funkcija. Nakon toga
	sam napravio "main.c" fajl koji sam uvezao sa DLCL dinamickom bibliotekom. U
	"main.c" se nalaze pozivi funkcija koje su neophodne za izvrsavanje programa
	kao i neki testni slucajevi. Glavna funkcija prima 3 parametra prvi je lista drugi
	parametar predstavlja koji element se izbacuje, a treci je broj elemenata liste.

								**Napomenee**
	U dinamickoj blioteci prekrsio sam sledeca MISRA pravila:
	- 20.4 zbog rada sa listom koristio sam dinamicko zauzimanje i oslobadjnje memorije
	- 20.9 zbog specifikacije zadatka koja kaze da se ispisuju elementi liste koristio
		   sam "printf" funkciju koja je iz biblioteke <stdio.h>
	Priloikom ispisivanja elementa pocinje se od pocetka liste s brojem preskoka koji
	je unesen sa ulaza, s tim da pokazivac na pocetku pokazuje na nulti element liste.
	Tako da ako imamo listu npr.{1, 3, 4, 6, 9} ako unesemo da ispisujem svaki treci
	element ispisacemo 6.
	Posto nisam nasao adekvatnu primenu ovoga program trudio sam se da zauzmem sto manje
	memorije koriscenjem int_least8_t.

								**Testiranje**
	Napravio sam par testnih slucajeva koji pokrivaju sve funkcije koje sam realizovao
	kao i granice tipa podatka.Posto sam koristio oznaceni tip podatka prilikom
	prekoracenja opsega dolazi do promene znaka. Takodje sam napravio ijedan test za
	glavnu funkciju koju je bilo neophodno odraditi specifikacijom zadatka.



 */

#include <stdio.h>
#include <stdlib.h>

#include "dlcl.h"

#include <inttypes.h>

int main()
{
/*
	int_least8_t data;
	int_least8_t i;
	int_least8_t position;
	int_least8_t num_element;
*/
	DLL list;
	DoubleLinkedListCreate(&list);

/*
	printf("Unesite broj element liste (max 127): ");
	scanf("%"SCNdLEAST8, &num_element);


	for(i = 1; i < num_element+1; i++)
	{
		printf("Element %"PRIdLEAST8" -", i);
		scanf("%"SCNdLEAST8, &data);

		DoubleLinkedListInsert(&list, data);
	}


	printf("Unesite poziciju elementa koji zelite da ispisete: ");
	scanf("%"SCNdLEAST8, &position);

	DoubleLinkedListPrint(&list);

	FunctionPrintNthElement(&list, position, num_element);
*/
	printf("**********TEST GLAVNE FUNKCIJE**********\n");
	DoubleLinkedListInsert(&list,2);
	DoubleLinkedListInsert(&list,3);
	DoubleLinkedListInsert(&list,4);
	DoubleLinkedListInsert(&list,9);
	DoubleLinkedListInsert(&list,1);
	DoubleLinkedListInsert(&list,5);
	DoubleLinkedListPrint(&list);
	FunctionPrintNthElement(&list,5,6);
	DoubleLinkedListPrint(&list);

	printf("**********TEST1**********\n");
	printf("Dodavanje elementa u listu!\n");
	DoubleLinkedListInsert(&list,127);
	DoubleLinkedListInsert(&list,128);/*overflow*/
	printf("%"PRIdLEAST8"\n", list.head->data);
	printf("%"PRIdLEAST8"\n", list.tail->data);

	printf("**********TEST2**********\n");
	printf("Dodavanje vise elemenata u listu!\n");
	DoubleLinkedListInsert(&list, 2);
	DoubleLinkedListInsert(&list, 4);
	printf("%"PRIdLEAST8"\n", list.head->data);
	printf("%"PRIdLEAST8"\n", list.head->next->data);
	printf("%"PRIdLEAST8"\n", list.tail->data);

	printf("**********TEST3**********\n");
	printf("Ispis svih elemenata iz liste!\n");
	DoubleLinkedListPrint(&list);


	printf("**********TEST4**********\n");
	printf("Brisanje elemenata iz liste!\n");
	DoubleLinkedListDelete(&list, list.head);
	DoubleLinkedListPrint(&list);




	return 0;
}
