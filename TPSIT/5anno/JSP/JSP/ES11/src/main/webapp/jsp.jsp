<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
<head>
<title>Esempio Taglib JSTL</title>
</head>
<body>
<c:set var="messaggio" value="Ciao dal tag JSTL!" />
<h2>Output del messaggio:</h2>
<p><c:out value="${messaggio}" /></p>
</body>
</html>