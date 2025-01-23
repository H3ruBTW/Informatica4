/* Per gli studenti il cui cognome inizia con una data lettera, 
visualizzare cognome, voti con il nome della materia e l'età espressa in anni */
select s.cognome as Cognome, YEAR(curdate())-YEAR(s.data_nascita) as Età, v.voto as Voto, m.nome_materia as Materia 
from Studenti s, Valutazioni v, Materie m 
where s.cognome like "B%" and s.matricola=v.matricola and v.codice_materia=m.codice_materia;

/* Nota la matricola, visualizzare il cognome di quello studente, 
quanti voti ha, la media dei voti, il voto più alto e il voto più basso */
select s.cognome as Cognome, COUNT(v.voto) as "Numero Valutazioni", AVG(v.voto) as Media, 
MAX(v.voto) as "Voto Massimo", MIN(v.voto) as "Voto Minimo" 
from Studenti s, Valutazioni v 
where s.matricola=v.matricola and s.matricola=2;

--Visualizzare quanti studenti hanno più di 18 anni
select COUNT(*) as "Studenti Maggiorenni" from Studenti where (YEAR(curdate())-YEAR(data_nascita))>=18;

--Visualizzare i cognomi degli studenti che non hanno voti
select s.cognome from Studenti s left join Valutazioni v on s.matricola=v.matricola where v.voto is null;