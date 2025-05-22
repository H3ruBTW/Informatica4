<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%! int contatoreGlobale = 0;%>
<HTML>
<BODY bgcolor ="ffffcc">
<TITLE> Esempio di variabili JSP </TITLE>
<H4> <FONT COLOR="#FF0000" >Variabile globale e locale </FONT></H4>
<HR>
Contatore globale -> si incrementa: <%= ++contatoreGlobale %>
<% int contatoreLocale = 0; %>
<P> Contatore locale -> non viene incrementato: <%= ++contatoreLocale %> </p>
<HR>
<P><a href = "index.jsp">Ricarica la pagina</a></P>
</BODY>
</HTML>