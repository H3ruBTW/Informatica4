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
        play.innerHTML = "O"

        play.addEventListener("click", function(){
        
            if(inizio === true)
            {
                if(this.getAttribute("data-value") == "0")
                {
                    this.innerHTML = "X"
                    this.setAttribute("data-value", "1")
                    matrice[this.getAttribute("data-n")]=1
                    nNavi--
                }
                else
                {
                    this.innerHTML = "O"
                    this.setAttribute("data-value", "0")
                    matrice[this.getAttribute("data-n")]=0
                    nNavi++
                }
                h3.innerHTML = "NUMERO DI NAVI DA INSERIRE: " + nNavi
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
    }

    h3.innerHTML = "NUMERO DI NAVI DA INSERIRE: " + nNavi
})

let Confirm = document.getElementById("bottone")
let tab2 = document.getElementById("tab2")
tab2.hidden = true

Confirm.addEventListener("click", function(){
    if(nNavi==0)
    {
        Confirm.hidden = true
        tab2.hidden = false
        inizio = false
    }
    else
    {
        /* FARE DIV ABSOLUTE CON AVVERTIMENTO CHE SCOMPARE DOPO POCHI SECONDI */
        alert("HAI INSERITO TROPPE O TROPPO POCHE NAVI")
    }
})