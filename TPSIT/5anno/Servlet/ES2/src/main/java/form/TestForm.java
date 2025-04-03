package form;

import java.io.*;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/Form")
public class TestForm extends HttpServlet {
/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException{
		response.setContentType("text/html"); // content type
		PrintWriter output = response.getWriter(); // get writer
		
		//stringhe del get
		String a = request.getParameter("str1");
		String b = request.getParameter("str2");
		System.out.println(a);
		System.out.println(b);
		
		// crea una pagina HTML e la invia al client
		output.println("<html>");
		output.println("<head>");
		output.println("<title>Risultato Form</title>");
		output.println("</head>");
		output.println("<body>");
		output.println("<h1>Inserimenti</h1>");
		output.println("<p>Primo inserimento: " + a + "<br>");
		output.println("Secondo inserimento: " + b + "<br></p>");
		output.println("</body>");
		output.println("</html>");
	}
}
