<?php
function Login($usr, $psw){
    define("HOST", "localhost");
    define("USER", "USERS");
    define("PASS", "123");
    define("DB", "es05");

    $conn = mysqli_connect(HOST, USER, PASS, DB);

    //ERRORE CONNESSIONE
    if(!$conn)
        return -2;

    $query = "select Username, Password from Utenti where Username = $usr";
    $ris = mysqli_query($conn, $query);

    if($ris){
        if(mysqli_num_rows($ris)>0){
            $acc = mysqli_fetch_assoc($ris);

            if($acc['Password'] == $psw){
                return 0;
            } else {
                //ERRORE CREDENZIALI ERRATE
                return -1;
            }

        } else {
            //ERRORE CREDENZIALI ERRATE
            return -1;
        }
    } else {
        //ERRORE QUERY
        return -3;
    }

}
?>