let box = document.getElementById("box")
box.hidden = true

let button = document.getElementById("button")
button.addEventListener("click", function(){
    box.hidden = false
    button.disabled = true
})

let button2 = document.getElementById("button3")
button2.addEventListener("click", function(){
    box.hidden = true
    button.disabled = false
})