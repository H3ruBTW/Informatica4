let buttons = document.querySelectorAll("th button")

buttons.forEach(button => {
    button.addEventListener("click", function(){
        button.innerHTML = "CONFIRM UPDATE"

        let id = button.getAttribute("id")

        //prende tutte le righe tranne quella col bottone
        let row = document.querySelectorAll("tr#" + CSS.escape(id) + " th")

        row.forEach(cell => {
            //no button cells
            let nbcells = []

            if(!cell.querySelector("button")){
                nbcells.push(cell);
            }

            console.log(nbcells)

            nbcells.forEach(nbcell => {
                let text = nbcell.textContent

                nbcell.innerHTML = "<input type=\"text\" >"
            });
        });
    })
});