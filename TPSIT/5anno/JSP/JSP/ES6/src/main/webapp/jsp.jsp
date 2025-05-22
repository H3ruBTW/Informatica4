<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<body>
<%
String uname = request.getParameter("uname");
String dname = request.getParameter("dname"); // Leggi il valore del form!
out.print("Welcome " + uname + "<br/>");
out.print("Driver name dalla form = " + dname + "<br/>");
String driverFromXml = application.getInitParameter("dname");
out.print("Driver name from web.xml = " + driverFromXml);
%>
</body>
</html>