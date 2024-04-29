ES_B();

function ES_B(){
    const obj = {
        userAgent: navigator.userAgent,
        piattaforma: navigator.platform,
        lingua: navigator.language,
        cookies: navigator.cookieEnabled,
        online: navigator.onLine,
        geolocazione: navigator.geolocation,
        userAgentData: navigator.userAgentData,
        venditore_browser: navigator.vendor,
        plugins: navigator.plugins,
        java_attivato: navigator.javaEnabled()
    }

    for(let chiave in obj)
    {
        console.log(chiave + ": ")
        console.log(obj[chiave])
        console.log(" ")
    }
}
