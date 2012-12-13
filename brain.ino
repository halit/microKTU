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
void siradakiHareket(int robotunYonu){
	
	/* Pointer ile kucukler dizisi esitleniyor 
	   @ FIX: Calismayabilir.Kontrol et.
	*/
	int kucukler[3];
	kucukleriBul(&kucukler);

	int aciklar[3];
	aciklariBul(&aciklar);
		
	switch(robotunYonu){

		/* Robotun yonu doguya dogru ise */
		case 0:
			// Sag duvar acik ve degeri kucuk ise
			if(kucukler[1] && aciklar[1]){
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}

			// On duvar acik ve degeri kucuk ise
			if(kucukler[0] && aciklar[0]){
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}

			// Sol duvar acik ve degeri kucuk ise
			if(kucukler[2] && aciklar[2]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}
			
			// On,Sag ve Sol kapali ise geri don
			if(!aciklar[0] && !aciklar[1] && !aciklar[2]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}	

			// On kapali, sag ve sol acik degerleri buyukse geri don
			if(!aciklar[0] && aciklar[1] && aciklar[2] && !kucukler[1] && !kucukler[2]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}

			// @TODO: harita guncelleme yapilabilir

			// sag aciksa oraya don
			if(aciklar[1]){
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}

			// on aciksa oraya git
			if(aciklar[0]){
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}

			// sol aciksa oraya git
			if(aciklar[2]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}

			// @TODO: baska durumlar eklenebilir

			break;
		
		/* Robotun yonu guneye dogru ise */			
		case 1:
			// Sag duvar acik ve degeri kucuk ise
			if(kucukler[3] && aciklar[3]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}

			// On duvar acik ve degeri kucuk ise
			if(kucukler[1] && aciklar[1]){
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}

			// Sol duvar acik ve degeri kucuk ise
			if(kucukler[0] && aciklar[0]){
				moveBati(robotunYonu);
				robotunYonu = 0;
			}
			
			// On,Sag ve Sol kapali ise geri don
			if(!aciklar[0] && !aciklar[1] && !aciklar[3]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}	

			// On kapali, sag ve sol acik degerleri buyukse geri don
			if(!aciklar[1] && aciklar[0] && aciklar[3] && !kucukler[0] && !kucukler[3]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}

			// @TODO: harita guncelleme yapilabilir

			// sag aciksa oraya don
			if(aciklar[3]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}

			// on aciksa oraya git
			if(aciklar[1]){
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}

			// sol aciksa oraya git
			if(aciklar[0]){
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}

			// @TODO: baska durumlar eklenebilir

			break;

		/* Robotun yonu kuzeye dogru ise */
		case 2:
			// Sag duvar acik ve degeri kucuk ise
			if(kucukler[0] && aciklar[0]){
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}

			// On duvar acik ve degeri kucuk ise
			if(kucukler[2] && aciklar[2]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}

			// Sol duvar acik ve degeri kucuk ise
			if(kucukler[3] && aciklar[3]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}
			
			// On,Sag ve Sol kapali ise geri don
			if(!aciklar[0] && !aciklar[2] && !aciklar[3]){
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}	

			// On kapali, sag ve sol acik degerleri buyukse geri don
			if(!aciklar[2] && aciklar[0] && aciklar[3] && !kucukler[0] && !kucukler[3]){
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}

			// @TODO: harita guncelleme yapilabilir

			// sag aciksa oraya don
			if(aciklar[0]){
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}

			// on aciksa oraya git
			if(aciklar[2]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}

			// sol aciksa oraya git
			if(aciklar[3]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}

			// @TODO: baska durumlar eklenebilir

			break;
		
		/* Robotun yonu batiya dogru ise */
		case 3:
			// Sag duvar acik ve degeri kucuk ise
			if(kucukler[2] && aciklar[2]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}

			// On duvar acik ve degeri kucuk ise
			if(kucukler[3] && aciklar[3]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}

			// Sol duvar acik ve degeri kucuk ise
			if(kucukler[1] && aciklar[1]){
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}
			
			// On,Sag ve Sol kapali ise geri don
			if(!aciklar[1] && !aciklar[2] && !aciklar[3]){
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}	

			// On kapali, sag ve sol acik degerleri buyukse geri don
			if(!aciklar[3] && aciklar[1] && aciklar[2] && !kucukler[1] && !kucukler[2]){
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}

			// @TODO: harita guncelleme yapilabilir

			// sag aciksa oraya don
			if(aciklar[2]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}

			// on aciksa oraya git
			if(aciklar[3]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}

			// sol aciksa oraya git
			if(aciklar[1]){
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}

			// @TODO: baska durumlar eklenebilir	

			break;
	}
}