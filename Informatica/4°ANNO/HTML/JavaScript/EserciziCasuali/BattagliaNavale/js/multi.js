let div_esci = document.getElementById("uscire")
let div_poche = document.getElementById("pocheNavi")
let div_troppe = document.getElementById("troppeNavi")

div_esci.hidden = true
div_poche.style.opacity = 0
div_troppe.style.opacity = 0

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
        thG1[i].setAttribute("data-gioc", 0)
        thG2[i].setAttribute("data-gioc", 0)
        turnoGioc1 = true
        aggiornaTh(i)
        turnoGioc1 = false
        aggiornaTh(i)
    }
})

function aggiornaTh(n){
    if(inizio)
    {
        if(turnoGioc1)
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
        if(turnoGioc1)
        {
            switch(thG1[n].getAttribute("data-gioc")){
                case "0":
                    thG1[n].innerHTML = "◎"
                    break
                case "1":
                    thG1[n].innerHTML = "◉"
                    break
                case "2":
                    thG1[n].setAttribute("class", "acqua")
                    thG1[n].innerHTML = "~"
                    thG1[n].removeEventListener("click", funzioneG1)
                    thG1[n].setAttribute("id", "disabled")
                    break
                case "3":
                    thG1[n].setAttribute("class", "nave")
                    thG1[n].innerHTML = "X"
                    thG1[n].removeEventListener("click", funzioneG1)
                    thG1[n].setAttribute("id", "disabled")
                    break
            }
        }
        else
        {
            switch(thG2[n].getAttribute("data-gioc")){
                case "0":
                    thG2[n].innerHTML = "◎"
                    break
                case "1":
                    thG2[n].innerHTML = "◉"
                    break
                case "2":
                    thG2[n].setAttribute("class", "acqua")
                    thG2[n].innerHTML = "~"
                    thG2[n].removeEventListener("click", funzioneG2)
                    thG2[n].setAttribute("id", "disabled")
                    break
                case "3":
                    thG2[n].setAttribute("class", "nave")
                    thG2[n].innerHTML = "X"
                    thG2[n].removeEventListener("click", funzioneG2)
                    thG2[n].setAttribute("id", "disabled")
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

function aggiornaH3(){

    h3NG1.innerHTML = "POSIZIONA LE NAVI: " + nNavi

    h3NG2.innerHTML = "POSIZIONA LE NAVI: " + nNavi2
    
}

/* DIV GIOCATORI */
let div_g1 = document.getElementById("g1")
let div_g2 = document.getElementById("g2")

let buttonG1 = document.getElementById("bg1")
let buttonG2 = document.getElementById("bg2")

/* PRE-PARTITA */
let inizio = true
const predefinitoNavi = 10
let nNavi = predefinitoNavi
let nNavi2 = predefinitoNavi
let nNaviG1 = nNavi
let nNaviG2 = nNavi
let turnoGioc1 = true

document.addEventListener("DOMContentLoaded", function(){
    turnoG1()
    turnoGioc1 = true
    aggiornaH3()
    turnoGioc1 = false
    aggiornaH3()
    turnoGioc1 = true

    thG1.forEach(element => {
        element.addEventListener("click", funzioneG1)
    });

    thG2.forEach(element => {
        element.addEventListener("click", funzioneG2)
    });
})

function funzioneG1(event){
    const elemento = event.target
    
    if(turnoGioc1)
    {
        if(inizio)
        {
            if(elemento.getAttribute("data-val") == "0")
            {
                elemento.setAttribute("data-val", "1")
                aggiornaTh(elemento.getAttribute("data-n"))
                nNavi--
            }
            else
            {
                elemento.setAttribute("data-val", "0")
                aggiornaTh(elemento.getAttribute("data-n"))
                nNavi++
            }
            aggiornaH3()
        }
        else
        {
            if(elemento.getAttribute("data-gioc") == "0")
            {
                elemento.setAttribute("data-gioc", "1")
                aggiornaTh(elemento.getAttribute("data-n"))
                nNavi--
            }
            else
            {
                elemento.setAttribute("data-gioc", "0")
                aggiornaTh(elemento.getAttribute("data-n"))
                nNavi++
            }
            aggiornaH3()
        }
    }
}

function funzioneG2(event){
    const elemento = event.target
    
    if(!turnoGioc1)
    {
        if(inizio)
        {
            if(elemento.getAttribute("data-val") == "0")
            {
                elemento.setAttribute("data-val", "1")
                aggiornaTh(elemento.getAttribute("data-n"))
                nNavi2--
            }
            else
            {
                elemento.setAttribute("data-val", "0")
                aggiornaTh(elemento.getAttribute("data-n"))
                nNavi2++
            }
            aggiornaH3()
        }
        else
        {
            if(elemento.getAttribute("data-gioc") == "0")
            {
                elemento.setAttribute("data-gioc", "1")
                aggiornaTh(elemento.getAttribute("data-n"))
                nNavi2--
            }
            else
            {
                elemento.setAttribute("data-gioc", "0")
                aggiornaTh(elemento.getAttribute("data-n"))
                nNavi2++
            }
            aggiornaH3()
        }
    }
}


function turnoG1(){
    h3NG2.style.opacity = 0
    h3TG2.style.opacity = 0
    buttonG2.disabled = true
    buttonG2.style.opacity = 0
    div_g2.setAttribute("class", "turnoAvv")
    thG2.forEach(th => {
        th.setAttribute("id", "disabled")
    });

    h3NG1.style.opacity = 1
    h3TG1.style.opacity = 1
    buttonG1.disabled = false
    buttonG1.style.opacity = 1
    div_g1.setAttribute("class", "none")
    thG1.forEach(th => {
        th.setAttribute("id", "gioca")
    });
}

function turnoG2(){
    h3NG1.style.opacity = 0
    h3TG1.style.opacity = 0
    buttonG1.disabled = true
    buttonG1.style.opacity = 0
    div_g1.setAttribute("class", "turnoAvv")
    thG1.forEach(th => {
        th.setAttribute("id", "disabled")
    });

    h3NG2.style.opacity = 1
    h3TG2.style.opacity = 1
    buttonG2.disabled = false
    buttonG2.style.opacity = 1
    div_g2.setAttribute("class", "none")
    thG2.forEach(th => {
        th.setAttribute("id", "gioca")
    });
}

buttonG1.addEventListener("click", function(){
    if(inizio)
        {
            if(nNavi==0)
            {   let ver = false
                
                if(inizio)
                {
                    inizio=false
                    ver = true
                }
                
        
                for (let i = 0; i < 100; i++) {
                    aggiornaTh(i)      
                }
                
                if(ver)
                    inizio=true

                turnoGioc1 = false
                turnoG2()
            }
            else
            {
                if(nNavi > 0)
                {
                    riavviaAnimazione(div_poche, "animazioneNavi");
                }
                else
                {
                    riavviaAnimazione(div_troppe, "animazioneNavi");
                }
            }
        }
        else
        {
            if(nNavi==0)
            {   
                let ver = turnoGioco()
                
                if(ver)
                {
                    turnoGioc1 = false
                    turnoG2()
                }

                nNavi = 1
                nNavi2 = 1
                
            }
            else
            {
                if(nNavi > 0)
                {
                    riavviaAnimazione(div_poche, "animazioneNavi");
                }
                else
                {
                    riavviaAnimazione(div_troppe, "animazioneNavi");
                }
            }
        }
})

buttonG2.addEventListener("click", function(){
    if(inizio)
    {
        if(nNavi2==0)
        {   
            inizio=false
    
            for (let i = 0; i < 100; i++) {
                aggiornaTh(i)      
            }
    
            turnoGioc1 = true
            turnoG1()
            nNavi = 1
            nNavi2 = 1
            aggiornaH3()

            let lav

            for(let i=0; i<100; i++)
            {
                lav = thG1[i].getAttribute("data-val")
                thG1[i].setAttribute("data-val", thG2[i].getAttribute("data-val"))
                thG2[i].setAttribute("data-val", lav)
            }

            console.log(thG1)
            console.log(thG2)
        }
        else
        {
            if(nNavi2 > 0)
            {
                riavviaAnimazione(div_poche, "animazioneNavi");
            }
            else
            {
                riavviaAnimazione(div_troppe, "animazioneNavi");
            }
        }
    }
    else
    {
        if(nNavi2==0)
        {   
            let ver = turnoGioco()
            
            if(ver)
            {
                turnoGioc1 = true
                turnoG1()
            }
            
            nNavi = 1
            nNavi2 = 1
        }
        else
        {
            if(nNavi2 > 0)
            {
                riavviaAnimazione(div_poche, "animazioneNavi");
            }
            else
            {
                riavviaAnimazione(div_troppe, "animazioneNavi");
            }
        }
    }
    
})

function riavviaAnimazione(elemento, classeAnimazione) {
    elemento.classList.remove(classeAnimazione);
    void elemento.offsetWidth; // Forza il reflow per "resettare" l'animazione
    elemento.classList.add(classeAnimazione);
}

function turnoGioco(){
    if(turnoGioc1)
    {
        for (let i = 0; i < 100; i++) {
        
            if (thG1[i].getAttribute("data-gioc") == "1") {

                thG1[i].setAttribute("data-gioc", thG1[i].getAttribute("data-val")*1+2)
                aggiornaTh(i)

                if(thG1[i].getAttribute("data-gioc")==2)
                {
                    return true
                }
                else
                {
                    controlloDiGioco()
                    nNavi2--
                    return false
                }
            }
        }
    }
    else
    {
        for (let i = 0; i < 100; i++) {
        
            if (thG2[i].getAttribute("data-gioc") == "1") {

                thG2[i].setAttribute("data-gioc", thG2[i].getAttribute("data-val")*1+2)
                aggiornaTh(i)

                if(thG2[i].getAttribute("data-gioc")==2)
                {
                    return true
                }
                else
                {
                    nNavi--
                    controlloDiGioco()
                    return false
                }
            }
        }
    }
}

/* VITTORIA + CONTROLLI */
let div_perso = document.getElementById("perso")
let div_vinto = document.getElementById("vinto")
div_perso.hidden = true
div_vinto.hidden = true

function controlloDiGioco(){

    if(nNavi==0)
    {
        setTimeout(function(){
            div_vinto.hidden = false
            body.setAttribute("class", "sfocato")
        },2000)
    }
    else if(nNavi2==0)
    {
        setTimeout(function(){
            div_perso.hidden = false
            body.setAttribute("class", "sfocato")
        },2000)
    }
}