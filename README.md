# Yabi: Yet another Brainf**k interpreter
Questo progetto didattico nasce con l'obiettivo di esplorare il funzionamento di un interpreter e di un compiler, mettendo in evidenza le differenze in termini di prestazioni

---
## Contenuti:
* [installazione](#installazione)
* [interpreter mode](#interpreter)
* [debug mode](#debug)
   * [logging](#logging)

* [compiler mode](#compiler)
   * [optimize](#optimize)
* [benchmark](#benchmark)
* [extra](#extra)
   * [info](#info)
   * [help](#help)
   * [about](#about)

*[risultati dei benchmark](#benchmark)
---

## Installazione:
linux
```
make 
```
windows
```
./compile.bat
```
L'eseguibile si troverà nella cartella `/bin`

---

## <a id=interpreter></a> Interpreter mode:

### modalità di utilizzo:
```
./yabi hello_world
```


In mancanza di flags, il programma è di default in modalità interprete. Le istruzioni in brainf**k vengono interpretate ed eseguite a runtime.
```c
switch (c)
      {
         case '>':
            ptr++;
         break;

         case '<':
            ptr--;
         break;
      
         case '+':
            (*ptr)++;
         break;

         case '-':
            (*ptr)--;
         break;

         ...
```
---
## <a id=debug></a> Debug mode:
### Modalità di utilizzo:
Aggiungere il flag `-d` oppure `--debug`
```
./yabi hello_world -d
```
```
./yabi hello_world --debug
```
In modalità debug, è possibile analizzare il funzionamento del programma istruzione per istruzione utilizzando un tracer interattivo. 
### comandi del tracer:
* ↑ freccia in su
* ↓ freccia in giù
* ← freccia a sinistra
* → freccia a destra
* esc

Premendo la freccia in giù, si passa all'istruzione sucessiva. Premendola due volte di fila l'esecuzione va in automatico finché non viene raggiunto un breakpoint (un punto esclamativo ! aggiunto all'interno del codice sorgente) o una richiesta di input.
```
./yabi echo -d

current intruction: 0    '-'    cell n. 15000   value: 255
current intruction: 1    '-'    cell n. 15000   value: 254
current intruction: 2    '-'    cell n. 15000   value: 253
SKIP
insert input:
```
```
./yabi hello_world -d

current intruction: 0    '+'    cell n. 15000   value:   1
SKIP
breakpoint
current intruction: 42   '!'    cell n. 15000   value:   0
```

Premendo la freccia in su, si ha una rappresentazione dei valori nelle cellette di memoria. con la freccia sinistra e destra è possibile muoversi avanti e indietro lungo le cellette

```
./yabi mandelbrot -d

current intruction: 0    '+'    cell n. 15000   value:   1
SKIP
breakpoint
current intruction: 90   '!'    cell n. 15025   value:   0
(cells 15020 - 15030)           0       0       0       0       0       [0]     0       0       0       0
(cells 15010 - 15020)           0       0       0       0       0       0       15      0       0       0
(cells 15000 - 15010)           0       26      0       0       65      32      10      0       0       0
(cells 14990 - 15000)           0       0       0       0       0       0       0       0       0       0
```
In caso di errore o malfunzionamento, è possibile abortire il programma premendo esc.

---
## Logging:
### Modalità di utilizzo:
```
./yabi hello_world -> logfile -d
```

Fornendo un output al programma in modalità debug, esso creerà un log file nel quale salverà tutte queste informazioni per ogni singola istruzione.


Il file si troverà nella cartella `/log`

---

## Compiler mode:
### Modalità di utilizzo:
Aggiungere il flag `-c` oppure `--compile`
```
./yabi hello_world -> output_name -c
```
```
./yabi hello_world -> output_name --compile
```
In modalità compilatore, le istruzioni in brainf**k vengono tradotte in codice C, il quale viene salvato all'interno di un file.
Qualora non venga assegnato un nome al file di output, questo verrà scelto automaticamente dal programma.
Il file si troverà nella cartella `/output`

---

## Optimize:
### Modalità di utilizzo:
Aggiungere il flag `-o` oppure `--optimize`
```
./yabi hello_world -> output_name -c -o
```
```
./yabi hello_world -> output_name --compile --optimize
```
In modalità ottimizzazione, il programma crea una rappresentazione intermedia del codice in Brainf**k, la quale viene ottimizzata per andare a creare del codice più performante

### esempio:
codice non ottimizzato:
```
int main()
{
   unsigned char cells[30000] = {0};
   unsigned char* ptr = &cells[15000];

   (*ptr)++;
   (*ptr)++;
   (*ptr)++;
   (*ptr)++;
   (*ptr)++;
   (*ptr)++;
   (*ptr)++;
   (*ptr)++;
   (*ptr)++;
   (*ptr)++;

   while (*ptr)
   {
      ptr++;
      (*ptr)++;
      (*ptr)++;
      (*ptr)++;
      ...
```
codice ottimizzato:
```
#include <stdio.h>

int main()
{
   unsigned char cells[30000] = {0};
   unsigned char* ptr = &cells[15000];

   *(ptr +=(0)) += (10);

   while (*ptr)
   {
      *(ptr +=(1)) += (7);
      *(ptr +=(1)) += (10);
      *(ptr +=(1)) += (3);
      *(ptr +=(1)) += (1);
      *(ptr +=(-4)) += (-1);
   }
}
```
---

## Benchmark:
### Modalità di utilizzo:
Aggiungere il flag `-b` oppure `--benchmark`

interpreter mode:
```
./yabi mandelbrot -b
```
compiler mode
```
./yabi --compile --benchmark mandelbrot -> output 
```
```
./yabi mandelbrot -> output -c -b -o
```

La modalità benchmark fornisce informazioni riguardo i tempi di esecuzione del programma. In modalità compiler, oltre a dichiarare il tempo impiegato dalla compilazione del programma, aggiunge del codice nel file C in output affinché anch'esso fornisca informazioni di benchmark.

---

## Extra
Una serie di funzionalità aggiuntive e molto probabilmente superflue:

---

### Info:
#### Modalità di utilizzo:
```
./yabi triangle -info

This program prints out the Sierpinski triangle
```
Questa flag fa sì che la descrizione del programma in Brainf**k all'inizio del file sia stampata a schermo. Qualora non sia presente una descrizione, stamperà un messaggio di errore.
```
./yabi hello_world_2 -info

No description found.
```

### Help:
#### Modalità di utilizzo:
```
./yabi -help
```
Questa flag stampa a video un breve riassunto di tutto ciò che c'è da sapere per riuscire ad usare questo programma.

### About:
#### Modalità di utilizzo:
```
./yabi -about
```
Questa flag stampa a video una concisa presentazione di questo progetto.

---

# <a id=benchmark> </a> Risultati dei benchmark:
## interpreter mode:
```
./yabi mandelbrot -b
```
```
[INFO] program execution took 34.281000 seconds
```
--- 
## unoptimized compiler mode:
```
./yabi mandelbrot -c -b
```
```
[INFO] compilation took 0.017000 seconds
```
```
gcc mandelbrot.c
./a
```
```
[INFO: The program took 18.979000 seconds]
```
---

## optimized compiler mode:
```
./yabi mandelbrot -c -b -o
```
```
[INFO] compilation took 0.011000 seconds
```
```
gcc mandelbrot.c
./a
```
```
[INFO: The program took 5.383000 seconds]
```