<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<body>
<%
out.print("Welcome "+request.getParameter("name"));
String driver=config.getInitParameter("name");
out.print("driver name is="+driver);
%>
</body>
</html>