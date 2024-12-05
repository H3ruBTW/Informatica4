------------------------------------------------------------------------------------
-- PARTE 1/2 - CREAZIONE DEL DATABASE                                              -
------------------------------------------------------------------------------------

CREATE DATABASE IF NOT EXISTS NoleggioVeicoli;
USE NoleggioVeicoli;

--Clienti: Informazioni sui clienti registrati.
CREATE TABLE Clienti (
    cliente_id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    cognome VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    telefono VARCHAR(15),
    data_registrazione DATE DEFAULT (CURRENT_DATE) --HO MESSO LE PARENTESI PER EVITARE UN ERRORE
);

--Veicoli: Dettagli sui veicoli disponibili per il noleggio.
CREATE TABLE Veicoli (
    veicolo_id INT AUTO_INCREMENT PRIMARY KEY,
    modello VARCHAR(50) NOT NULL,
    marca VARCHAR(50) NOT NULL,
    anno INT CHECK (anno >= 2000 AND anno <= YEAR(CURDATE())), --DA ERRORE ERROR 3814 (HY000): An expression of a check constraint 'Veicoli_chk_1' contains disallowed function: curdate.
                                                               --QUINDI HO SOSTITUITO YEAR(CURDATE()) CON "2024"
    targa VARCHAR(15) UNIQUE NOT NULL,
    prezzo_giornaliero DECIMAL(10, 2) NOT NULL
);

--Noleggi: Registra i noleggi effettuati.
CREATE TABLE Noleggi (
    noleggio_id INT AUTO_INCREMENT PRIMARY KEY,
    cliente_id INT NOT NULL,
    veicolo_id INT, -- NOT NULL, --ERRORE NON PUO ESSERE SETTATO NULL NELLA INTEGRITA REFERENZIALE QUINDI RIMUOVO NOT NULL
    data_inizio DATE NOT NULL,
    data_fine DATE NOT NULL,
    totale DECIMAL(10, 2) NOT NULL CHECK (totale > 0),
    FOREIGN KEY (cliente_id) REFERENCES Clienti(cliente_id) ON DELETE CASCADE,
    FOREIGN KEY (veicolo_id) REFERENCES Veicoli(veicolo_id) ON DELETE SET NULL 
);

--Pagamenti: Dettagli sui pagamenti effettuati.
CREATE TABLE Pagamenti (
    pagamento_id INT AUTO_INCREMENT PRIMARY KEY,
    noleggio_id INT NOT NULL,
    data_pagamento DATE NOT NULL,
    importo DECIMAL(10, 2) NOT NULL CHECK (importo > 0),
    metodo_pagamento ENUM('Carta', 'Bonifico', 'Contanti') NOT NULL,
    FOREIGN KEY (noleggio_id) REFERENCES Noleggi(noleggio_id) ON DELETE CASCADE
);

------------------------------------------------------------------------------------
-- PARTE 3 - INSERIMENTO DEI DATI                                                  - 
------------------------------------------------------------------------------------
INSERT INTO Clienti (nome, cognome, email, telefono)
VALUES 
    ('Mario', 'Rossi', 'mario.rossi@email.com', '3331234567'),
    ('Anna', 'Bianchi', 'anna.bianchi@email.com', '3349876543'),
    ('Luca', 'Verdi', 'luca.verdi@email.com', '3355678901');

INSERT INTO Veicoli (modello, marca, anno, targa, prezzo_giornaliero)
VALUES 
    ('Panda', 'Fiat', 2020, 'AB123CD', 30.00),
    ('Golf', 'Volkswagen', 2019, 'EF456GH', 45.00),
    ('Civic', 'Honda', 2021, 'IJ789KL', 50.00);

INSERT INTO Noleggi (cliente_id, veicolo_id, data_inizio, data_fine, totale)
VALUES 
    (1, 1, '2024-11-01', '2024-11-05', 120.00),
    (2, 2, '2024-11-10', '2024-11-12', 90.00);

INSERT INTO Pagamenti (noleggio_id, data_pagamento, importo, metodo_pagamento)
VALUES 
    (1, '2024-11-05', 120.00, 'Carta'),
    (2, '2024-11-12', 90.00, 'Bonifico');

------------------------------------------------------------------------------------
-- VERIFICA DEI VINCOLI                                                            -
------------------------------------------------------------------------------------

--La colonna email nella tabella Clienti non può essere NULL, quindi proviamo a inserire un cliente senza email
insert into Clienti (nome, cognome, telefono) VALUES   
    ('Alessandro', 'Buongallino', '3333333333');

--ERROR 1364 (HY000): Field 'email' doesn't have a default value
--QUESTO ERRORE INDICA CHE APPUNTO DEVE ESSERE INSERITA LA MAIL


--La colonna email nella tabella Clienti deve essere unica, quindi proviamo a inserire due clienti con la stessa email
--USO UNA QUERY DI PRIMA CHE FUNZIONA LO STESSO
INSERT INTO Clienti (nome, cognome, email, telefono)
VALUES 
    ('Mario', 'Rossi', 'mario.rossi@email.com', '3331234567');

