# README[DE]

Der Zweck dieses Repositories ist es, ein einfaches Beispiel für einen guten Aufbau eines Projektes mit C inclusive Testing, Changelog, Bau einer eigenen Library zu demonstrieren.

> Durch die CI/CD wird sichergestellt, dass das Projekt mit clang und gcc erfolgreich gebaut werden kann und die Tests erfolgreich durchlaufen.

## Struktur des Projektes

```
├── build
├── CHANGELOG
├── cmake
│   └── FetchCMocka.cmake
├── CMakeLists.txt
├── README.md
├── assets
│   └── places.csv
├── src
│   ├── argument-example.c
│   ├── c-intro.c
│   ├── itec-lib
│   │   ├── ...
│   │   └── ...
│   ├── runtime-test-example.c
│   └── sort-comp-main.c
└── test
```

Erklärung für die Struktur:

- `build`: alle kompilierten Executables und libraries und Test-Reports
- `src`: alle Source und Header Dateien. Unter `itec-lib` liegen die Source Dateien für die libitec.so
- `test`: alle Test-Source Dateien
- `cmake`: cMake Erweiterung (u.A. für cmocka)
- `CMakeLists.txt` ist das zentrale Konfigurationsskript für CMake
- `assets`: Dateien für Beispiel Executables
- `CHANGELOG`ist die zentrale Datei in der die erwähnenswerten Veränderungen des Projektes aufgelistet werden. Mehr Details: [Keep a Changelog](https://keepachangelog.com/en/1.1.0/)

## Compilieren und Ausführen des Projektes

Klonen des Repositories:

```bash
git clone https://github.com/hse-digital-engineering/Labor_ITEC.git
cd Labor_ITEC
```

1. Den Ordner `Labor_ITEC` in Visual Studio Code öffnen (vscode).

Das Projekt hat einen devcontainer. Wenn man den Ordner in vscode öffnet, fragt vscode, ob das Projekt im container geöffnet werden soll. 

2. Das Projekt im devcontainer öffnen. 

Der Devcontainer enthält alle relevanten Plugins für vscode. Unabhängig von den Plugins kann man auch das Projekt auf der Kommandozeile erstellen und compilieren.

3. Öffnen eines neuen Terminals in vscode und mit dem nächsten Abschnitt fortfahren.

### Auf der Kommandozeile

Erstelle einen Ordner für den Build-Prozess:

```bash
mkdir build
```

Wechseln in den build Ordner:

```bash
cd build/
```

Das Projekt konfigurieren:

```bash
cmake ../
```

Das Projekt compilieren und Libraries und Executables linken

```bash
cmake --build .
```

Resultat des Build-Prozesses: 

```bash
$ ls a-hl
drwxr-xr-x 20 vscode vscode  640 Dec  2 15:01 .
drwxr-xr-x 15 vscode vscode  480 Dec  2 14:57 ..
-rwxr-xr-x  1 vscode vscode  71K Dec  2 15:01 arg-ex
-rw-r--r--  1 vscode vscode  31K Dec  2 14:57 CMakeCache.txt
drwxr-xr-x 23 vscode vscode  736 Dec  2 15:01 CMakeFiles
-rw-r--r--  1 vscode vscode 1.8K Dec  2 14:57 cmake_install.cmake
-rwxr-xr-x  1 vscode vscode  71K Dec  2 15:01 CMockaExample
-rwxr-xr-x  1 vscode vscode  71K Dec  2 15:01 code-intro-ex
-rw-r--r--  1 vscode vscode 1.2K Dec  2 14:57 compile_commands.json
-rw-r--r--  1 vscode vscode 3.9K Dec  2 14:57 CPackConfig.cmake
-rw-r--r--  1 vscode vscode 4.2K Dec  2 14:57 CPackSourceConfig.cmake
-rw-r--r--  1 vscode vscode  927 Dec  2 14:57 CTestTestfile.cmake
drwxr-xr-x  5 vscode vscode  160 Dec  2 14:57 _deps
-rwxr-xr-x  1 vscode vscode  73K Dec  2 15:01 itec-util-test
-rwxr-xr-x  1 vscode vscode  73K Dec  2 15:01 libitec.so
-rw-r--r--  1 vscode vscode  36K Dec  2 14:57 Makefile
-rwxr-xr-x  1 vscode vscode  71K Dec  2 15:01 runtime-ex
-rwxr-xr-x  1 vscode vscode  72K Dec  2 15:01 sort_comp_with_lib-ex
-rwxr-xr-x  1 vscode vscode  73K Dec  2 15:01 sort-test
drwxr-xr-x  3 vscode vscode   96 Dec  2 15:01 Testing
```

Tests ausführen:

```bash
ctest
```

Ausgabe auf der Kommandozeile:

```bash
Test project /workspaces/test-c/build
    Start 1: CMockaExample
1/3 Test #1: CMockaExample ....................   Passed    0.01 sec
    Start 2: sort-test
2/3 Test #2: sort-test ........................   Passed    0.03 sec
    Start 3: itec-util-test
3/3 Test #3: itec-util-test ...................   Passed    0.02 sec
```


## Was ist die CMakeLists.txt

Die Datei CMakeLists.txt ist das zentrale Konfigurationsskript für CMake, ein plattformübergreifendes Build-System. Sie enthält Anweisungen, die CMake mitteilen, wie ein Softwareprojekt zu konfigurieren, zu kompilieren und zu installieren ist. Typische Inhalte einer CMakeLists.txt sind:

-	Projektname und -version: Definition des Projektnamens und optional der Versionsnummer.
-	Mindestversion von CMake: Angabe der minimal erforderlichen CMake-Version für das Projekt.
-	Quell- und Header-Dateien: Auflistung der Dateien, die kompiliert werden sollen.
-	Abhängigkeiten: Spezifikation externer Bibliotheken oder Pakete, die für den Build erforderlich sind.
-	Build-Optionen: Festlegung von Compiler-Optionen, Build-Typen (z. B. Debug oder Release) und anderen Konfigurationsparametern.
-	Zieldefinitionen: Erstellung von Zielen wie ausführbaren Dateien oder Bibliotheken und deren Eigenschaften.

CMake verarbeitet die CMakeLists.txt, um plattformspezifische Build-Systeme zu generieren, wie Makefiles oder Projektdateien für IDEs. Dies ermöglicht eine flexible und konsistente Build-Umgebung über verschiedene Plattformen hinweg.


## cmake auf der Kommandozeile aufrufen

Build Ordner anlegen und in diesen wechslen
```bash
vscode ➜ /workspaces/test-c $ mkdir build
vscode ➜ /workspaces/test-c $ cd build
```

cmake ausführen, um die Konfigurationen zum Erstellen der Executables zu erzeugen.

```bash
vscode ➜ /workspaces/test-c/build $ cmake ../
Re-run cmake no build system arguments
-- The C compiler identification is GNU 12.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /workspaces/test-c/build
```

Schritte um sich anzeigen zu lassen was im Hintergrund passiert:

1. Alle c-Dateien werden compiliert zu .o-Dateien
2. Die o-Dateien werden zum Executable gelinkt

Setzen der Environment Variable `VERBOSE`, damit die Compiler und Linker aufrufe sichtbar werden:
```bash
vscode ➜ /workspaces/test-c/build $ export VERBOSE=1

```

Build der Libraries und Executables ausführen:

```bash
vscode ➜ /workspaces/test-c/build $ cmake --build .
```

Exemplarische Ausgabe:

```bash
[1/3] /usr/bin/aarch64-linux-gnu-gcc   -g -MD -MT CMakeFiles/sort_comp.dir/src/sort-comp-main.c.o -MF CMakeFiles/sort_comp.dir/src/sort-comp-main.c.o.d -o CMakeFiles/sort_comp.dir/src/sort-comp-main.c.o -c /workspaces/test-c/src/sort-comp-main.c
[2/3] /usr/bin/aarch64-linux-gnu-gcc   -g -MD -MT CMakeFiles/sort_comp.dir/src/sort-comp/sort-comp.c.o -MF CMakeFiles/sort_comp.dir/src/sort-comp/sort-comp.c.o.d -o CMakeFiles/sort_comp.dir/src/sort-comp/sort-comp.c.o -c /workspaces/test-c/src/sort-comp/sort-comp.c
[3/3] : && /usr/bin/aarch64-linux-gnu-gcc -g  CMakeFiles/sort_comp.dir/src/sort-comp/sort-comp.c.o CMakeFiles/sort_comp.dir/src/sort-comp-main.c.o -o sort_comp   && :
```

## Beispiel Unit Test mit cmocka

```c 
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

static void test(void **state)
{
    assert_int_equal(2, 2);
}

int main()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
```


## Trouble Shooting

Wenn der Fehler "Undefined Reference to..." auftritt, dann ist die Implementierung in der Library nicht vorhanden.

z.B.: Folgender Fehler:

```bash
[build] /workspaces/test-c/src/sort-comp-main.c:17: undefined reference to `mergeSort'
[build] collect2: error: ld returned 1 exit status
```

in der CMakeLists.txt fehlt die Datei mit der Implementierung von der Methode `mergeSort`.

```bash

add_library(itec-sort SHARED 
    ./src/sort-comp/sort-comp.c
    ./src/sort-comp/quicksort.c
    #hier fehlt mergesort.c
    )

```

