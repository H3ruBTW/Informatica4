let val = 0

let inp1 = document.getElementById("I1")
let inp2 = document.getElementById("I2")
let but = document.getElementById("b")
let tx1 = document.getElementById("tx1")
let tx2 = document.getElementById("tx2")
let tx3 = document.getElementById("tx3")

tx1.hidden=true
tx2.hidden=true
tx3.hidden=true

but.addEventListener('click', function(){
    val = 0
    
    if(inp1.value!==inp2.value)
    {
        tx1.hidden=false
        inp1.setAttribute('class', 'rosso')
        inp2.setAttribute('class', 'rosso')
    }
    else
    {
        tx1.hidden=true
        val++;
        inp2.setAttribute('class', 'clear')
    }

    if(inp1.value.length>=8 && passwordCor(inp1.value))
    {
        tx3.hidden=true
        val++
    }
    else
    {
        tx3.hidden=false
        inp1.setAttribute('class', 'rosso')
    }

    if(val===2)
    {
        tx2.hidden=false
        inp1.setAttribute('class', 'clear')
        inp2.setAttribute('class', 'clear')
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