# Temperatur-messen
Aufgabe: Mit den Temperatursensor TMP36 soll die Temperatur ausgelesen und mit dem serial-monitor angezeigt werden.

Material: Arduino / Breadboard / Kabel / Temperatursensor TMP36 / Externe Stromversorgung

Der Sensor hat drei Anschlüsse. Beim Blick auf die flache Seite des Sensors: links 5V, rechts GND und in der Mitte der Pin für das Temperatursignal. Auf diesem Pin gibt der Sensor eine Spannung zwischen 0 und 2,0 Volt aus. Wobei 0V -50°C entsprechen und der Wert 2,0V entspricht 150°C. Laut Hersteller ist der Sensor zwischen -40°C und +125°C einigermaßen genau (±2°C). Die Spannung dieses Pins muss vom Mikrocontroller-Board ausgelesen und in einen Temperaturwert umgerechnet werden.

– ACHTUNG: Wenn der Sensor falsch angeschlossen wird, brennt er durch!

– Bei dem Aufbau sollte nach Möglichkeit eine externe Stromversorgung verwendet werden, da dies die Sensorgenauigkeit wesentlich verbessert (9V Netzteil oder 9V-Batterie).

Für diesen Sketch wird der „map“ Befehl benötigt. Dieser Befehl befindet sich in der Zeile: „temperatur= map(analogRead(TMP36), 0, 410, -50, 150);“

Anhand der allgemeinen Schreibweise „map ( a, b, c, d, e)“ lässt sich die Funktion besser beschreiben. Ein Wert „a“ (beispielsweise ein Messwert) wird in einem bestimmten Zahlenbereich zwischen den zwei Werten (b) und (c) erwartet. Der „map“ Befehl wandelt dann den Wert „a“ in einen anderen Wert um, der dem Zahlenbereich zwischen „d“ und „e“ entspricht.

In unserem Sketch passiert dabei folgendes:

Der Temperatursensor TMP36 gibt an dem mittleren Pin den Messwert für die Temperatur in Form einer Spannung zwischen 0V und 2V aus. Dieser Spannungsbereich entspricht dem messbaren Temperaturbereich von -50°C bis +150°C. Am analogen Eingangspin des Arduino Mikrocontrollerboards wird dieser Spannungsbereich mit Hilfe des Befehls „analogRead(TMP36)“ als Zahlenwert zwischen 0 und 410 erkannt. Dieser Wert des Temperatursensors wird zunächst ausgelesen und unter der Variablen „sensorwert“ gespeichert.

Der „map“ Befehl wird nun verwendet um diesen Zahlenwert zwischen 0 und 410 wieder in einen Temperaturwert zwischen -50°C und +150°C umzuwandeln.

temperatur = map(sensorwert, 0, 410, -50, 150);

temperatur = map (a , b , c , d , e)

a= umzuwandelnde Zahl

b= minimum Messbereich

c= maximum Messbereich

d= minimum Ausgabewert

e= maximum Ausgabewert

Nach der Umwandlung des analogen Messwertes in einen Temperaturwert, wird dieser mit dem Befehl „Serial.print(temperatur);“ an den seriellen Monitor gesendet und kann dann am PC abgelesen werden.


Weitere Infos unter: https://funduino.de/
