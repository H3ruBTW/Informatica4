const Calcolo = {
    somma: (x,y) => {return `${x} + ${y} = ${(x*1)+(y*1)}`},
    sottrazione: (x,y) => {return `${x} - ${y} = ${x-y}`},
    moltiplicazione: (x,y) => {return `${x} * ${y} = ${x*y}`},
    divisione: (x,y) => {
        if(y!=0)
            return `${x} / ${y} = ${x/y}`

        console.log("LA PAROLA D'ORDINE è UNA SOLA: NON PUOI DIVIDERE PER 0");
    },
    potenza: (x,y) => {return `${x} ^ ${y} = ${x**y}`}
}

let d=false;

let num1 = prompt("Calcolatrice\nScrivere il primo numero");

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

let num2 = prompt("Calcolatrice\nScrivere il secondo numero");

if(isNaN(num1+num2))
{
    console.error("Hai inserito un NaN");
}
else
{
    switch(oper)
    {
    case "+":
        console.log(Calcolo.somma(num1, num2));
        break;

    case "-":
        console.log(Calcolo.sottrazione(num1, num2));
        break;

    case "*":
        console.log(Calcolo.moltiplicazione(num1, num2));
        break;

    case "/":
        console.log(Calcolo.divisione(num1, num2));
        break;

    case "**":
        console.log(Calcolo.potenza(num1, num2));
        break;
    }
}