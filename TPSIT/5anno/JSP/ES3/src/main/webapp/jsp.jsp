<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<body>
<form>
<%
String name=request.getParameter("name");
out.print("welcome "+name);
%>
</form>
</body>
</html>