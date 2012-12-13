/* Sensor Degerleri */
int SAG_SENSOR = 0;
int SOL_SENSOR = 0;
int ON_SENSOR  = 0;
int ALT_SENSOR = 0;

/* Sag sensorden veri oku */
void sagOku(){
	SAG_SENSOR = // deger alma islemi
	return SAG_SENSOR;
}

/* Sol sensorden veri oku */
void solOku(){
	SOL_SENSOR = // deger alma islemi
	return SOL_SENSOR;
}

/* On sensorden veri oku */
void onOku(){
	ON_SENSOR = // deger alma islemi
	return ON_SENSOR;
}

/* Alt sensorden veri oku */
void altOku(){
	ALT_SENSOR = // deger alma islemi
	return ALT_SENSOR;
}

/* Sensorden gelen degeri cm turune cevirir */
int uzaklik(deger){
	// cevirme islemi
}

/* Sag tarafta duvar tespiti. Var ise 1 doner */
int sagDuvar(){
	int deger = sagOku();
	if(uzaklik(deger) < DUVAR_SABITI ){
		return 1;
	}

}

/* Sol tarafta duvar tespiti. Var ise 1 doner */
int solDuvar(){
	int deger = solOku();
	if(uzaklik(deger) < DUVAR_SABITI ){
		return 1;
	}	

}

/* On tarafta duvar tespiti. Var ise 1 doner */
int onDuvar(){
	int deger = onOku();
	if(uzaklik(deger) < DUVAR_SABITI ){
		return 1;
	}	

}

int hedefBul(){
	int deger = altOku();
	if(deger > 0){ // @TODO: degerler stabilize edilmeli
		return 1;
	}
}