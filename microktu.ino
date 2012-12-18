int robotunYonu  = 0; // Robotun bulundugu konuma gore yonu
int hedefBulundu = 0; // Hedefin bulunduguna dair degisken
int algoritmaSecenek = 0; // 0 dalga-sag duvar, 1 sag duvar, 2 special

/* Robotun ana omurgasi */
void setup(){
	//sensorKontrol();
	//ilkHareket();
}

void loop(){
	if(algoritmaSecenek == 0){ // dalga ve sag duvar kombinasyonu

		while(!hedefBulundu){
			
			if(hedefBul()){
				hedefBulundu = 1;

			}else{

				//aciklariBul();
				//kucukleriBul();

				siradakiHareket(robotunYonu);
			}
		}

	}else if(algoritmaSecenek == 1){ // sag duvar algoritmasi
		while(!hedefBulundu){

			if(hedefBul()){
				hedefBulundu = 1;
				
			}else{
			
				if(!sagDuvar()){
					sagaDon();
					moveIleri();

				}else if(!onDuvar()){
					moveIleri();

				}else if(!solDuvar()){
					solaDon();
					moveIleri();

				}else if(sagDuvar && solDuvar && onDuvar){
					geriyeDon();
					moveIleri();
				}
			}
		}
	}

	}else if(algoritmaSecenek == 2){ // special algoritma
		while(!hedefBulundu){

			if(hedefBul()){
				hedefBulundu = 1;
				
			}else{
				isiniTakipEt();
			}
		}
	}	

}