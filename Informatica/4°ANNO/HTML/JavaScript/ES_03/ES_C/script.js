let d = false; //Variabile utilizzata per nel ciclo do-while per avvertire l'utente
let ris, oper; 

let num1 = prompt("Calcolatrice\nScrivere il primo numero");

if(Number.isNaN(num1)) //controllo variabile "Not a Number"
{
    console.error("Nel prompt è stato inserito un NaN");
}
else 
{
    //ciclo per vedere se l'utente inserisce un operatore disponibile
    do
    {
        if(d==false)
        {
            d=true;
        }
        else
        {
            alert("Hai inserito un operatore non esistente!");
        }

        oper = prompt("Inserire l'operatore\nOpzioni:\n+(addizione)|-(sottrazione)|*(moltiplicazione)|/(divisione)|**(potenza)");
    
    }while(oper!="+" && oper!="-" && oper!="*" && oper!="/" && oper!="**");
}

let num2 = prompt("Calcolatrice\nScrivere il secondo numero");

if(Number.isNaN(num2)) //controllo variabile "Not a Number"
{
    console.error("Nel prompt è stato inserito un NaN");
}
else
{
    switch(oper)
    {
        case "+":
            ris = (num1 * 1) + (num2 * 1);
            console.log(num1 + " + " + num2 + " = " + ris);
            break;

        case "-":
            ris = num1 - num2;
            console.log(num1 + " - " + num2 + " = " + ris);
            break;

        case "*":
            ris = num1 * num2;
            console.log(num1 + " * " + num2 + " = " + ris);
            break;

        case "/":
            if(num1==0 || num2==0)
            {
                console.error("Impossibile dividere per 0");
            }
            else
            {
                ris = num1 / num2;
                console.log(num1 + " / " + num2 + " = " + ris);
            }
            break;

        case "**":
            if(num1==0 && num2==0)
            {
                console.log("Forma indeterminata");
                break;
            }

            if(num1==0)
                ris=0;
            else
            {
                ris=1;

                for(let i=0; i<num2; i++)
                {
                    ris*=num1;
                }
            }   

            console.log(num1 + " ^ " + num2 + " = " + ris);

            break;
    }
}