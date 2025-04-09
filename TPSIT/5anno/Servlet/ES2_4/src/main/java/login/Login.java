package login;

import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class Login extends HttpServlet {

private static final long serialVersionUID = 1L;  

    public Login() {

        super();

    }

protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

response.setContentType("text/html");  

    PrintWriter out = response.getWriter();         

    String n=request.getParameter("name");  

    String p=request.getParameter("psw");

       if(p == null || p.isEmpty()) {

        out.print("Password Error!");

        RequestDispatcher rd = request.getRequestDispatcher("/index.html");//inserire il METODO DELLA CLASSE INTERFACCIA                                                                                                                                                           //REQUESTDISPATCHER CHE CHAMA LA PAGINE HTML INDICATA  

        rd.include(request, response);  

        return; // Stop further execution

    }           

    if(p.equals("servlet")){  

        RequestDispatcher rd=request.getRequestDispatcher("/index.html"); //inserire il METODO DELLA CLASSE INTERFACCIA                                                                                                                                                           //REQUESTDISPATCHER CHE CHIAMA LA SERVLET WELCOME 

        rd.forward(request, response);  

    }else{  

        out.print(" Password Error!");  

        RequestDispatcher rd=request.getRequestDispatcher("/index.html");//inserire il METODO DELLA CLASSE INTERFACCIA                                                                                                                                                           //REQUESTDISPATCHER CHE CHAMA LA PAGINE HTML INDICATA   

        rd.include(request, response);                  

        }  

}

protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

// TODO Auto-generated method stub

doGet(request, response);

}

}
