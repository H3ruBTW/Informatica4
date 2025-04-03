package Testo;

import java.io.*;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/TestTesto")
public class TestTesto extends HttpServlet {
/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException{
		response.setContentType("text/html"); // content type
		PrintWriter output = response.getWriter(); // get writer
		
		// crea una pagina HTML e la invia al client
		output.println("<html>");
		output.println("<head>");
		output.println("<title>Primo esempio di Servelet</title>");
		output.println("</head>");
		output.println("<body>");
		output.println("<h1>Buongiorno, questa è la prima servlet!</h1>");
		output.println("</body>");
		output.println("</html>");
	}
}
