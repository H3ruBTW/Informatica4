let body = document.getElementById("body")

/* DIV SCELTA */
let div_tip = document.getElementById("tipo_di_gioco")

div_tip.hidden = true

/* BOTTONE GIOCA ORA */
let Gioca = document.getElementById("button") 

Gioca.addEventListener("click", function(){
    body.setAttribute("class", "sfocato")
    div_tip.hidden = false
})

/* BOTTONE X */
let X = document.getElementById("X")

X.addEventListener("click", function(){
    body.setAttribute("class", "clear")
    div_tip.hidden = true
})