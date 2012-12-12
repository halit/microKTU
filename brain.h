#include "variables.h"
#include "sensors.h"
#include "movement.h"

/* Hareket edilebilecek kucuk degerleri dondurur 
   @FIX: pointer calismayabilir
*/
void kucukleriBul(int *kucukler){
	int kucukler[3] = {0,0,0,0}; // Donecek degerler tanimlanir
	int x = simdikiKoordinat[0]; // x koordinati degeri alinir
	int y = simdikiKoordinat[1]; // y kooridnati degeri alinir

	// Dogu degeri kucukse donecek degerlere eklenir
	if(simdikiKonumDegeri > harita[x+1][y]){
		kucukler[0] = 1;
	}

	// Kuzey degeri kucukse donecek degerlere eklenir
	if(simdikiKonumDegeri > harita[x][y+1]){
		kucukler[2] = 1;
	}

	// Guney degeri kucukse donecek degerlere eklenir
	if(simdikiKonumDegeri > harita[x][y-1]){
		kucukler[1] = 1;
	}

	// Bati degeri kucukse donecek degerlere eklenir
	if(simdikiKonumDegeri > harita[x-1][y]){
		kucukler[3] = 1;
	}		

}

/* Duvarlarin olmadigi yonleri bulur.
   Donen deger 1 ise duvar yoktur.
   [0]=sag, [1]=sol, [2]=on, [3]=arka
*/
void aciklariBul(int *aciklar){
	int aciklar[3] = {0,0,0,1}; // Donecek degerler tanimlanir

	if(!solDuvar){
		aciklar[1]=1;
	}

	if(!sagDuvar){
		aciklar[0]=1;
	}

	if(!onDuvar){
		aciklar[2]=1;
	}		
}

void siradakiHareket(){

}