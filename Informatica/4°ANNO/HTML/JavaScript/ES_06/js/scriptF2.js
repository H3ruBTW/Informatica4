let val = 0
let input1 = false
let input2 = false
let ver1 = false
let ver2 = false

let inp1 = document.getElementById("I1")
let inp2 = document.getElementById("I2")
let tx1 = document.getElementById("tx1")
let tx2 = document.getElementById("tx2")
let tx3 = document.getElementById("tx3")

tx1.hidden=true
tx2.hidden=true
tx3.hidden=true

inp1.addEventListener('input', function(){

    tx3.setAttribute('class', 'arancione bianco')

    if(inp1.value.length>=8 && passwordCor(inp1.value))
    {
        inp1.setAttribute('class', 'verde')
        tx3.hidden=true
        ver1 = true
    }
    else
    {
        inp1.setAttribute('class', 'arancione')
        tx3.hidden=false
        ver1 = false
    }

    input1 = true
})

inp1.addEventListener('blur', function(){

    tx3.setAttribute('class', 'rosso bianco')

    if(inp1.value.length>=8 && passwordCor(inp1.value))
    {
        inp1.setAttribute('class', 'verde')
        tx3.hidden=true
    }
    else
    {
        if(input1)
        {
            inp1.setAttribute('class', 'rosso')
            tx3.hidden=false
        }
    }
})

inp1.addEventListener('focus', function(){
    if(!ver1 && input1)
    {
        tx3.setAttribute('class', 'arancione bianco')
        inp1.setAttribute('class', 'arancione')
    }
})

inp2.addEventListener('input', function(){

    tx1.setAttribute('class', 'arancione bianco')

    if(inp1.value===inp2.value && inp1.value.length>=1)
    {
        tx1.hidden=true
        inp2.setAttribute('class', 'verde')
        ver2 = true
    }
    else
    {
        tx1.hidden=false
        inp2.setAttribute('class', 'arancione')
        ver2 = false
    }

    input2 = true
})

inp2.addEventListener('blur', function(){

    tx1.setAttribute('class', 'rosso bianco')

    if(inp1.value===inp2.value && inp1.value.length>=1)
    {
        tx1.hidden=true
        inp2.setAttribute('class', 'verde')
    }
    else
    {
        if(input2)
        {
            tx1.hidden=false
            inp2.setAttribute('class', 'rosso')
        }
    }
})

inp2.addEventListener('focus', function(){
    if(!ver2 && input2)
    {
        tx1.setAttribute('class', 'arancione bianco')
        inp2.setAttribute('class', 'arancione')
    }
})

setInterval(function(){
    if(ver1 == true && ver2 == true)
    {
        tx2.hidden = false
    }
    else
    {
        tx2.hidden = true
    }
}, 10)
    


function passwordCor(password){
    let regexMaiuscole = /[A-Z]/;
    let regexNumeri = /[0-9]/;
    let regexCaratteriSpeciali = /[!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]+/;

    return regexMaiuscole.test(password) && regexNumeri.test(password) && regexCaratteriSpeciali.test(password);
}