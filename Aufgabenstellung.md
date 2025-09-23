# Laboraufgabe

Erste Zeile
Beschreibung Hardware:
Die Blackbox ist ein Gehäuse in dem ein µ Controller Signale von einem Ultraschall Sensor erfasst diese verarbeitet und über die USB Schnittstelle ausgibt.
Die gesendeten Daten sind im INT Format und werden mit einer Frequenz von 1Hz ausgegeben
Die Spannungsversorgung erfolgt auch über den USB Anschluss (5V/0,500mA).

Aufgabe 1.
    Schreiben Sie ein C Programm um die Daten auszulesen und zu speichern. Dauer der Aufzeichnung 20 Sekunden ( ca 20 Werte)

Aufgabe 2
    Finden Sie das Maximum und das Minimum der Aufgezeichneter Werte. Ausgabe erfolgt im Ausgabe Fenster.

Aufgabe 3
    Finden aller Maxima und Minima
    Erstelle einen Algorithmus zum finden der Kette Maximum - Minimum
    Erstellen eines Histogramms unter Verwendung der Sortierfunktion

     (? muss noch geklärt werden was damnit genmeint ist AR? )

Aufgabe 4
Approximieren der Höhendaten mit Gauss Verteilung

# Eigene 4 Ideen für ein Labor

1. Plausbilität der eingelesen Werte
   - US Sensor in einer festen Position zu einem Objekt abstellen
   - Mit einem Lineal den Abstand Sensor Objekt messen
   - Eingelesenen Wert konvertieren und den Wert als Meter anzeigen (Faktor!)
   - Auf einem Blatt Papier eine Tabelle für 20 Abstands Messungen erstellen.
   - 20 Messungen Anfang =0m, Schrittweite =   0,002 m  durchführen und Werte in Tabelle eintragen
   - Plot mit Soll und Ist Wert programieren und graphisch ausgeben.
   - Anhand der händisch erstellten Tabelle eine Look-Up Tabelle programieren.
   - Look Up Tabelle interpolieren (lineare Interpolation , 5 Zwischenpunkte)
   - Durch Messungen die Plausbilität überprüfen (3-5 Messungen)
   - Die Ergebnisse in einer Excel Tabelle "Messung Nr. 1" speichern

2. Time -
   - für ca. 10 Sekunden eine/n Messung/Bewegungsablauf starten
   - Zeitstempel der erfassten Werte und die Werte in einer .csv Tabelle "Messung Nr. 2" speichern
   - Ist die Zeit zwischen zwei Zeitstempeln immer gleich?
   - Wenn nein die max und min sowie auch die durchnits Abtast Zeit berechnen.
   - Im Windows mehrere Task's starten (youtube Video, Maus bewegen usw. ) und gleiche Mesusung noch mal durchführen.
   - Wie verändern sich jetzt die Werte der Zeitstempel? Speichern Sie die Daten in einer neiuen in einer .csv Tabelle
     "Messung Nr. 3"

3. Daten Filtern
   - Filter Sie die eingelesenen Werte.
   - Programieren Sie ein Mittelwert Filter über 3 Werte  z.B. u(m)=(SUMME( y(m-1):y(m+1))/3
   - Ploten Sie beide Werte Reihen in einem Diagramm und die dazugehörige Differenz zwichen den beiden Wertereihen
     in einem neuem Diagramm

4. Sound
  - Geben Sie über die Lautsprechen des PC's ein Sound aus abhängig vom gemessenen Abstand
  - 20 cm = 1kHz  1cm = 50Hz
