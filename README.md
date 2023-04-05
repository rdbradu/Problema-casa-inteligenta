# Problema-vot-electronic
Este luna mai din anul 2018 și ați fost angajați de statul român să dezvoltați o aplicație pentru votul electronic. Aveți o bază de date de persoane pe care aplicația o citește la pornire. Pentru fiecare persoană din baza de date se cunosc numele, prenumele, adresa de domiciliu, CNP-ul, seria și numărul de buletin.

După citirea bazei de date, de la tastatură se citește o secvență de perechi ”CNP + Nume Candidat” care reprezintă voturi ale persoanelor identificate prin CNP-ul respectiv pentru candidatul identificat prin nume. Aplicația va rezolva secvențial voturile și le va număra în timp real putând oricând să afișeze situația de la momentul curent.

Cerință Aplicația citește fișierul cu date personale ale persoanelor ce vor vota dintr-un fișier CSV (Comma Separated Values) numit „evidenta.csv” scris în următorul format (fiecare persoană pe o singură linie):

NUME PRENUME_1 PRENUME_2 PRENUME_N,ADRESA,CNP,SERIE_NR_CI Numărul de persoane nu este cunoscut la deschiderea fișierului; fișierul va fi citit până la sfârșitul său.

De la tastatură se citesc linii de forma:

CNP_votant Nume Complet Candidat sau ? sau
În funcție de primul caracter se vor realiza următoarele operații:

'+' - cineva încearcă să voteze. Se realizează următoarele verificări:

Dacă CNP-ul nu există în baza de date, se afișează un mesaj de eroare: „CNP invalid” și se consideră încercare de fraudă

Dacă CNP-ul există, dar persoana a votat deja, se afișează un alt mesaj de eroare „Vot deja inregistrat” și se consideră încercare de fraudă

Dacă CNP-ul există dar vârsta persoanei e mai mică decât 18 (se calculează diferența dintre anul și luna din CNP și anul și luna curentă) se afișează un mesaj de eroare „Persoana minora” și NU se consideră încercare de fraudă

Altfel, se înregistrează votul pentru candidatul specificat prin nume și se marchează CNP-ul votantului ca vot exprimat.

'?' - se cere statistica curentă: Se vor afișa candidații în ordinea descrescătoare a voturilor obținute (dacă există mai mulți candidați cu același număr de voturi, ordinea în care se afișează este ordinea în care au apărut în listă pentru prima oară) și numărul încercărilor de fraudă

'*' - procesul electroral se încheie, se afișează statistica similar cu output-ul pentru '?' și programul se încheie.

Afișarea statisticilor la introducerea unui caracter '?' sau '*' se face în formatul următor:

Statistici
Nume Candidat Unu: 1234 voturi (77.61%) Nume Candidat Doi: 343 voturi (21.57%) Nume Candidat N: 13 voturi (0.82%) Incercari de frauda: 2 Procentajul voturilor se va afișa cu două zecimale. Textul care nu reprezintă valori sau nume de candidați din blocul de mai sus se va afișa exact ca mai sus.
