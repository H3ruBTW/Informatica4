<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Esempio di codice JSP</title>
</head>
<body>
<!-- DICHIARAZIONI -->
<%! String utente = "Anna Maria";
double[] prezzi = { 11.5, 73.8, 121.5 };
double getTotale() {
double totale = 0.0;
for (int x = 0; x < prezzi.length; x++)
totale += prezzi[x];
return totale;
}
%>
<!--espressioni -->
<P>Gentile cliente <%= utente %>, oggi <%= new
java.util.Date().toString() %></P>
<P>ha effettuato acquisti per Euro: <%= getTotale()%>.</P>
</body>
</html>