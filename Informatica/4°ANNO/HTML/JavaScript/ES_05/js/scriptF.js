let tab = document.createElement("table")
let main = document.querySelector("main")

for(let i=1; i<=10; i++)
{
    let riga = document.createElement("tr")
    for(let j=1; j<=10; j++)
    {
        let colonna = document.createElement("td")
        colonna.textContent = i*j
        if(i%2===1)
            colonna.setAttribute('class', 'evidenziato')
        riga.appendChild(colonna)
    }
    tab.appendChild(riga)
}

main.appendChild(tab)

