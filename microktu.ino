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
					moveIleri(robotunYonu);

				}else if(!onDuvar()){
					moveIleri(robotunYonu);

				}else if(!solDuvar()){
					solaDon();
					moveIleri(robotunYonu);

				}else if(sagDuvar && solDuvar && onDuvar){
					geriyeDon();
					moveIleri(robotunYonu);
				}
			}
		}
	}

	}else if(algoritmaSecenek == 2){ // lee'den bozma algoritma
		while(!hedefBulundu){

			if(hedefBul()){
				hedefBulundu = 1;
				
			}else{
				robotunYonu = isiniTakipEt(robotunYonu);
			}
		}
	}	

}