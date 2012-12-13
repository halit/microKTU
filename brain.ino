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

	// Sol tarafta duvar yoksa doneceklere ekle
	if(!solDuvar){
		aciklar[2]=1;
	}

	// Sag tarafta duvar yoksa doneceklere ekle
	if(!sagDuvar){
		aciklar[1]=1;
	}

	// On tarafta duvar yoksa doneceklere ekle
	if(!onDuvar){
		aciklar[0]=1;
	}		
}

/* Robotun yonune gore siradaki hareketi belirler */
/* @TODO: if'leri else if haline getir */
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
			if(kucukler[1] && aciklar[1]){ // Sag duvar acik ve degeri kucuk ise
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}else if(kucukler[0] && aciklar[0]){ // On duvar acik ve degeri kucuk ise
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}else if(kucukler[2] && aciklar[2]){ // Sol duvar acik ve degeri kucuk ise
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}else if(!aciklar[0] && !aciklar[1] && !aciklar[2]){ // On,Sag ve Sol kapali ise geri don
				moveBati(robotunYonu);
				robotunYonu = 3;
			}else if(!aciklar[0] && aciklar[1] && aciklar[2] && !kucukler[1] && !kucukler[2]){ // On kapali, sag ve sol acik degerleri buyukse geri don
				moveBati(robotunYonu);
				robotunYonu = 3;
			// @TODO: harita guncelleme eklenebilir
			}else if(aciklar[1]){ // sag aciksa oraya don
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}else if(aciklar[0]){ // on aciksa oraya git
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}else if(aciklar[2]){ // sol aciksa oraya git
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}else{
				dur();
			}

			// @TODO: baska durumlar eklenebilir
			break;
		
		/* Robotun yonu guneye dogru ise */			
		case 1:
			// Sag duvar acik ve degeri kucuk ise
			if(kucukler[3] && aciklar[3]){
				moveBati(robotunYonu);
				robotunYonu = 3;
			}else if(kucukler[1] && aciklar[1]){ // On duvar acik ve degeri kucuk ise
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}else if(kucukler[0] && aciklar[0]){ // Sol duvar acik ve degeri kucuk ise
				moveBati(robotunYonu);
				robotunYonu = 0;
			}else if(!aciklar[0] && !aciklar[1] && !aciklar[3]){ // On,Sag ve Sol kapali ise geri don
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}else if(!aciklar[1] && aciklar[0] && aciklar[3] && !kucukler[0] && !kucukler[3]){ // On kapali, sag ve sol acik degerleri buyukse geri don
				moveKuzey(robotunYonu);
				robotunYonu = 2;			
			// @TODO: harita guncelleme yapilabilir
			}else if(aciklar[3]){ // sag aciksa oraya don
				moveBati(robotunYonu);
				robotunYonu = 3;
			}else if(aciklar[1]){ // on aciksa oraya git
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}else if(aciklar[0]){ // sol aciksa oraya git
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}else{
				dur();
			}			

			// @TODO: baska durumlar eklenebilir
			break;

		/* Robotun yonu kuzeye dogru ise */
		case 2:
			// Sag duvar acik ve degeri kucuk ise
			if(kucukler[0] && aciklar[0]){
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}else if(kucukler[2] && aciklar[2]){ // On duvar acik ve degeri kucuk ise
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}else if(kucukler[3] && aciklar[3]){ // Sol duvar acik ve degeri kucuk ise
				moveBati(robotunYonu);
				robotunYonu = 3;
			}else if(!aciklar[0] && !aciklar[2] && !aciklar[3]){ // On,Sag ve Sol kapali ise geri don
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}else if(!aciklar[2] && aciklar[0] && aciklar[3] && !kucukler[0] && !kucukler[3]){ // On kapali, sag ve sol acik degerleri buyukse geri don
				moveGuney(robotunYonu);
				robotunYonu = 1;
			// @TODO: harita guncelleme yapilabilir
			}else if(aciklar[0]){ // sag aciksa oraya don
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}else if(aciklar[2]){ // on aciksa oraya git
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}else if(aciklar[3]){ // sol aciksa oraya git
				moveBati(robotunYonu);
				robotunYonu = 3;
			}else{
				dur();
			}		

			// @TODO: baska durumlar eklenebilir
			break;
		
		/* Robotun yonu batiya dogru ise */
		case 3:
			// Sag duvar acik ve degeri kucuk ise
			if(kucukler[2] && aciklar[2]){
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}else if(kucukler[3] && aciklar[3]){ // On duvar acik ve degeri kucuk ise
				moveBati(robotunYonu);
				robotunYonu = 3;
			}else if(kucukler[1] && aciklar[1]){ // Sol duvar acik ve degeri kucuk ise
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}else if(!aciklar[1] && !aciklar[2] && !aciklar[3]){ // On,Sag ve Sol kapali ise geri don
				moveDogu(robotunYonu);
				robotunYonu = 0;
			}else if(!aciklar[3] && aciklar[1] && aciklar[2] && !kucukler[1] && !kucukler[2]){ // On kapali, sag ve sol acik degerleri buyukse geri don
				moveDogu(robotunYonu);
				robotunYonu = 0;
			// @TODO: harita guncelleme yapilabilir
			}else if(aciklar[2]){ // sag aciksa oraya don
				moveKuzey(robotunYonu);
				robotunYonu = 2;
			}else if(aciklar[3]){ // on aciksa oraya git
				moveBati(robotunYonu);
				robotunYonu = 3;
			}else if(aciklar[1]){ // sol aciksa oraya git
				moveGuney(robotunYonu);
				robotunYonu = 1;
			}else{
				dur();
			}	

			// @TODO: baska durumlar eklenebilir	
			break;
	}
}