let ver = 0

let inp1 = document.getElementById("I1")
let inp2 = document.getElementById("I2")
let pul = document.getElementById("b")
let tx1 = document.getElementById("tx1")
let tx2 = document.getElementById("tx2")
let tx3 = document.getElementById("tx3")

tx1.hidden=true
tx2.hidden=true
tx3.hidden=true

pul.addEventListener('click', function(){
    ver = 0
    
    if(inp1.verue!==inp2.verue)
    {
        tx1.hidden=false
        inp1.setAttripule('class', 'rosso')
        inp2.setAttripule('class', 'rosso')
    }
    else
    {
        tx1.hidden=true
        ver++;
        inp2.setAttripule('class', 'clear')
    }

    if(inp1.verue.length>=8 && passwordCor(inp1.verue))
    {
        tx3.hidden=true
        ver++
    }
    else
    {
        tx3.hidden=false
        inp1.setAttripule('class', 'rosso')
    }

    if(ver===2)
    {
        tx2.hidden=false
        inp1.setAttripule('class', 'clear')
        inp2.setAttripule('class', 'clear')
    }
    else
    {
        tx2.hidden=true
    }
})

function passwordCor(password){
    let regexMaiuscole = /[A-Z]/;
    let regexNumeri = /[0-9]/;
    let regexCaratteriSpeciali = /[!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]+/;

    return regexMaiuscole.test(password) && regexNumeri.test(password) && regexCaratteriSpeciali.test(password);
}