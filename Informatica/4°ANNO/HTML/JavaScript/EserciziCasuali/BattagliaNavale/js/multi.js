let div_esci = document.getElementById("uscire")
/*let div_poche = document.getElementById("pocheNavi")
let div_troppe = document.getElementById("troppeNavi")*/

div_esci.hidden = true
/*div_poche.style.opacity = 0
div_troppe.style.opacity = 0*/

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

/* TH DEI RISPETTIVI GIOCATORI */
let thG1 = document.querySelectorAll('#g1 table tr th#gioca')
let thG2 = document.querySelectorAll('#g2 table tr th#gioca')

/* INIZIALIZZAZIONE TABELLE */
document.addEventListener("DOMContentLoaded", function(){
    for(let i=0; i<100; i++)
    {
        thG1[i].setAttribute("data-n", i)
        thG2[i].setAttribute("data-n", i)
        thG1[i].setAttribute("data-val", 0)
        thG2[i].setAttribute("data-val", 0)
        aggiornaTh(i, true)
        aggiornaTh(i, false)
    }
})

function aggiornaTh(n, turnoG1){
    if(inizio)
    {
        if(turnoG1)
        {
            switch(thG1[n].getAttribute("data-val")){
                case "0":
                    thG1[n].innerHTML = "◎"
                    break
                case "1":
                    thG1[n].innerHTML = "◉"
                    break
            }
        }
        else
        {
            switch(thG2[n].getAttribute("data-val")){
                case "0":
                    thG2[n].innerHTML = "◎"
                    break
                case "1":
                    thG2[n].innerHTML = "◉"
                    break
            }
        }
    }
    else
    {
        if(turnoG1)
        {
            switch(thG1[n].getAttribute("data-val")){
                case "0":
                case "1":
                    thG1[n].innerHTML = "◎"
                    break
                case "2":
                    thG1[n].setAttribute("class", "acqua")
                    thG1[n].innerHTML = "~"
                    break
                case "3":
                    thG1[n].setAttribute("class", "nave")
                    thG1[n].innerHTML = "X"
                    break
            }
        }
        else
        {
            switch(thG2[n].getAttribute("data-val")){
                case "0":
                case "1":
                    thG2[n].innerHTML = "◎"
                    break
                case "2":
                    thG2[n].setAttribute("class", "acqua")
                    thG2[n].innerHTML = "~"
                    break
                case "3":
                    thG2[n].setAttribute("class", "nave")
                    thG2[n].innerHTML = "X"
                    break
            }
        }
    }
}

/* H3 */
let h3NG1 = document.getElementById("h3g1")
let h3TG1 = document.getElementById("turnoG1")
let h3NG2 = document.getElementById("h3g2")
let h3TG2 = document.getElementById("turnoG2")

/* PRE-PARTITA */
let inizio = true
let nNavi = 10
let nNaviG1 = nNavi
let nNaviG2 = nNavi