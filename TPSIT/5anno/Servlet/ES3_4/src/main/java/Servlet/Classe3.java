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


@WebServlet("/Login")
public class Classe3 extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	
	public Classe3() {
		super();
	}
	
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		request.getRequestDispatcher("link.html").include(request, response);//METODO CHE RIMANDA AD UN FILE HTML O WEB GIÀ USATO
		//NEGLI ESERCIZI PRECEDENTI VEDERE PAG.13
		String name=request.getParameter("name");
		String password=request.getParameter("password");//ESTRAE I PARAMETRI CON I NOTI METODI GIA’ USATI NEI PRECEDENTI ESERCIZI
		//VEDERE PAG.14
		if(password.equals("admin123")){
			//out.print("Welcome, "+name);
			HttpSession session= request.getSession();//CREA UNA SESSIONE PAG.52
			session.setAttribute("name", name);//METODO CHE INSERISCE IL NOME COME ID DI SESSIONE VEDERE PAG.54
			out.print("Welcome, "+session.getAttribute("name"));
		}
		else{
			out.print("Sorry, username or password error!");
			request.getRequestDispatcher("login.html").include(request, response);//TORNA AL LOGIN VEDERE PAG.13
		}
		out.close();
	}
}

