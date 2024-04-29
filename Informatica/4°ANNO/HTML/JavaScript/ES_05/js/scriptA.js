ES_A();

function ES_A(){
    const obj = {
        doc: window.document,
        loc: window.location,
        nav: window.navigator,
        height: window.innerHeight,
        width: window.innerWidth,
        local: window.localStorage,
        session: window.sessionStorage
    }

    for(let chiave in obj)
    {
        console.log(chiave + ": ")
        console.log(obj[chiave])
        console.log(" ")
    }
}

