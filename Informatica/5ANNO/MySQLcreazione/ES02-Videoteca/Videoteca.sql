-- CREARE IL DATABASE
create database IF not exists Videoteca;
use Videoteca;

-- CREO L'ENTITA FORTE FORMATO FISICO COSI DA POI CREARE VIDEOCASSETTE
create table Formato (
    id_formato int not null auto_increment,
    tipo varchar(20) not null,
    primary key (id_formato)
);

create table Videocassetta (
    id_videocassetta int not null auto_increment,
    id_formato int not null,
    titolo varchar(100) not null, 
    durata varchar(10) not null,
    data_uscita date not null,
    primary key (id_videocassetta),
    foreign key (id_formato) references Formato(id_formato) on delete no action
);

-- CREO ATTORE
create table Attore (
    id_attore int not null auto_increment,
    nome varchar(30) not null,
    cognome varchar(30) not null,
    data_nascita date not null,
    primary key (id_attore)
);

create table Attori_Videocassette (
    id_attori_videocassette int not null auto_increment,
    id_attore int not null,
    id_videocassetta int not null,
    primary key (id_attori_videocassette),
    foreign key (id_attore) references Attore(id_attore) on delete no action, -- L'ATTORE NON PUO' ESSERE CANCELLATO FINCHE' CI SONO
                                                                              -- ALTRE VIDEOCASSETTE CON EGLI CHE PARTECIPA
    foreign key (id_videocassetta) references Videocassetta(id_videocassetta) on delete cascade
);

-- CREO REGISTA
create table Regista (
    id_regista int not null auto_increment,
    nome varchar(30) not null,
    cognome varchar(30) not null,
    data_nascita date not null,
    primary key (id_regista)
);

create table Registi_Videocassette (
    id_registi_videocassette int not null auto_increment,
    id_regista int not null,
    id_videocassetta int not null,
    primary key (id_registi_videocassette),
    foreign key (id_regista) references Regista(id_regista) on delete no action, -- IL REGISTA NON PUO' ESSERE CANCELLATO FINCHE' CI 
                                                                                 -- SONO ALTRE VIDEOCASSETTE GIRATE DA ESSO
    foreign key (id_videocassetta) references Videocassetta(id_videocassetta) on delete cascade
);

-- CREO GENERI
create table Genere (
    id_genere int not null auto_increment,
    nome_genere varchar(30) not null,
    primary key (id_genere)
);

create table Generi_Videocassette (
    id_generi_videocassette int not null auto_increment,
    id_genere int not null,
    id_videocassetta int not null,
    primary key (id_generi_videocassette),
    foreign key (id_genere) references Genere(id_genere) on delete no action,
    foreign key (id_videocassetta) references Videocassetta(id_videocassetta) on delete cascade
);

-- CREO IL CLIENTE
create table Cliente (
    id_tessera int not null auto_increment,
    nome varchar(30) not null,
    cognome varchar(30) not null,
    data_nascita date not null,
    primary key (id_tessera) 
);

-- CREO I PRESTITI
create table Prestito (
    id_prestito int not null auto_increment,
    id_tessera int, -- IN CASO DI CANCELLAZIONE DEL CLIENTE SI VUOLE TENERE IL PRESTITO PRECEDENTE (SET NULL)
    id_videocassetta int,
    data_inizio date not null,
    data_fine date not null,
    primary key (id_prestito),
    foreign key (id_tessera) references Cliente(id_tessera) on delete set null,
    foreign key (id_videocassetta) references Videocassetta(id_videocassetta) on delete set null
);

-- ED INFINE I PAGAMENTI
create table Pagamento (
    id_pagamento int not null auto_increment,
    id_prestito int not null,
    prezzo varchar(10) not null,
    primary key (id_pagamento),
    foreign key (id_prestito) references Prestito(id_prestito) -- NON METTO LA INTEGRITA' REFENZIALE POICHE'
                                                               -- PRESTITO NON PUO' ESSERE CANCELLATA
);