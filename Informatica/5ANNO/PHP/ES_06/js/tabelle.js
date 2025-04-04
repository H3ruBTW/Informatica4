/*
* PER OGNI PULSANTE NELLA TABELLA 2 SI ASCOLTA L'EVENTO CLICK PER TRASFORMARE TUTTO IN CASELLE
* MODIFICABILI PER POI SALVARE NEGLI HIDDEN FORM ED EFFETTUARNE IL POST
*/
if(window.tab == 2){
    let buttons = document.querySelectorAll("td button");

    buttons.forEach(button => {
        button.addEventListener("click", function Handle(event){

            let index = button.id

            button.innerHTML = "CONFIRM UPDATE"

            event.target.removeEventListener("click", Handle)

            let texts = document.querySelectorAll("tr#" + CSS.escape(index) + " td")

            for(let j=0; j<texts.length-1; j++){
                if(j==6){continue}

                let text = texts[j].textContent

                texts[j].innerHTML = "<textarea cols=\"12\" rows=\"5\" style=\"resize:none\">" + text + "</textarea>";
                
            }

            button.addEventListener("click", function Handle2(){
                let texts = document.querySelectorAll("tr#" + CSS.escape(index) + " td textarea")

                let inputs = document.querySelectorAll("tr#" + CSS.escape(index) + " td form input")

                for(let j=0; j<texts.length; j++){
                    let text = texts[j].value
    
                    inputs[j].setAttribute("value", text)
                }

                let thisform = document.getElementById("mod" + index)

                thisform.submit()
            })
               
        })
    });

    let keys = document.querySelectorAll("tr#keys th")

    keys.forEach (key => {
        if(key.innerHTML != "Modifica"){
            key.addEventListener("click", function(){
                let url

                
                
                if(window.di == "i" && window.orderby == key.innerHTML){
                    url = "Pannello.php?id=2&orderby=" + key.innerHTML + "&di=d"               
                } else {
                    url = "Pannello.php?id=2&orderby=" + key.innerHTML + "&di=i"  
                }

                window.location.href = url
            })
        }
    })
}




