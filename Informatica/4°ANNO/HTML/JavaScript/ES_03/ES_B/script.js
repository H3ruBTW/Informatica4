let libro = {
    Titolo: "Harry Potter e la pietra filosofale", 
    Autore: "J. K. Rowling", 
    Anno_di_pubblicazione: 1997, 
    Genere: "Fantascienza", 
    Numero_di_pagine: 304
}

for(let chiave in libro)
{
    console.log(chiave + ": " + libro[chiave]);
}

console.log();

for(let chiave in libro)
{
    console.log(`${chiave} -> ${libro[chiave]}`);
}