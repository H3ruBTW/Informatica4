document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('form');
    const submitButton = document.getElementById('button'); 
    const inputs = form.querySelectorAll('input[pattern], input[required]');

    // Funzione per controllare la validità dei campi
    function valida() {
        inputs.forEach(input => {
            if (input.hasAttribute('required') && input.value.trim() === "") {
                input.setAttribute('class', 'rosso'); 
            } else if (!input.checkValidity()) {
                input.setAttribute('class', 'rosso'); 
            } else {
                if (input.classList.contains('rosso')) {
                    input.setAttribute('class', ''); 
                }
            }
        });
    }

    // Gestore dell'evento click sul pulsante di submit
    submitButton.addEventListener('click', function(event) {
        valida();
    });
});