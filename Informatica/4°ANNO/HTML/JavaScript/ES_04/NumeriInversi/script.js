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

console.log(NumeriInversi(num));