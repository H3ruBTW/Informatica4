-- CREARE IL DATABASE
create database Videoteca if not exists;
use Videoteca;

-- CREO L'ENTITA FORTE FORMATO FISICO COSI DA POI CREARE VIDEOCASSETTE
create table Formato (
    id_formato int not null auto_increment,
    tipo varchar(20) not null,
    primary key (id_formato)
);

create table Videocassette (
    id_videocassetta int not null auto_increment,
    id_formato int not null,
    titolo varchar(100) not null, 
    durata varchar(10) not null,
    data_uscita date not null,
    primary key (id_videocassetta),
    foreign key (id_formato) references Formato(id_formato)
);