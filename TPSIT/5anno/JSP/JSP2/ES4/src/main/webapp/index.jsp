<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%! public long fact (long x) {
if (x == 0)
return 1;
else
return x * fact(x-1);
}
%>
<HTML><HEAD><TITLE>Fattoriale ricorsivo</TITLE></HEAD>
<BODY>
<H2 ALIGN="CENTER">Fattoriale ricorsivo con ciclo FOR</H2>
<TABLE ALIGN="CENTER" BORDER="1">
<TR>
<TD><I>n</I></TD>
<TD><I>n</I>!</TD>
</TR>
<% for (long x = 01; x <= 101; ++x) { %>
<TR><TD><%= x %></TD><TD><%= fact(x) %></TD></TR>
<% } %>
</TABLE></BODY></HTML>