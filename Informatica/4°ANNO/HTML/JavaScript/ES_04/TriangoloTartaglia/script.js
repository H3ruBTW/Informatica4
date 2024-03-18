
StampaPir = function(x)
{
    let spaziIn = "";
    let riga = "";

    for(let n=0; n<x; n++)
    {
        spaziIn = "";
        riga = "";

        for(let i=0; i<x-n; i++)
        {
            spaziIn = spaziIn + " ";
        }   

        for(let k=n; k>=0; k--)
        {
            riga += Math.round(Equazione(n, k)) + " ";
        }

        console.log(spaziIn + riga);
    }
}

Esponenziale = function(x)
{
    let ris = 1;

    for(let i=0; i<x-1; i++)
    {
        ris *= x-i;
    }

    return ris;
}

Equazione = function(x, y)
{
    return Esponenziale(x)/(Esponenziale(y)*Esponenziale(x-y));
}

let alt;
do
{
    alt = prompt("Si prega d'inserire un numero maggiore o uguale ad uno\nInserire l'altezza della piramide");
}while(alt < 1);

StampaPir(alt)

