let inp1 = document.getElementById("I1")
let inp2 = document.getElementById("I2")
let but = document.getElementById("b")
let tx1 = document.getElementById("tx1")
let tx2 = document.getElementById("tx2")

tx1.hidden=true
tx2.hidden=true

but.addEventListener('click', function(){
    if(inp1.value!==inp2.value)
    {
        tx1.hidden=false
        tx2.hidden=true
    }
    else
    {
        tx1.hidden=true
        tx2.hidden=false
    }
})