--ERROR 1062 (23000): Duplicate entry 'mario.rossi@email.com' for key 'Clienti.email'
--ATTRIBUTO DUPLICATO NELLA TABELLA QUINDI ERRORE


--La colonna targa nella tabella Veicoli deve essere unica, quindi proviamo a inserire un altro veicolo con la stessa targa
INSERT INTO Veicoli (modello, marca, anno, targa, prezzo_giornaliero)
VALUES 
    ('Panda', 'Fiat', 2020, 'AB123CD', 30.00);

--ERROR 1062 (23000): Duplicate entry 'AB123CD' for key 'Veicoli.targa'
--STESSI ERRORE DI PRIMA


--La colonna anno nella tabella Veicoli ha un vincolo CHECK che limita l'anno a valori tra il 2000 e l'anno corrente. 
--Proviamo a inserire un veicolo con un anno fuori dal range
INSERT INTO Veicoli (modello, marca, anno, targa, prezzo_giornaliero)
VALUES 
    ('Panda', 'Fiat', 2029, 'AB123CE', 30.00);

--ERROR 3819 (HY000): Check constraint 'Veicoli_chk_1' is violated.
--LA CHECK E' STATA VIOLATA POICHE' LA DATA E' OLTRE IL 2024


--La colonna totale nella tabella Noleggi ha un vincolo CHECK che impone che il totale sia maggiore di 0. 
--Proviamo a inserire un noleggio con un totale negativo
INSERT INTO Noleggi (cliente_id, veicolo_id, data_inizio, data_fine, totale)
VALUES 
    (1, 1, '2024-11-01', '2024-11-05', 0.00);

--ERROR 3819 (HY000): Check constraint 'Noleggi_chk_1' is violated.
--LA CHECK E' STATA VIOLATA POICHE' IL PREZZO NON E' MAGGIORE DI 0


--La colonna cliente_id nella tabella Noleggi fa riferimento alla colonna cliente_id nella tabella Clienti. 
--Se cerchiamo di inserire un noleggio con un cliente_id che non esiste nella tabella Clienti, il vincolo di chiave esterna fallirà
INSERT INTO Noleggi (cliente_id, veicolo_id, data_inizio, data_fine, totale)
VALUES 
    (9, 1, '2024-11-01', '2024-11-05', 90.00);

--ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails 
--(`NoleggioVeicoli`.`Noleggi`, CONSTRAINT `Noleggi_ibfk_1` FOREIGN KEY (`cliente_id`) REFERENCES 
--`Clienti` (`cliente_id`) ON DELETE CASCADE)
--IN POCHE PAROLE LA FOREIGN KEY NON SI RIFERISCE A NESSUNA ISTANZA DI CLIENTI


--Allo stesso modo, se proviamo a eliminare un cliente che ha dei noleggi associati, 
--il vincolo di chiave esterna con ON DELETE CASCADE eliminerà anche i noleggi
DELETE FROM Clienti WHERE cliente_id = 1;

--PRIMA
--mysql> select * from Clienti;
--+------------+-------+---------+------------------------+------------+--------------------+
--| cliente_id | nome  | cognome | email                  | telefono   | data_registrazione |
--+------------+-------+---------+------------------------+------------+--------------------+
--|          1 | Mario | Rossi   | mario.rossi@email.com  | 3331234567 | 2024-12-05         |
--|          2 | Anna  | Bianchi | anna.bianchi@email.com | 3349876543 | 2024-12-05         |
--|          3 | Luca  | Verdi   | luca.verdi@email.com   | 3355678901 | 2024-12-05         |
--+------------+-------+---------+------------------------+------------+--------------------+
--
--mysql> select * from Noleggi;
--+-------------+------------+------------+-------------+------------+--------+
--| noleggio_id | cliente_id | veicolo_id | data_inizio | data_fine  | totale |
--+-------------+------------+------------+-------------+------------+--------+
--|           1 |          1 |          1 | 2024-11-01  | 2024-11-05 | 120.00 |
--|           2 |          2 |          2 | 2024-11-10  | 2024-11-12 |  90.00 |
--+-------------+------------+------------+-------------+------------+--------+

--DOPO
--mysql> select * from Clienti;
--+------------+------+---------+------------------------+------------+--------------------+
--| cliente_id | nome | cognome | email                  | telefono   | data_registrazione |
--+------------+------+---------+------------------------+------------+--------------------+
--|          2 | Anna | Bianchi | anna.bianchi@email.com | 3349876543 | 2024-12-05         |
--|          3 | Luca | Verdi   | luca.verdi@email.com   | 3355678901 | 2024-12-05         |
--+------------+------+---------+------------------------+------------+--------------------+
--
--mysql> select * from Noleggi;
--+-------------+------------+------------+-------------+------------+--------+
--| noleggio_id | cliente_id | veicolo_id | data_inizio | data_fine  | totale |
--+-------------+------------+------------+-------------+------------+--------+
--|           2 |          2 |          2 | 2024-11-10  | 2024-11-12 |  90.00 |
--+-------------+------------+------------+-------------+------------+--------+
--L'ISTANZA DOVE C'ERA IL CLIENTE CON ID 1 E' STATA ELIMINATA COL CLIENTE
