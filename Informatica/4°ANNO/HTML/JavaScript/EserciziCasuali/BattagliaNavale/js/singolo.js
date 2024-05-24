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

        play.addEventListener("click", function(){
        
            if(inizio === true)
            {
                if(this.getAttribute("data-value") == "0")
                {
                    this.innerHTML = "◉"
                    this.setAttribute("data-value", "1")
                    matrice[this.getAttribute("data-n")]=1
                    nNavi--
                }
                else
                {
                    this.innerHTML = "◎"
                    this.setAttribute("data-value", "0")
                    matrice[this.getAttribute("data-n")]=0
                    nNavi++
                }
                aggiornaH3()
            }
            else
            {

            }
        })
    })

    
})

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
                aggiornaTh(i)
            }

            inizializzazioneBot()
        }
        else
        {
            /* FARE DIV ABSOLUTE CON AVVERTIMENTO CHE SCOMPARE DOPO POCHI SECONDI */
            alert("HAI INSERITO TROPPE O TROPPO POCHE NAVI")
        }
    }
    else
    {

    }
})

let posis = document.querySelectorAll('#pos')

function aggiornaH3(){
    h3.innerHTML = "NUMERO DI NAVI DA INSERIRE: " + nNavi
}

function aggiornaTh(n){
    switch(posis[n].getAttribute("data-value")){
        case "0":
            posis[n].innerHTML = "◎"
            break
        case "1":
            posis[n].innerHTML = "◉"
            break
        case "2":
            posis[n].innerHTML = "X"
            break
        case "3":
            posis[n].innerHTML = "O"
            break
    }
}

let matriceBot = [100]

matriceBot = 0

function inizializzazioneBot(){
    for(let i=0; i<5; i++)
    {
        //NUMERI CASUALI BOT
        let num


    }
}