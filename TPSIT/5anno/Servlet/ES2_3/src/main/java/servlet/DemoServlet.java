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

//@WebServlet("/Demo")
public class DemoServlet extends HttpServlet {  

	private static final long serialVersionUID = 1L;
	
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {  
	
	    response.setContentType("text/html");  
	
	    PrintWriter out = response.getWriter();      
	
	    ServletConfig config = getServletConfig();//INSERIRE L'OGGETTO DELLA CLASSE SERVLETCONFIG
	
	    String str =config.getInitParameter("param");  //INSERIRE IL METODO CHE LEGGERA' IL PARAMTRO IN WEB.XML
	
	    out.print("IL VALORE DEL MIO PARAMETRO E': "+ str);           
	
	    out.close();  

    }  

}
