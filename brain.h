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
   Donen deger 1 ise duvar yoktur yani aciktir
   [1]=sag, [2]=sol, [0]=on, [3]=arka
*/
void aciklariBul(int *aciklar){
	int aciklar[3] = {0,0,0,1}; // Donecek degerler tanimlanir

	if(!solDuvar){
		aciklar[2]=1;
	}

	if(!sagDuvar){
		aciklar[1]=1;
	}

	if(!onDuvar){
		aciklar[0]=1;
	}		
}

/* Robotun yonune gore siradaki hareketi belirler */
void siradakiHareket(){
	switch(robotunYonu){
		case 0:
			// Sag duvar acik ve degeri kucuk ise
			if(kucukler[1] && aciklar[1]){
				moveGuney();
				robotunYonu = 1;
			}

			// On duvar acik ve degeri kucuk ise
			if(kucukler[0] && aciklar[0]){
				moveDogu();
				robotunYonu = 0;
			}

			// Sol duvar acik ve degeri kucuk ise
			if(kucukler[2] && aciklar[2]){
				moveKuzey();
				robotunYonu = 2;
			}
			
			// On,Sag ve Sol kapali ise geri don
			if(!aciklar[0] && !aciklar[1] && !aciklar[2]){
				moveBati();
				robotunYonu = 3;
			}	

			// On kapali, sag ve sol acik degerleri buyukse geri don
			if(!aciklar[0] && aciklar[1] && aciklar[2] && !kucukler[1] && !kucukler[2]){
				moveBati();
				robotunYonu = 3;
			}

			// @TODO: harita guncelleme yapilabilir

			// sag aciksa oraya don
			if(aciklar[1]){
				moveGuney();
				robotunYonu = 1;
			}

			// on aciksa oraya git
			if(aciklar[0]){
				moveDogu();
				robotunYonu = 0;
			}

			// sol aciksa oraya git
			if(aciklar[2]){
				moveKuzey();
				robotunYonu = 2;
			}

			// @TODO: baska durumlar eklenebilir

			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
	}
}