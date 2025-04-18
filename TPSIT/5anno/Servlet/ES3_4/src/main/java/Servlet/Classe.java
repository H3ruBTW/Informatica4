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


@WebServlet("/Profile")
public class Classe extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	
	public Classe() {
		super();
	}
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		request.getRequestDispatcher("link.html").include(request, response);//VEDERE PAG. 14
		HttpSession session=request.getSession(false);//NON CREA UNA NUOVA SESSIONE,MANTIENE QUELLA PRECEDENTE VAI A PAG.53
		if(session!=null){
			String name=(String)session.getAttribute("name");//ESTRAE IL NOME DELL’ATTRIBUTO name DALLA SESSIONE ATTUALE
			//VEDERE PAG.54
			out.print("Hello, "+name+" Welcome to Profile");
		}
		else{
			out.print("Please login first"); //SE NON C’È UNA SESSIONE TI INVITA NUOVAMENTE AL LOGIN
			request.getRequestDispatcher("login.html").include(request, response);//VEDERE PAG. 14
		}
		out.close();
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}
	
}

