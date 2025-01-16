CREATE DATABASE Studenti;

USE Studenti;

-- Creazione delle tabelle
CREATE TABLE Corsi (
    codice_corso INT PRIMARY KEY AUTO_INCREMENT,
    nome_corso VARCHAR(50) NOT NULL
);

CREATE TABLE Materie (
    codice_materia INT PRIMARY KEY AUTO_INCREMENT,
    nome_materia VARCHAR(50) NOT NULL
);

CREATE TABLE Studenti (
    matricola INT PRIMARY KEY AUTO_INCREMENT,
    cognome VARCHAR(50) NOT NULL,
    data_nascita DATE NOT NULL,
    codice_corso INT,
    capogruppo int NOT NULL,
    FOREIGN KEY (codice_corso) REFERENCES Corsi(codice_corso) ON DELETE NO ACTION ON UPDATE CASCADE
);

CREATE TABLE Valutazioni (
    codice_valutazione INT PRIMARY KEY AUTO_INCREMENT,
    matricola INT,
    codice_materia INT,
    voto INT NOT NULL,
    commento VARCHAR(255),
    FOREIGN KEY (matricola) REFERENCES Studenti(matricola) ON DELETE NO ACTION ON UPDATE CASCADE,
    FOREIGN KEY (codice_materia) REFERENCES Materie(codice_materia) ON DELETE CASCADE ON UPDATE CASCADE
);

-- Inserimento dei dati
INSERT INTO Corsi (nome_corso) values (
    "Informatica",
    "Artistico",
    "Telecomunicazioni"
);

INSERT INTO Materie (nome_materia) values (
    "Matematica",
    "Italiano",
    "Informatica"
);

INSERT INTO Studenti (cognome, data_nascita, codice_corso, capogruppo) values (
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
