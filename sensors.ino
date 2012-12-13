/* Sensor Degerleri */
SAG_SENSOR = 0;
SOL_SENSOR = 0;
ON_SENSOR = 0;

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

/* Sensorden gelen degeri cm turune cevirir */
int uzaklik(deger){
	// cevirme islemi
}

/* Sag tarafta duvar tespiti. Var ise 1 doner */
int sagDuvar(){
	deger = sagOku();
	if(uzaklik(deger) < DUVAR_SABITI ){
		return 1;
	}

}

/* Sol tarafta duvar tespiti. Var ise 1 doner */
int solDuvar(){
	deger = solOku();
	if(uzaklik(deger) < DUVAR_SABITI ){
		return 1;
	}	

}

/* On tarafta duvar tespiti. Var ise 1 doner */
int onDuvar(){
	deger = onOku();
	if(uzaklik(deger) < DUVAR_SABITI ){
		return 1;
	}	

}
