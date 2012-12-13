int robotunYonu  = 0;
int hedefBulundu = 0;

/* Robotun ana omurgasi */
void setup(){
	//sensorKontrol();
	//ilkHareket();
}

void loop(){
	while(!hedefBulundu){

		sagDuvar();
		solDuvar();
		onDuvar();

		aciklariBul();
		kucukleriBul();

		siradakiHareket(robotunYonu);

		if(hedefBul()){
			hedefBulundu = 1;
		}
	}

}