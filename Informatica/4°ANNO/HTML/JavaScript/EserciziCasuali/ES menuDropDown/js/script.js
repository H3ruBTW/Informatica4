let menu = document.getElementById("menu")
let con = document.getElementById("content")
let but = document.getElementById("img")
let but2 = document.getElementById("text")
let img = document.getElementById("image")
let val = 0;
let val2 = 0;

but2.setAttribute("src", "img/icons8-doppio-giù-100.png")

menu.hidden=true;
menu2.hidden=true;

but.addEventListener("click", function(){

    if(val===0)
    {
        menu.hidden = false
        val=1
    }
    else
    {
        menu.hidden = true
        val=0
    }
})

but2.addEventListener('click', function(){
    if(val2===0)
    {
        menu2.hidden=false
        img.setAttribute('src', "img/icons8-doppio-sù-100.png")
        val2=1
    }
    else
    {
        menu2.hidden=true
        img.setAttribute('src', "img/icons8-doppio-giù-100.png")        
        val2=0
    }
})

