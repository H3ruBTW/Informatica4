<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>ESEMPIO DI BEAN</title>
</head>
<body> -NOME DEL PACKAGE-
<jsp:useBean id="Bean" class="JSP.ES2"/>
<h1>ESEMPIO DI BEAN</h1>
<p><%= Bean.getTesto() %></p>

</body>
</html>