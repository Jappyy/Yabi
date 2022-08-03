# Yabi: Yet another Brainf**k interpreter
Questo progetto didattico nasce con l'obiettivo di esplorare il funzionamento di un interpreter e di un compiler, mettendo in evidenza le differenze in termini di prestazioni

---
## Contenuti:
* [installazione](#installazione)
* [interpreter mode](#interpreter)
* [debug mode](debug)
   * [logging](logging)

* [compiler mode](compiler)

* [benchmark](benchmark)
* [info](info)
* [help](help)

---

## installazione:
linux
```
make 
```
windows
```
./compile.bat
```
l'eseguibile si troverà nella cartella `/bin`

---

## <a id=interpreter></a> interpreter mode:

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
## <a id=debug></a> debug mode:
### modalità di utilizzo:
aggiungere il flag `-d` oppure `--debug`
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
