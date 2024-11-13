-- Creare un nuovo database
CREATE DATABASE IF NOT EXISTS biblioteca;
USE biblioteca;

-- Creare la tabella degli autori
CREATE TABLE IF NOT EXISTS autori (
    id_autore INT AUTO_INCREMENT PRIMARY KEY,
    nome_autore VARCHAR(50) NOT NULL,
    nazionalita VARCHAR(50),
    data_nascita DATE,
    data_morte DATE
);

-- Inserire alcuni dati nella tabella degli autori
INSERT INTO autori (nome_autore, nazionalita, data_nascita, data_morte)
VALUES
    ('Jane Austen', 'Inglese', '1775-12-16', '1817-07-18'),
    ('George Orwell', 'Inglese', '1903-06-25', '1950-01-21'),
    ('Harper Lee', 'Americana', '1926-04-28', '2016-02-19');

-- Verifico il corretto inserimento dei dati
SELECT * FROM autori;

-- Creare la tabella delle categorie
CREATE TABLE IF NOT EXISTS categorie (
    id_categoria INT AUTO_INCREMENT PRIMARY KEY,
    nome_categoria VARCHAR(50) NOT NULL
);

-- Inserire alcuni dati nella tabella delle categorie
INSERT INTO categorie (nome_categoria)
VALUES
    ('Romanzo'),
    ('Saggio'),
    ('Fantascienza'),
    ('Mistero');

-- Verifico il corretto inserimento dei dati
SELECT * FROM categorie ;

-- Creare la tabella dei libri
CREATE TABLE IF NOT EXISTS libri (
    id_libro INT AUTO_INCREMENT PRIMARY KEY,
    titolo VARCHAR(100) NOT NULL,
    id_autore INT,
    id_categoria INT,
    anno_pubblicazione INT,
    FOREIGN KEY (id_autore) REFERENCES autori(id_autore),
    FOREIGN KEY (id_categoria) REFERENCES categorie(id_categoria)
);

-- Inserire alcuni dati nella tabella dei libri
INSERT INTO libri (titolo, id_autore, id_categoria, anno_pubblicazione)
VALUES
    ('Orgoglio e pregiudizio', 1, 1, 1813),
    ('1984', 2, 3, 1949),
    ('Il buio oltre la siepe', 3, 1, 1960),
    ('Guerra e pace', 1, 1, 1869);

-- Verifico il corretto inserimento dei dati
SELECT * FROM libri;

SHOW TABLES;

-- CON LA MODIFICA CON BIBLIOTECA v2

-- Rimuovo "nazionalita" da "autori" poichè non serve più
alter table autori drop column nazionalita;

-- Creo le tabelle "nazionalita-autori" e "nazionalita"
create table nazionalita (
    id_nazionalita int(11) auto_increment not null,
    str_nazionalita varchar(30) not null,
    primary key(id_nazionalita)
);

create table nazionalita_autori (
    id_nazionalita_autori int(11) auto_increment not null,
    id_nazionalita int(11) not null,
    id_autore int(11) not null,
    primary key(id_nazionalita_autori),
    foreign key(id_nazionalita) references nazionalita(id_nazionalita),
    foreign key(id_autore) references autori(id_autore)
);

-- Adesso gestiamo i prestiti creando prima l'entità forte "cliente" e dopo la tabella dei "prestiti"
create table cliente (
    id_cliente int(11) auto_increment not null,
    nome varchar(40) not null,
    cognome varchar(40) not null,
    data_nascita date not null,
    primary key(id_cliente)
);

create table prestiti(
    id_prestito int(11) auto_increment not null,
    id_cliente int(11)  not null,
    id_libro int(11) not null,
    data_inizio date not null,
    data_fine date not null,
    primary key(id_prestito),
    foreign key(id_cliente) references cliente(id_cliente),
    foreign key(id_libro) references libri(id_libro)
);

-- INSERISCO DATI NELLE TABELLE
insert into nazionalita (str_nazionalita) values 
    ("inglese"),
    ("americano");

insert into nazionalita_autori (id_autore, id_nazionalita) values 
    (1, 1),
    (2, 1),
    (3, 2);

insert into cliente (nome, cognome, data_nascita) values 
    ("antonio", "rossi", "1982-05-14"),
    ("mario", "sturniolo", "1998-11-8");

insert into nazionalita_autori (id_cliente, id_libro, data_inizio, data_fine) values 
    (1, 2, "2024-11-11", "2024-12-11"),
    (2, 4, "2024-11-11", "2024-12-11");