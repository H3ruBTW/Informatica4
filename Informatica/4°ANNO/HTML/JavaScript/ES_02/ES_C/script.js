let persona = {
    nome: null,
    cognome: null,
    eta: null
}

persona.nome = prompt("Scrivi il tuo nome:");
persona.cognome = prompt("Scrivi il tuo cognome:");
persona.eta = prompt("Scrivi la tua età:");

console.log("Persona:");
for(let chiave in persona)
{
    console.log (chiave + " : " + persona[chiave]);
}