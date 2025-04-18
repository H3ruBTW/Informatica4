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
import jakarta.servlet.http.HttpSession;


@WebServlet("/Logout")
public class Classe2 extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	
	public Classe2() {
		super();
	}
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		request.getRequestDispatcher("link.html").include(request, response);//INVIA TUTTO AL LINK.HTML VEDERE A PAG.14
		HttpSession session = request.getSession();//RICHIAMA LA SESSIONE PROPRIA NEL LOGOUT VEDERE PAG.52
		session.invalidate();//QUESTO METODO CHIUDE LA SESSIONE VEDERE PAG 53
		out.print("You are successfully logged out!");
		out.close();
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
	
}

