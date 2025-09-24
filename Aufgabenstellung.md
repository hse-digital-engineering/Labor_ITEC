# Laboraufgabe

Es soll eine Höhenmesser entwicklet werden, der ein Höhenprofil aufnehmen kann. Dazu wird in diesem Labor die Informatik-Komponente entwickelt.

Für die Entwicklung ist schon eine Hardware vrohanden. Diese bietet verschiedene Grundfunktionen an, die anhand der Aufgaben erweitert werden sollen.

## Beschreibung Hardware:

Die Blackbox ist ein Gehäuse in dem ein µ Controller Signale von einem Ultraschall Sensor (US-Sensor) erfasst diese verarbeitet und über die USB Schnittstelle ausgibt.
Die gesendeten Daten sind im INT Format und werden mit einer Frequenz von 1Hz ausgegeben
Die Spannungsversorgung erfolgt auch über den USB Anschluss (5V/0,500mA).

TODO: Beschreibung der Ansteuerung (Win und Linux)

'''
 Windows System 
// cp++ Programmzum auslesen eines USP Port's 
#include <windows.h>
#include <iostream>
#include <stdlib.h>

int main() {
    HANDLE hSerial;
    LPCSTR portName = "\\\\.\\COMX"; // Ersetze COMX durch deinen Port (z. B. COM1, COM4)

    hSerial = CreateFile(portName,
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);
........

    dcbSerialParams.BaudRate = CBR_115200;   
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
.........
}

LinuxSystem 


// usb: USB0 Baud; Rate  115200

// mit "cat /dev/ttyUSB0" kan der Port Testweise gelesen werden.

#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>

int main() {
    const char* port = "/dev/ttyUSB0";  // Port Nr.
    int serial_port = open(port, O_RDWR);

   .........
}


'''


## Rahmenbedinung

- Es muss in C programmiert werden.

## Abnahme

- Die Laboraufgaben werden einzeln abgenommen.
- Der Code wie auch die erzeugten Visualisierungen müssen erklärt werden.
- Der Code muss sauber mit Methoden, structs und unterschiedlichen .h und .c Dateien strukturiert sein. (vgl. Vorlesungsprojekt)

## Aufgaben

### 1. Plausbilität der eingelesen Werte

Ziel: 

- Ziel ist es ein C Programm zu entwicklen, das den Sensorwert aus der Blackbox auf Tastendruck ausliest und in eine csv-Datei speichert. 
- Das Programm soll einen Kalibrierungsmodus haben. 
- In diesem Modus soll der reale Abstandswert auf der Kommandozeile eingegeben werden und mit Enter bestätigt werden. Der reale Abstandswert soll ebenfalls in der csv-Datei gespeiochert werden.
- Der Modus kann über die CLI ausgewählt werden (Einzelmessung, Kalibirierung)
- Anhand der händisch erstellten Tabelle eine Look-Up Tabelle programieren, die als Input die aufgenommene csv-Datei hat. So ist es möglich durch den Tausch der csv-Datei einen anderen Wertebereich festzulegen.
- Zwischen den Datenpunkten aus der Look-Up Tabelle soll linear interpoliert werden, um aus dem Sensorwert den korrekten Abstand zu berechnen.
- Die Visualisierung der Soll-Ist-Abweichung soll in Excel durch den Import der csv-Datei erfolgen.

TODO: überarbeien
Breakdown Kalibrieren:

   - US-Sensor in einer festen Position zu einem Objekt abstellen
   - Mit einem Lineal den Abstand Sensor Objekt messen
   - Eingelesenen Wert konvertieren und den Wert als Meter anzeigen (Faktor!)
   - Auf einem Blatt Papier eine Tabelle für 20 Abstands Messungen erstellen.
   - 20 Messungen Anfang =0m, Schrittweite = 0,002 m  durchführen und Werte in Tabelle eintragen
   - Plot mit Soll und Ist Wert programieren und graphisch ausgeben.
   - Anhand der händisch erstellten Tabelle eine Look-Up Tabelle programieren.
   - Look Up Tabelle interpolieren (lineare Interpolation , 5 Zwischenpunkte)
   - Durch Messungen die Plausbilität überprüfen (3-5 Messungen)
   - Die Ergebnisse in einer Excel Tabelle "Messung Nr. 1" speichern


### 2. Automatisch messen

   - für ca. 10 Sekunden eine/n Messung/Bewegungsablauf starten
   - Zeitstempel der erfassten Werte und die Werte in einer .csv Tabelle "Messung Nr. 2" speichern
   - Visualisieren der Höhenkarte anhand der Zeitstempel
   - Ist die Zeit zwischen zwei Zeitstempeln immer gleich?
   - Wenn nein die max und min sowie auch die durchnits Abtast Zeit berechnen.
   - Im Windows mehrere Task's starten (youtube Video, Maus bewegen usw. ) und gleiche Mesusung noch mal durchführen.
   - Wie verändern sich jetzt die Werte der Zeitstempel? Speichern Sie die Daten in einer neiuen in einer .csv Tabelle
     "Messung Nr. 3"


### 3. Daten Filtern

   - Filter Sie die eingelesenen Werte.
   - Programieren Sie ein Mittelwert Filter über 3 Werte  z.B. u(m)=(SUMME( y(m-1):y(m+1))/3
   - Ploten Sie beide Werte Reihen in einem Diagramm und die dazugehörige Differenz zwichen den beiden Wertereihen
     in einem neuem Diagramm

### 4. Fun: Make it a game

TODO:

- ASCII Art level durch höhenkarte
- U-Boot mit W - up, S - down gesteuert
- von links nach rechts fährt das Uboot automatisch
- Bei kollisiotn mit der Höhe ...

  - Geben Sie über die Lautsprechen des PC's ein Sound aus abhängig vom gemessenen Abstand
  - 20 cm = 1kHz  1cm = 50Hz
  - Das C Programm gibt eine Höhenkarte als Bild aus.
  - Das C Programm gibt auf der Kommandozeile interaktive die Höhenkarte aus (ascii-art, ascii-style)
  - 
