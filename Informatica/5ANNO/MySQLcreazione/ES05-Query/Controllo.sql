-- Dopo aver creato la tabella biblioteca, la interrogo con le giusti query

/*
+--------------------------------------------------------------------------------------
| ES 1                                                                     
| Seleziona tutti i libri pubblicati nel 1987 
| mysql> select * from Libri where AnnoPubblicazione = 1987
|     -> ;
| +---------------+----------------+--------+-------------------+---------------------+
| | ISBN          | Titolo         | Autore | AnnoPubblicazione | QuantitaInMagazzino |
| +---------------+----------------+--------+-------------------+---------------------+
| | 9788806180825 | Norwegian Wood | 8      |              1987 |                  10 |
| +---------------+----------------+--------+-------------------+---------------------+
| 1 row in set (0.00 sec)         
+--------------------------------------------------------------------------------------                                                                
| ES 2
| Seleziona gli autori di nazionalità Americana 
| mysql> select * from Autori where Nazionalita = "Americano";
| +----+--------------------+-------------+------------+------------+
| | ID | Nome               | Nazionalita | Nascita    | Morte      |
| +----+--------------------+-------------+------------+------------+
| |  2 | Dan Brown          | Americano   | 1964-06-22 | NULL       |
| |  6 | George R.R. Martin | Americano   | 1948-09-20 | NULL       |
| |  7 | Frank Herbert      | Americano   | 1920-10-08 | 1986-02-11 |
| +----+--------------------+-------------+------------+------------+
| 3 rows in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 3
| Trova tutti i libri disponibili nel magazzino e pubblicati dopo il 2000
| mysql> select * from Libri where AnnoPubblicazione >= 2000;
| +---------------+--------------------+--------+-------------------+---------------------+
| | ISBN          | Titolo             | Autore | AnnoPubblicazione | QuantitaInMagazzino |
| +---------------+--------------------+--------+-------------------+---------------------+
| | 9780553803709 | Il Codice Da Vinci | 2      |              2003 |                   8 |
| +---------------+--------------------+--------+-------------------+---------------------+
| 1 row in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 4
| Identifica i prestiti che sono scaduti, usa la funzione curdate() per ottenere la data corrente
| mysql> select * from Prestiti where DataScadenza < curdate();
| +------------+---------------+----------+--------------+--------------+
| | IDPrestito | ISBNLibro     | IDUtente | DataPrestito | DataScadenza |
| +------------+---------------+----------+--------------+--------------+
| |          1 | 9780544003415 |        1 | 2023-03-01   | 2023-03-15   |
| |          2 | 9780553803709 |        2 | 2023-03-05   | 2023-03-20   |
| |          3 | 9780141441146 |        3 | 2023-03-10   | 2023-03-25   |
| |          4 | 9780061120085 |        2 | 2023-03-15   | 2023-03-30   |
| |          5 | 9788804645238 |        1 | 2023-03-18   | 2023-04-02   |
| |          6 | 9788806180825 |        3 | 2023-03-22   | 2023-04-06   |
| +------------+---------------+----------+--------------+--------------+
| 6 rows in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 5
| Proietta solo i titoli dei libri
| +--------------------------------------+
| | Titolo                               |
| +--------------------------------------+
| | Cronache di Narnia                   |
| | Le Cronache del Ghiaccio e del Fuoco |
| | 1984                                 |
| | Il Signore degli Anelli              |
| | Il Codice Da Vinci                   |
| | Dune                                 |
| | Norwegian Wood                       |
| | Harry Potter e la Pietra Filosofale  |
| +--------------------------------------+
| 8 rows in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 6
| Proietta i nomi completi degli utenti
| mysql> select Nome, Cognome from Utenti;
| +----------+---------+
| | Nome     | Cognome |
| +----------+---------+
| | Mario    | Rossi   |
| | Luca     | Verdi   |
| | Anna     | Bianchi |
| | Laura    | Ferrari |
| | Riccardo | Russo   |
| | Valeria  | Galli   |
| +----------+---------+
| 6 rows in set (0.00 sec)
| 
| Oppure
|
| mysql> select concat(Nome, " ", Cognome) as NomeCompleto from Utenti;
| +----------------+
| | NomeCompleto   |
| +----------------+
| | Mario Rossi    |
| | Luca Verdi     |
| | Anna Bianchi   |
| | Laura Ferrari  |
| | Riccardo Russo |
| | Valeria Galli  |
| +----------------+
| 6 rows in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 7
| Elenco delle nazionalità uniche degli autori
| mysql> select distinct Nazionalita from Autori;
| +-------------+
| | Nazionalita |
| +-------------+
| | Inglese     |
| | Americano   |
| | Irlandese   |
| | Giapponese  |
| +-------------+
| 4 rows in set (0.01 sec)
+--------------------------------------------------------------------------------------
| ES 8
| Alias per la "data di prestito" nella tabella Prestiti:
| mysql> select DataPrestito as "Data Di Prestito" from Prestiti;
| +------------------+
| | Data Di Prestito |
| +------------------+
| | 2023-03-01       |
| | 2023-03-05       |
| | 2023-03-10       |
| | 2023-03-15       |
| | 2023-03-18       |
| | 2023-03-22       |
| +------------------+
| 6 rows in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 9
| Concatena il titolo e l'anno di pubblicazione dei libri e mostra questa colonna come "dettagli libro"
| mysql> select concat(Titolo, " ", AnnoPubblicazione) as "Dettagli Libro" from Libri;
| +-------------------------------------------+
| | Dettagli Libro                            |
| +-------------------------------------------+
| | Cronache di Narnia 1950                   |
| | Le Cronache del Ghiaccio e del Fuoco 1996 |
| | 1984 1949                                 |
| | Il Signore degli Anelli 1954              |
| | Il Codice Da Vinci 2003                   |
| | Dune 1965                                 |
| | Norwegian Wood 1987                       |
| | Harry Potter e la Pietra Filosofale 1997  |
| +-------------------------------------------+
| 8 rows in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 10
| Elenco dei libri ordinati per anno di pubblicazione (decrescente)
| mysql> select * from Libri order by AnnoPubblicazione desc;
| +---------------+--------------------------------------+--------+-------------------+---------------------+
| | ISBN          | Titolo                               | Autore | AnnoPubblicazione | QuantitaInMagazzino |
| +---------------+--------------------------------------+--------+-------------------+---------------------+
| | 9780553803709 | Il Codice Da Vinci                   | 2      |              2003 |                   8 |
| | 9788807886655 | Harry Potter e la Pietra Filosofale  | 5      |              1997 |                  20 |
| | 9780061120085 | Le Cronache del Ghiaccio e del Fuoco | 6      |              1996 |                   5 |
| | 9788806180825 | Norwegian Wood                       | 8      |              1987 |                  10 |
| | 9788804645238 | Dune                                 | 7      |              1965 |                   7 |
| | 9780544003415 | Il Signore degli Anelli              | 1      |              1954 |                  10 |
| | 9780061120084 | Cronache di Narnia                   | 4      |              1950 |                  15 |
| | 9780141441146 | 1984                                 | 3      |              1949 |                  12 |
| +---------------+--------------------------------------+--------+-------------------+---------------------+
| 8 rows in set (0.01 sec)
+--------------------------------------------------------------------------------------
| ES 11
| Elenco dei libri il cui titolo inizia con "Il"
| mysql> select * from Libri where Titolo like "Il%";
| +---------------+-------------------------+--------+-------------------+---------------------+
| | ISBN          | Titolo                  | Autore | AnnoPubblicazione | QuantitaInMagazzino |
| +---------------+-------------------------+--------+-------------------+---------------------+
| | 9780544003415 | Il Signore degli Anelli | 1      |              1954 |                  10 |
| | 9780553803709 | Il Codice Da Vinci      | 2      |              2003 |                   8 |
| +---------------+-------------------------+--------+-------------------+---------------------+
| 2 rows in set (0.01 sec)
|
+--------------------------------------------------------------------------------------
| ES 12
| Trova i libri il cui titolo contiene la parola 'Harry'.
| mysql> select * from Libri where Titolo like "%Harry%";
| +---------------+-------------------------------------+--------+-------------------+---------------------+
| | ISBN          | Titolo                              | Autore | AnnoPubblicazione | QuantitaInMagazzino |
| +---------------+-------------------------------------+--------+-------------------+---------------------+
| | 9788807886655 | Harry Potter e la Pietra Filosofale | 5      |              1997 |                  20 |
| +---------------+-------------------------------------+--------+-------------------+---------------------+
| 1 row in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 13
| Autori con un nome che contiene la lettera "a":
| mysql> select * from Autori where Nome like "%a%" or "%A%";
| +----+--------------------+-------------+------------+------------+
| | ID | Nome               | Nazionalita | Nascita    | Morte      |
| +----+--------------------+-------------+------------+------------+
| |  2 | Dan Brown          | Americano   | 1964-06-22 | NULL       |
| |  6 | George R.R. Martin | Americano   | 1948-09-20 | NULL       |
| |  7 | Frank Herbert      | Americano   | 1920-10-08 | 1986-02-11 |
| |  8 | Haruki Murakami    | Giapponese  | 1949-01-12 | NULL       |
| +----+--------------------+-------------+------------+------------+
| 4 rows in set, 1 warning (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 14
| Primi 5 libri ordinati per titolo
| mysql> select * from Libri order by Titolo limit 5;
| +---------------+-------------------------------------+--------+-------------------+---------------------+
| | ISBN          | Titolo                              | Autore | AnnoPubblicazione | QuantitaInMagazzino |
| +---------------+-------------------------------------+--------+-------------------+---------------------+
| | 9780141441146 | 1984                                | 3      |              1949 |                  12 |
| | 9780061120084 | Cronache di Narnia                  | 4      |              1950 |                  15 |
| | 9788804645238 | Dune                                | 7      |              1965 |                   7 |
| | 9788807886655 | Harry Potter e la Pietra Filosofale | 5      |              1997 |                  20 |
| | 9780553803709 | Il Codice Da Vinci                  | 2      |              2003 |                   8 |
| +---------------+-------------------------------------+--------+-------------------+---------------------+
| 5 rows in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 15
| Libri pubblicati tra il 1980 e il 1990
| mysql> select * from Libri where AnnoPubblicazione between 1980 and 1990;
| +---------------+----------------+--------+-------------------+---------------------+
| | ISBN          | Titolo         | Autore | AnnoPubblicazione | QuantitaInMagazzino |
| +---------------+----------------+--------+-------------------+---------------------+
| | 9788806180825 | Norwegian Wood | 8      |              1987 |                  10 |
| +---------------+----------------+--------+-------------------+---------------------+
| 1 row in set (0.00 sec)
+--------------------------------------------------------------------------------------
| ES 16
| Libri pubblicati dagli autori con id (1, 5 e 6)
| mysql> select * from Libri where Autore = 1 or Autore = 5 or Autore = 6;
| +---------------+--------------------------------------+--------+-------------------+---------------------+
| | ISBN          | Titolo                               | Autore | AnnoPubblicazione | QuantitaInMagazzino |
| +---------------+--------------------------------------+--------+-------------------+---------------------+
| | 9780061120085 | Le Cronache del Ghiaccio e del Fuoco | 6      |              1996 |                   5 |
| | 9780544003415 | Il Signore degli Anelli              | 1      |              1954 |                  10 |
| | 9788807886655 | Harry Potter e la Pietra Filosofale  | 5      |              1997 |                  20 |
| +---------------+--------------------------------------+--------+-------------------+---------------------+
| 3 rows in set (0.00 sec)
+--------------------------------------------------------------------------------------