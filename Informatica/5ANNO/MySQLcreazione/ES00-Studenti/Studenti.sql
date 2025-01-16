CREATE DATABASE Studenti;

USE Studenti;

-- Creazione delle tabelle
CREATE TABLE Corsi (
    codice_corso INT PRIMARY KEY,
    nome_corso VARCHAR(50) NOT NULL
);

CREATE TABLE Materia (
    codice_materia INT PRIMARY KEY,
    nome_materia VARCHAR(50) NOT NULL
);

CREATE TABLE Studente (
    matricola INT PRIMARY KEY,
    cognome VARCHAR(50) NOT NULL,
    data_nascita DATE NOT NULL,
    codice_corso INT,
    capogruppo int NOT NULL,
    FOREIGN KEY (codice_corso) REFERENCES Corsi(codice_corso)
);

CREATE TABLE Valutazioni (
    matricola INT,
    codice_materia INT,
    voto INT NOT NULL,
    commento VARCHAR(255),
    PRIMARY KEY (matricola, codice_materia),
    FOREIGN KEY (matricola) REFERENCES Studente(matricola),
    FOREIGN KEY (codice_materia) REFERENCES Materia(codice_materia)
);

-- Inserimento dei dati
INSERT INTO Corsi (nome_corso) values (
    "Informatica",
    "Artistico",
    "Telecomunicazioni"
);

INSERT INTO Materia (nome_materia) values (
    "Matematica",
    "Italiano",
    "Informatica"
);

INSERT INTO Studente (cognome, data_nascita, codice_corso, capogruppo) values (
    "Angelico", "2006-01-01", 1, 1,
    "Baglì", "2006-02-02", 1, 1,
    "Buongallino", "2006-03-03", 1, 2,
    "Spinola", "2006-04-04", 1, 2,
);

INSERT INTO Valutazioni (matricola, codice_materia, voto, commento) values (
    1, 1, 8, "COMPITO SULLE FUNZIONI",
    1, 2, 7, "VERGA",
    2, 1, 6, "COMPITO SULLE FUNZIONI",
    2, 2, 8, "VERGA",
    3, 1, 9, "COMPITO SULLE FUNZIONI",
    3, 2, 7, "VERGA",
    4, 1, 4, "COMPITO SULLE FUNZIONI",
    4, 2, 6, "VERGA",
);
