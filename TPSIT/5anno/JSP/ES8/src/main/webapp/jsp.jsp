<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<body>
<%@ include file="index.html" %>
<h1>OGGI È IL GIORNO CHE TI DEVI MUOVERE
<%= java.util.Calendar.getInstance().getTime() %>
</h1>
</body>
</html>