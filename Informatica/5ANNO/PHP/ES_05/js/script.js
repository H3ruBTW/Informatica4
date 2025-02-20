let box = document.getElementById("box")
box.hidden = true

let button = document.getElementById("button")
button.addEventListener("click", function(){
    if(box.hidden == true){
        box.hidden = false
        button.disabled = true
    }
})