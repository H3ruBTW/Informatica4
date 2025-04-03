package Buffer;

import java.io.*;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/TestBuffer")
public class TestBuffer extends HttpServlet{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
		response.setContentType("text/html"); // content type
		PrintWriter output = response.getWriter(); // get writer
		
		// crea una pagina HTML e la invia al client
		StringBuffer buffer = new StringBuffer();
		buffer.append( "<HTML><HEAD><TITLE>\n" );
		buffer.append( "Secondo esempio di Servlet\n" );
		buffer.append( "</TITLE></HEAD><BODY>\n" );
		buffer.append("<h1>Buongiorno, questa è la seconda servlet!</h1>");
		buffer.append( "</BODY></HTML>" );
		output.println( buffer.toString() );
		output.close(); // chiusura del PrintWriter stream
	}
}
