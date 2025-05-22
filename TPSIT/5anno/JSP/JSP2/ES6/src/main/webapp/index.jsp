<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<HTML>
<head><TITLE>JSP e database MySQL</TITLE></head>
<BODY>
<H2>JSP e database MySQL</H2>
<%@ page import="java.sql.*" %>
<TABLE BORDER="1">
<%
// carico il driver per la connessione al DB MySQL
String DRIVER = "com.mysql.jdbc.Driver";
// riferimento al database: connessione MySQL
String URL_mioDB = "jdbc:mysql://localhost:3306/first"; //3306 di default
// definizione della query
String query = "SELECT * FROM user905";
try{
Class.forName(DRIVER);
}
catch (ClassNotFoundException e) {
System.err.println("Driver non trovato" + e);
}
Connection connessione = null;
try{ // apro la connesione verso il database
connessione = DriverManager.getConnection(URL_mioDB,"root","Password");
}
catch (Exception e){
System.err.println("Errore nella connessione col database: " + e);
}
try{
// ottengo lo Statement per interagire con il database
Statement statement = connessione.createStatement();
// interrogo il DBMS mediante una query SQL
ResultSet resultSet = statement.executeQuery(query);
// scorro e mostro i risultati
out.println("<PRE>");
out.println("<B>name"+"&#9;"+"password"+"&#9;"+"email"+"&#9;"+"country</B><BR>");
while (resultSet.next()) {
String name = resultSet.getString(1);
String password = resultSet.getString(2);
String email = resultSet.getString(3);
String country = resultSet.getString(4);
out.println( name+"&#9;"+password+"&#9;"+email+"&#9;"+country);
}
out.println("</PRE>");
}
catch (Exception e){
System.err.println(e);
}
try{ // chiusura connessione
connessione.close();
}
catch (Exception e) {
System.err.println(e);
}

%>
</TABLE>
</BODY>
</HTML>