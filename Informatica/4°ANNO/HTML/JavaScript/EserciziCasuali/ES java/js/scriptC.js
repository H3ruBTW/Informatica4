let text = document.getElementById("tx")

text.addEventListener('focus', function(){
    text.setAttribute('class', 'hover')
})

text.addEventListener('blur', function(){
    text.setAttribute('class', 'clear')
})