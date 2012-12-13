int robotunYonu  = 0;
int hedefBulundu = 0;
int algoritmaSecenek = 0; // 0 dalga-sag duvar, 1 sag duvar, 2 special

/* Robotun ana omurgasi */
void setup(){
	//sensorKontrol();
	//ilkHareket();
}

void loop(){
	if(algoritmaSecenek == 0){ // dalga ve sag duvar kombinasyonu

		while(!hedefBulundu){
			aciklariBul();
			kucukleriBul();

			siradakiHareket(robotunYonu);

			if(hedefBul()){
				hedefBulundu = 1;
			}
		}

	}else if(algoritmaSecenek == 1){ // sag duvar algoritmasi
		while(!hedefBulundu){
			
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

			if(hedefBul()){
				hedefBulundu = 1;
			}
		}
	}

}