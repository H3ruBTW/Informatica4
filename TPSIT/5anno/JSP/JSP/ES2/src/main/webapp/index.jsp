<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<HTML >
<TITLE> Esempio di codice JSP </TITLE>
<BODY>
<!-- dichiarazioni -->
<%!
String utente = "Anna Maria";
double totale = 1230.5090;
%>
<!-- espressioni -->
<P><FONT COLOR="#0000FF">Gentile cliente
<%= utente%></FONT>
Oggi <%= new java.util.Date().toString() %> </P>
<P>ha effettuato acquisti per Euro: <%= totale %>:</P>
<!-- scriplet -->
<% if (totale > 1000) { %>
<H3> puo' effettuare un pagamento rateizzato </H3>
<% } else { %>
<H3> devi pagare in una sola soluzione.</H3>
<% } %>
</BODY>
</HTML>