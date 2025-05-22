<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="JSP.ES1" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Display Person Information</title>
</head>
<body>
<%
ES1 person = new ES1();
person.setName("Mario");
person.setAge(30);
%>
<h1>Person Information</h1>
<p>Name: <%= person.getName() %></p>
<p>Age: <%= person.getAge() %></p>
</body>
</html>