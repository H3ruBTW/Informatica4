package servlet;

import jakarta.servlet.ServletConfig;

import jakarta.servlet.ServletContext;

import jakarta.servlet.ServletException;

import jakarta.servlet.annotation.WebServlet;

import jakarta.servlet.http.HttpServlet;

import jakarta.servlet.http.HttpServletRequest;

import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

import java.io.PrintWriter;

import jakarta.servlet.annotation.WebServlet;

@WebServlet("/DemoServlet")
public class DemoServlet extends HttpServlet {

private static final long serialVersionUID = 1L;      

    public DemoServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		response.setContentType("text/html");  
		
		PrintWriter pw=response.getWriter(); 
		
		String name=request.getParameter("str");//INSERIRE IL METODO CORRETO DELLA CLASSE SERVLETREQUEST CHE ritorna il                                                                                                         //valore del parametro inviato DALL’HTML CHE LO CHIAMA 
		
		pw.println("Welcome "+name);   
		
		pw.close();  
	
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		// TODO Auto-generated method stub
		doGet(request, response);
	
	}

}