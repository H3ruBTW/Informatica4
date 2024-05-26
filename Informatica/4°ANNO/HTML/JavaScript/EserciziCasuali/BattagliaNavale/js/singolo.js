let div_esci = document.getElementById("uscire")

div_esci.hidden = true

/* USCIRE */
let bot_esci = document.getElementById("esci")
let bot_conf = document.getElementById("NO")
let body = document.getElementById("body")

bot_esci.addEventListener("click", function(){
    div_esci.hidden = false
    body.setAttribute("class", "sfocato")
})

bot_conf.addEventListener("click", function(){
    div_esci.hidden = true
    body.setAttribute("class", "clear")
})

/* PRE-PARTITA */
let inizio = true
let matrice = [100]
let nNavi = 5

let plays = document.querySelectorAll('#gioca')

plays.forEach(play => {

    document.addEventListener("DOMContentLoaded", function(){
        play.innerHTML = "◎"

        play.addEventListener("click", funzione)
    })

    
})

function funzione(event){
    
    const elemento = event.target

    if(inizio === true)
    {
        if(elemento.getAttribute("data-value") == "0")
        {
            elemento.setAttribute("data-value", "1")
            aggiornaThGioc(elemento.getAttribute("data-n"))
            matrice[elemento.getAttribute("data-n")]=1
            nNavi--
        }
        else
        {
            elemento.setAttribute("data-value", "0")
            aggiornaThGioc(elemento.getAttribute("data-n"))
            matrice[elemento.getAttribute("data-n")]=0
            nNavi++
        }
        aggiornaH3()
    }
    else
    {
        if(elemento.getAttribute("data-value") == "0")
        {
            elemento.setAttribute("data-value", "1")
            aggiornaThGioc(elemento.getAttribute("data-n"))
            matrice[elemento.getAttribute("data-n")]=1
            nNavi--
        }
        else
        {
            elemento.setAttribute("data-value", "0")
            aggiornaThGioc(elemento.getAttribute("data-n"))
            matrice[elemento.getAttribute("data-n")]=0
            nNavi++
        }
        aggiornaH3()
    }
}

let h3 = document.getElementById("nNavi")

document.addEventListener("DOMContentLoaded", function(){
    for (let i = 0; i < 100; i++) {
        matrice[i] = plays[i].getAttribute("data-value")
        plays[i].setAttribute("data-n", i)
        posis[i].setAttribute("data-n", i)
    }

    aggiornaH3()
})

let Confirm = document.getElementById("bottone")
let tab2 = document.getElementById("tab2")
tab2.hidden = true

Confirm.addEventListener("click", function(){
    if(inizio === true)
    {
        if(nNavi==0)
        {
            tab2.hidden = false
            inizio = false

            for (let i = 0; i < 100; i++) {
                posis[i].setAttribute("data-value", matrice[i])
                aggiornaThBot(i)
            }

            inizializzazioneBot()

            nNavi = 1
            aggiornaH3()

            resetGrid()
        }
        else
        {
            /* FARE DIV ABSOLUTE CON AVVERTIMENTO CHE SCOMPARE DOPO POCHI SECONDI */
            alert("HAI INSERITO TROPPE O TROPPO POCHE NAVI")
        }
    }
    else
    {
        if(nNavi==0)
        {
            turnoGioc()
        }
        else
        {
            /* FARE DIV ABSOLUTE CON AVVERTIMENTO CHE SCOMPARE DOPO POCHI SECONDI */
            alert("HAI INSERITO TROPPE O TROPPO POCHE NAVI")
        }
    }
})

let posis = document.querySelectorAll('#pos')

function aggiornaH3(){
    if(inizio===true)
        h3.innerHTML = "NUMERO DI NAVI DA INSERIRE: " + nNavi
    else
        h3.innerHTML = "NUMERO DI NAVI DA ATTACCARE: " + nNavi
}

/* AGGIORNA LA TABELLA CON LE TUE NAVI; ATTACCO BOT*/
function aggiornaThBot(n){
    switch(posis[n].getAttribute("data-value")){
        case "0":
            posis[n].innerHTML = "◎"
            break
        case "1":
            posis[n].innerHTML = "◉"
            break
        case "2":
            posis[n].setAttribute("class", "acqua")
            posis[n].innerHTML = "~"
            break
        case "3":
            posis[n].setAttribute("class", "nave")
            posis[n].innerHTML = "X"
            break
    }
}

/* AGGIORNA LA TABELLA CON LE NAVI DA ATTACCARE */
function aggiornaThGioc(n){
    switch(plays[n].getAttribute("data-value")){
        case "0":
            plays[n].innerHTML = "◎"
            break
        case "1":
            plays[n].innerHTML = "◉"
            break
        case "2":
            plays[n].setAttribute("class", "acqua")
            plays[n].innerHTML = "~"
            plays[n].removeEventListener("click", funzione)
            plays[n].setAttribute("id", "disabled")
            break
        case "3":
            plays[n].setAttribute("class", "nave")
            plays[n].innerHTML = "X"
            plays[n].removeEventListener("click", funzione)
            plays[n].setAttribute("id", "disabled")
            break
    }
}

let matriceBot = new Array(100).fill(0)

function inizializzazioneBot(){
    for(let i=0; i<5; i++)
    {
        //NUMERI CASUALI BOT
        let num = Math.floor(Math.random()*100)

        if(matriceBot[num]!=1)
        {
            matriceBot[num]=1
        }
        else
        {
            i--
        }
    }

    console.log(matriceBot)
}

function resetGrid(){
    for(let i=0; i<100; i++){
        plays[i].setAttribute("data-value", 0)
        aggiornaThGioc(i)
    }
}

let h3TurnoG = document.getElementById("turnoGioc")
let h3TurnoB = document.getElementById("turnoBOT")

h3TurnoB.style.opacity=0

function turnoGioc(){
    for (let i = 0; i < 100; i++) {
        
        if (plays[i].getAttribute("data-value") == "1") {
            matriceBot[i] += 2
            plays[i].setAttribute("data-value", matriceBot[i])
            console.log(plays[i].getAttribute("data-value"))
            aggiornaThGioc(i)

            if (plays[i].getAttribute("data-value") == "2") {
                Confirm.disabled = true
                h3TurnoB.style.opacity = 1
                h3TurnoG.style.opacity = 0
                h3.opacity=0
                setTimeout(turnoBot, 1500)
            }

            nNavi = 1
            aggiornaH3()

            break;
        }
    }
}

async function turnoBot(){
    await giocoBot()

    Confirm.disabled = false
    h3TurnoB.style.opacity = 0
    h3TurnoG.style.opacity = 1
    h3.opacity=1
}

async function giocoBot(){

    let ver = true
    let num = 0

    do{
        num = Math.floor(Math.random()*100)
        if(posis[num].getAttribute("data-value")<2)
        {
            ver=true
        }
        else
        {
            ver=false
        }
    }while(!ver)

    posis[num].setAttribute("data-value", posis[num].getAttribute("data-value")*1+2*1)
    aggiornaThBot(num)
    console.log(posis[num].getAttribute("data-value"))

    if(posis[num].getAttribute("data-value")==3)
    {
        setTimeout(giocoBot, 1500)
    }
}
