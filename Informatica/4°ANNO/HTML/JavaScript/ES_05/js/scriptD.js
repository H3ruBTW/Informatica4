let textArea = document.getElementsByTagName("textarea");

function maiuscolo() {
    let testo = textArea[0].value
    testo = testo.toUpperCase()
    textArea[1].value = testo
}