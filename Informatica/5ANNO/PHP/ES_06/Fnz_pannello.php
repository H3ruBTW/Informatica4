<?php
define("HOST", "localhost");
define("USER", "USERS");
define("PASS", "123");
define("DB", "es06");

//tabella senza possibilità di modificare
function start1(){
    $html = "<table>";

    $conn = mysqli_connect(HOST, USER, PASS, DB);

    // ERRORE CONNESSIONE
    if (!$conn) {
        header("Location: Login.php?error=Errore di connessione al DB. Riprovare più tardi.");
        exit;
    }

    $query = "SELECT * from utente";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_execute($stmt);
    $ris = mysqli_stmt_get_result($stmt);

    //ESTRAE LE CHIAVI
    if(($acc = mysqli_fetch_assoc($ris)) != NULL || !$acc){
        $chiavi = array_keys($acc);
        
        $html .= "<tr>";

        for($i=0; isset($chiavi[$i]); $i++){
            $html .= "<th>" . $chiavi[$i] . "</th>";
        }

        $html .= "</tr>";
    }

    $html .= "<tr id=\"0\">";
    
    foreach ($acc as $key => $value) {
        $html .= "<th>" . $value . "</th>";
    }

    $html .= "</tr>";

    //Numero riga estratta
    $n = 1;

    //@RETURN mysqli_fetch_assoc array|false|null
    while(($acc = mysqli_fetch_assoc($ris)) != NULL){
        if(!$acc){
            $html .= "</table><br><p style=\"color=red\">Errore di fetching dei dati</p>";
        } else {
            $html .= "<tr id=\"$n\">";
    
            foreach ($acc as $key => $value) {
                $html .= "<th>" . $value . "</th>";
            }
            $html .= "</tr>";

            $n += 1;
        }       
    }
    $html .= "</table>";

    return $html;
}

//tabella con possibiltà di modificare
function start2(){
    $html = "<table>";

    $conn = mysqli_connect(HOST, USER, PASS, DB);

    // ERRORE CONNESSIONE
    if (!$conn) {
        header("Location: Login.php?error=Errore di connessione al DB. Riprovare più tardi.");
        exit;
    }

    $query = "SELECT * from utente";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_execute($stmt);
    $ris = mysqli_stmt_get_result($stmt);

    //ESTRAE LE CHIAVI
    if(($acc = mysqli_fetch_assoc($ris)) != NULL || !$acc){
        $chiavi = array_keys($acc);
        
        $html .= "<tr>";

        for($i=0; isset($chiavi[$i]); $i++){
            $html .= "<th>" . $chiavi[$i] . "</th>";
        }

        $html .= "<th>Modifica</th>";

        $html .= "</tr>";
    }

    $html .= "<tr id=\"0\"";
    
    foreach ($acc as $key => $value) {
        $html .= "<th>" . $value . "</th>";
    }

    $html .= "<th><button class=\"button\" id=\"0\">UPDATE</button></th>";

    $html .= "</tr>";

    //Numero riga estratta
    $n = 1;

    //@RETURN mysqli_fetch_assoc array|false|null
    while(($acc = mysqli_fetch_assoc($ris)) != NULL){
        if(!$acc){
            $html .= "</table><br><p style=\"color=red\">Errore di fetching dei dati</p>";
        } else {
            $html .= "<tr id=\"$n\">";
    
            foreach ($acc as $key => $value) {
                $html .= "<th>" . $value . "</th>";
            }
            $html .= "<th><button class=\"button\" id=\"$n\">UPDATE</button></th>";
            $html .= "</tr>";

            $n += 1;
        }       
    }
    $html .= "</table>";

    return $html;
}
?>