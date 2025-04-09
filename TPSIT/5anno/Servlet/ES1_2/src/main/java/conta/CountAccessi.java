package conta;

import jakarta.servlet.ServletConfig;

import jakarta.servlet.ServletContext;

import jakarta.servlet.ServletException;

import jakarta.servlet.annotation.WebServlet;

import jakarta.servlet.http.HttpServlet;

import jakarta.servlet.http.HttpServletRequest;

import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

import java.io.PrintWriter;

@WebServlet("/Count")
public class CountAccessi extends HttpServlet {

	private static final long serialVersionUID = 1L;

	public CountAccessi() {
		super();
	}

	public void init (ServletConfig config) throws ServletException {

		super.init(config);
		
		ServletContext context = getServletContext();//INSERIRE L'OGGETTO DELLA CLASSE SERVLETCONTEXT
		
		if (context.getAttribute("countx") == null) {
		
			context.setAttribute("countx", 1);
		
		} 
	
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	
		response.setContentType("text/html");
		
		PrintWriter out = response.getWriter();
		
		ServletContext context = getServletContext();//INSERIRE L'OGGETTO DELLA CLASSE SERVLETCONTEXT
		
		int count = (int) context.getAttribute("countx");
		
		out.println("<html><body>Conta le volte che viene caricata la pagina:  " + count++ + " volte<html></body>");
		
		context.setAttribute("countx", count);
	
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
