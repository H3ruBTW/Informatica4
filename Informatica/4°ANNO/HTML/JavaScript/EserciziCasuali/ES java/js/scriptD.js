let val = 0;

let but = document.getElementById("b")
let tx = document.getElementById("tx")

but.addEventListener('click', function(){
    if(val===0)
    {
        tx.hidden = true
        but.innerHTML = "Scopri"
        val=1
    }
    else
    {
        tx.hidden = false
        but.innerHTML = "Nascondi"
        val=0
    }
})