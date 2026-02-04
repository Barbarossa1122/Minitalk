*This project has been created as part of the 42 curriculum by <fionni>.*

**Description**
Minitalk e un progetto della 42 che ha come obiettivo la comunicazione tra due processi
tramite segnali UNIX (`SIGUSR1` e `SIGUSR2`). Il client codifica un messaggio in bit e li
invia al server usando i segnali; il server ricostruisce i caratteri e li stampa.
Questo progetto permette di comprendere segnali, sincronizzazione base e comunicazione
inter-processo in C.

**Instructions**
Compilazione:
```bash
make
```

Esecuzione:
1. Avvia il server e annota il PID stampato.
```bash
./server
```
2. Invia un messaggio dal client usando il PID del server.
```bash
./client <PID> "Ciao Minitalk"
```

Pulizia:
```bash
make fclean
```

**Resources**
- `man 2 signal`, `man 2 kill`, `man 7 signal`
- Documentazione GNU C Library su segnali e gestione dei processi
- Tutorial su IPC e segnali UNIX (overview generale)

Uso dell'AI:
- Supporto alla stesura del README e alla formulazione delle istruzioni di compilazione
  ed esecuzione.
