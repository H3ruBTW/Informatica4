let spaziIn = "";
let spaziMez = "";
let asterischi = "*";
let alt;

do
{
    alt = prompt("Si prega d'inserire un numero maggiore o uguale ad uno\nInserire l'altezza della piramide");
}while(alt < 1);

for(let i=1; i<alt; i++)
    spaziIn = spaziIn + " ";

console.log(spaziIn + "*");

for(let i=1; i<alt-1; i++)
{
    spaziIn = "";
    spaziMez = " ";

    for(let j=1; j<alt-i; j++)
        spaziIn = spaziIn + " ";

    for(let j=1; j<i; j++)
        spaziMez = spaziMez + "  ";

    console.log(spaziIn + "*" + spaziMez + "*");
}

if(alt>1)
{
    for(let i=1; i<alt; i++)
        asterischi = asterischi + "**";
}

console.log(asterischi);

