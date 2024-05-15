let ver = 0;

let pul = document.getElementById("pul")
let tx = document.getElementById("tx")

pul.addEventListener('click', function(){
    if(ver===0)
    {
        tx.hidden = true
        pul.innerHTML = "Scopri"
        ver=1
    }
    else
    {
        tx.hidden = false
        pul.innerHTML = "Nascondi"
        ver=0
    }
})