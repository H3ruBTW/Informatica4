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

            for(let j=0; j<texts.length-2; j++){
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

    //Ordinamento
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

                window.location.href = url + "&pag=" + window.pag
            })
        }
    })

    let delButtons = document.querySelectorAll("td input[type^=\"button\"]")
    
    delButtons.forEach(dbtn => {
        dbtn.addEventListener("click", function Handle3(event){
            dbtn.value = "CONFIRM\nDELETE"

            dbtn.setAttribute("type", "submit")

            event.preventDefault()

            event.target.removeEventListener("click", Handle3)
        })
    });

    let displaybox = document.getElementById("displaybox")

    if(displaybox.getAttribute("class") != ""){
        displaybox.hidden = false
    }
}

if(window.tab == 3){
    let displaybox = document.getElementById("displaybox")

    let buttons = document.querySelectorAll("td button");

    buttons.forEach(button => {
        button.addEventListener("click", function Handle(event){

            let index = button.id

            button.innerHTML = "CONFIRM UPDATE"

            event.target.removeEventListener("click", Handle)

            let texts = document.querySelectorAll("tr#" + CSS.escape(index) + " td")

            for(let j=0; j<texts.length-2; j++){
                if(j==6){continue}

                let text = texts[j].textContent
                let olddata = texts[j].dataset.old

                texts[j].innerHTML = "<textarea data-old=\"" + olddata + "\" cols=\"12\" rows=\"5\" style=\"resize:none\">" + text + "</textarea>";
                
            }

            button.addEventListener("click", function Handle2(event){
                let displaybox = document.getElementById("displaybox")
                let textareas = document.querySelectorAll("tr#" + CSS.escape(index) + " td textarea")
                let texts = document.querySelectorAll("tr#" + CSS.escape(index) + " td")

                let inputs = document.querySelectorAll("tr#" + CSS.escape(index) + " td form input")

                for(let j=0; j<textareas.length; j++){
                    let text = textareas[j].value
    
                    inputs[j].value = text
                }

                let thisform = document.getElementById("mod" + index)

                let dataform = new FormData(thisform)

                document.body.classList.add("loading");
                document.getElementById("loader").style.display = "block";

                fetch(
                    "updatetable.php", 
                    {method: "POST", body: dataform}
                ).then(response => {
                    displaybox.className = ""
                    void displaybox.offsetWidth //RESETTA L'ANIMAZIONE
                    if (!response.ok) {
                        return response.text().then(text => { throw new Error(text) })
                    }
                    return response.text() //RICEVE I DATI OTTENUTI
                }).then(data => {
                    document.body.classList.remove("loading");
                    document.getElementById("loader").style.display = "none";

                    displaybox.querySelector("p").textContent = data
                    displaybox.hidden = false
                    displaybox.classList.add("succ")

                    for(let j=0; j<textareas.length; j++){

                        let text = textareas[j].value
                        if(j<6){
                            texts[j].innerHTML = text
                            texts[j].dataset.old = text
                        } else {
                            texts[j+1].innerHTML = text
                            texts[j+1].dataset.old = text
                        }
                            
                    }

                }).catch(error =>{
                    document.body.classList.remove("loading");
                    document.getElementById("loader").style.display = "none";

                    displaybox.querySelector("p").textContent = error
                    displaybox.hidden = false
                    displaybox.classList.add("err")

                    textareas.forEach(textarea => {
                        textarea.value = textarea.dataset.old
                    });

                    for(let j=0; j<textareas.length; j++){

                        let text = textareas[j].value
                        if(j<6)
                            texts[j].innerHTML = text
                        else
                            texts[j+1].innerHTML = text
                    }
                })

                event.target.removeEventListener("click", Handle2)

                button.innerHTML = "UPDATE"

                event.target.addEventListener("click", Handle)
            })
               
        })
    });

    //Ordinamento
    let keys = document.querySelectorAll("tr#keys th")

    keys.forEach (key => {
        if(key.innerHTML != "Modifica"){
            key.addEventListener("click", function(){
                let url

                if(window.di == "i" && window.orderby == key.innerHTML){
                    url = "Pannello.php?id=3&orderby=" + key.innerHTML + "&di=d"               
                } else {
                    url = "Pannello.php?id=3&orderby=" + key.innerHTML + "&di=i"  
                }

                window.location.href = url + "&pag=" + window.pag
            })
        }
    })

    let delButtons = document.querySelectorAll("td input[type^=\"button\"]")
    
    delButtons.forEach(dbtn => {
        dbtn.addEventListener("click", function Handle3(event){
            dbtn.value = "CONFIRM\nDELETE"

            dbtn.setAttribute("type", "submit")

            event.preventDefault()

            event.target.removeEventListener("click", Handle3)
        })
    });

    if(displaybox.getAttribute("class") != ""){
        displaybox.hidden = false
    }
}