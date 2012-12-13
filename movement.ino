/* Kuzeye Hareket */
void moveKuzey(robotunYonu){
	turnKuzey(robotunYonu);
	moveIleri();
}

/* Guneye Hareket */
void moveGuney(robotunYonu){
	turnGuney(robotunYonu);
	moveIleri();
}

/* Batiya Hareket */
void moveBati(robotunYonu){
	turnBati(robotunYonu);
	moveIleri();
}

/* Doguya Hareket */
void moveDogu(robotunYonu){
	turnDogu(robotunYonu);
	moveIleri();
}

/* Kuzeye Donus */
void turnKuzey(robotunYonu){
	switch(robotunYonu){
		case 0:
			solaDon(); // @TODO: stabilize olmali
			break;

		case 1:
			geriyeDon(); // @TODO: stabilize olmali
			break;

		case 2:
			break;

		case 3:
			sagaDon(); // @TODO: stabilize olmali
			break;

	}

}

/* Guneye Donus */
void turnGuney(robotunYonu){
	switch(robotunYonu){
		case 0:
			sagaDon(); // @TODO: stabilize olmali
			break;

		case 1:
			break;

		case 2:
			geriyeDon(); // @TODO: stabilize olmali
			break;

		case 3:
			solaDon(); // @TODO: stabilize olmali
			break;

	}	

}

/* Batiya Donus */
void turnBati(robotunYonu){
	switch(robotunYonu){
		case 0:
			geriyeDon(); // @TODO: stabilize olmali
			break;

		case 1:
			sagaDon(); // @TODO: stabilize olmali
			break;

		case 2:
			solaDon(); // @TODO: stabilize olmali
			break;

		case 3:
			break;

	}	

}

/* Doguya Donus */
void turnDogu(robotunYonu){
	switch(robotunYonu){
		case 0:
			break;

		case 1:
			solaDon(); // @TODO: stabilize olmali
			break;

		case 2:
			sagaDon(); // @TODO: stabilize olmali
			break;

		case 3:
			geriyeDon(); // @TODO: stabilize olmali
			break;

	}		

}

/* Saga Donus */
void sagaDon(){

}

/* Sola Donus */
void solaDon(){

}

/* Geriye Donus */
void geriyeDon(){

}

/* Ileri Gidis */
void moveIleri(){

}