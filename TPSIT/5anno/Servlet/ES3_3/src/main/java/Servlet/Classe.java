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


@WebServlet("/Profile")
public class Classe extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	
	public Classe() {
		super();
	}
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		request.getRequestDispatcher("link.html").include(request, response);
		Cookie ck[]=request.getCookies();
		if(ck!=null){ 
			String name= ck[0].getValue(); 
			if(!name.equals("")||name!=null){
			out.print("<b>Welcome to Profile</b>");
			out.print("<br>Welcome, "+name);
			}
		}else{
			out.print("Please login first");//niente cookie poichè non è stato fatto l’accesso
			request.getRequestDispatcher("login.html").include(request, response);
		}
		out.close();
	}
	
}

