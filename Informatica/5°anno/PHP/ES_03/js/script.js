document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('form');
    const submit = document.getElementById('button'); 
    const inputs = form.querySelectorAll('input[pattern], input[required]');

    function valida() {
        inputs.forEach(input => {
            if (input.hasAttribute('required') && input.value.trim() === "") {
                input.setAttribute('class', 'rosso'); 
            } else if (!input.checkValidity()) {
                input.setAttribute('class', 'rosso'); 
            } else {
                input.setAttribute('class', '');
            }
        });
    }

    submit.addEventListener('click', function(event) {
        valida();
    });
});