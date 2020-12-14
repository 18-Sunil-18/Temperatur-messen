int TMP36 = A0; 
int sensorwert;
int temperatur = 0;
int t=500;
int piezo=5;  // Das Wort „piezo“ steht jetzt für die Zahl 5, also wird an Pin5 der Speaker angeschlossen.

void setup(){
  Serial.begin(9600);
  pinMode (piezo, OUTPUT);  // Der Pin für den Piezo-Lautsprecher wird als Ausgang definiert, da hier um zu piepsen eine Spannung benötigt wird.
}

void loop(){
  sensorwert=analogRead(TMP36); 
  temperatur= map(sensorwert, 0, 410, -50, 150);
  delay(t);
  Serial.print(temperatur);
  Serial.println(" Grad Celsius");
  if (temperatur>=30)  // Es wird eine IF-Bedingung erstellt: Wenn der Wert für die Temperatur über oder gleich 30 ist, dann ...
  {
    digitalWrite(piezo,HIGH);  // ... fange an zu piepsen.
    }
    else  // Und wenn das nicht so ist ...
    {
      digitalWrite(piezo,LOW);  // ... dann sein leise.
  }
}
