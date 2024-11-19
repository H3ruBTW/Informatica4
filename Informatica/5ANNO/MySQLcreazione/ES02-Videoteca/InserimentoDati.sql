insert into Formato (tipo) values
    ("CD"),
    ("DVD"),
    ("VIDEOCASSETTA");

insert into Videocassetta (titolo, durata, data_uscita, id_formato) values
    ("Oppenheimer", "180 min", "2023-07-11", 2),
    ("Interstellar", "169 min", "2014-11-05", 2);

insert into Regista (nome, cognome, data_nascita) values
    ("Christopher", "Nolan", "1970-07-30");

insert into Registi_Videocassette (id_regista, id_videocassetta) values
    (1, 1),
    (1, 2);

insert into Attore (nome, cognome, data_nascita) values
    ("Cillian", "Murphy", "1976-05-25"),
    ("Tom", "Conti", "1941-11-22"),
    ("Matthew", "McConaughey", "1969-11-04"),
    ("Anne", "Hathaway", "1982-11-12");

insert into Attori_Videocassette (id_attore, id_videocassetta, personaggio) values
    (1, 1, "Robert J. Oppenheimer"),
    (2, 1, "Albert Einstein"),
    (3, 2, "Joseph Cooper"),
    (4, 2, "Amelia Brand");

insert into Genere (nome_genere) values
    ("biografico"), 
    ("drammatico"), 
    ("thriller"), 
    ("storico"),
    ("fantascienza"), 
    ("avventura");

insert into Generi_Videocassette (id_videocassetta, id_genere) values
    (1, 1),
    (1, 2),
    (1, 3),
    (1, 4),
    (2, 5),
    (2, 6),
    (2, 2);
