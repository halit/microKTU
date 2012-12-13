/* (0->Dogu) (3->Bati) (2->Kuzey) (1->Guney) */
int robotunYonu = 0; // robotun o anki yonu
int simdikiKonumDegeri = 14; // bulundugu konumun degeri
int simdikiKoordinat = {0,0};
int harita[7][7]; // harita

/* Pointer ile kucukler degeri esitleniyor 
   @ FIX: Calismayabilir.Kontrol et.
*/
int kucukler[3];
kucukleriBul(&kucukler);

int aciklar[3];
aciklariBul(&aciklar);
