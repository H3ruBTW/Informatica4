<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>SSSSSSSSSSS</title>
</head>
<body>
<jsp:useBean id="Bean" class="JSP.ES3" />
<jsp:setProperty name="Bean" property="name" />

<H1>WELCOME:<br>
<jsp:getProperty name="Bean" property="name" />

</H1>
</body>
</html>