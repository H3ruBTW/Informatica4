package Servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

import jakarta.servlet.ServletContext;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;


@WebServlet("/Login")
public class Classe3 extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	
	public Classe3() {
		super();
	}
	
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		request.getRequestDispatcher("link.html").include(request, response);
		String name=request.getParameter("name");
		String password=request.getParameter("password");
		if(password.equals("vivalascuola")){
			out.print("You are successfully logged in!");
			out.print("<br>Welcome, "+name);
			Cookie ck=new Cookie("name", name);
			response.addCookie(ck);
		}else{
			out.print("sorry, username or password error!");
			request.getRequestDispatcher("login.html").include(request, response);//TORNA ALL’ACCESSO
		}
		out.close();
	}
}

