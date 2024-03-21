NumeriInversi = function(x){
    let array = [];
    let n = "";

    for (let i = 0; i < x.length; i++) {
        array[i] = x.charAt(i);
    }

    array.forEach(e => {
        n = e + n;
    });

    return n;
}

let num = "";
num = prompt("Inserire un numero");

if(Number.isInteger(num))
    console.log(NumeriInversi(num));
else
    console.error("L'inserimento è NaN")