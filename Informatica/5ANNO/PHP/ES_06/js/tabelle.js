let buttons = document.querySelectorAll("th button")

buttons.forEach(button => {
    button.addEventListener("click", function(){
        button.innerHTML = "CONFIRM UPDATE"

        let id = button.getAttribute("id")

        //prende tutte le righe tranne quella col bottone
        let row = document.querySelectorAll("tr#" + id + " th:not(:has(button))")

        row.forEach(cell => {
            
        });
    })
});