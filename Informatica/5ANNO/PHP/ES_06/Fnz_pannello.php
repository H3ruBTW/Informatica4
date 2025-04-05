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
        header("Location: Pannello.php?id=1&error=Errore di connessione al DB. Riprovare più tardi.");
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
        $html .= "<td>" . $value . "</td>";
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
                $html .= "<td>" . $value . "</td>";
            }
            $html .= "</tr>";

            $n += 1;
        }       
    }
    $html .= "</table>";

    return $html;
}

/*
//tabella con possibiltà di modificare
function start2(){
    $html = "<table>";

    $conn = mysqli_connect(HOST, USER, PASS, DB);

    // ERRORE CONNESSIONE
    if (!$conn) {
        header("Location: Pannello.php?id=2&error=Errore di connessione al DB. Riprovare più tardi.");
        exit;
    }

    $query = "SELECT * from utente";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_execute($stmt);
    $ris = mysqli_stmt_get_result($stmt);

    //ESTRAE LE CHIAVI
    if(($acc = mysqli_fetch_assoc($ris)) != NULL || !$acc){
        $chiavi = array_keys($acc);
        
        $html .= "<tr id=\"keys\">";

        for($i=0; isset($chiavi[$i]); $i++){
            $html .= "<th>" . $chiavi[$i] . "</th>";
        }

        $html .= "<th>Modifica</th>";

        $html .= "</tr>";
    }

    $html .= "<tr id=\"0\">";
    
    foreach ($acc as $key => $value) {
        $html .= "<td>" . $value . "</td>";
    }

    $html .= "<td><form id=\"mod0\" action=\"Pannello.php?id=2#0\" method=\"post\">";

    foreach ($acc as $key => $value) {
        if($key != "Password")
            $html .= "<input type=\"text\" name=\"" . $key . "\" value=\"" . $value . "\" hidden>";
    }

    $html .= "<input type=\"text\" name=\"oldID\" value=\"" . $acc['UserID'] . "\" hidden>";

    $html .= "<button class=\"button\" type=\"button\" id=\"0\">UPDATE</button></form></td>";

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
                $html .= "<td>" . $value . "</td>";
            }

            $html .= "<td><form id=\"mod$n\" action=\"Pannello.php?id=2#$n\" method=\"post\">";

            foreach ($acc as $key => $value) {
                if($key != "Password")
                    $html .= "<input type=\"text\" name=\"" . $key . "\" value=\"" . $value . "\" hidden>";
            }

            $html .= "<input type=\"text\" name=\"oldID\" value=\"" . $acc['UserID'] . "\" hidden>";

            $html .= "<button class=\"button\" type=\"button\" id=\"$n\">UPDATE</button></form></td>";
            $html .= "</tr>";

            $n += 1;
        }       
    }
    $html .= "</table>";

    return $html;
}*/

function start2(){
    $html = "<table>";

    $conn = mysqli_connect(HOST, USER, PASS, DB);

    // ERRORE CONNESSIONE
    if (!$conn) {
        header("Location: Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&error=Errore di connessione al DB. Riprovare più tardi.");
        exit;
    }

    $query = "SELECT * FROM utente ORDER BY " . $_GET['orderby'];
    if($_GET['di'] == "i"){
        $query .= " asc";
    } else {
        $query .= " desc";
    }

    

    $stmt = mysqli_prepare($conn, $query);
    mysqli_execute($stmt);
    $ris = mysqli_stmt_get_result($stmt);

    //ESTRAE LE CHIAVI
    if(($acc = mysqli_fetch_assoc($ris)) != NULL || !$acc){
        $chiavi = array_keys($acc);
        
        $html .= "<tr id=\"keys\">";

        for($i=0; isset($chiavi[$i]); $i++){
            $html .= "<th id=\"key\">" . $chiavi[$i] . "</th>";
        }

        $html .= "<th>Modifica</th>";
        $html .= "<th>Cancella</th>";

        $html .= "</tr>";
    }

    $html .= "<tr id=\"0\">";
    
    foreach ($acc as $key => $value) {
        $html .= "<td>" . $value . "</td>";
    }

    $html .= "<td><form id=\"mod0\" action=\"Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "#0\" method=\"post\">";

    foreach ($acc as $key => $value) {
        if($key != "Password")
            $html .= "<input type=\"text\" name=\"" . $key . "\" value=\"" . $value . "\" hidden>";
    }

    $html .= "<input type=\"text\" name=\"type\" value=\"update\" hidden>";
    $html .= "<input type=\"text\" name=\"oldID\" value=\"" . $acc['UserID'] . "\" hidden>";
    $html .= "<input type=\"text\" name=\"oldMail\" value=\"" . $acc['Email'] . "\" hidden>";
    $html .= "<input type=\"text\" name=\"oldUser\" value=\"" . $acc['Username'] . "\" hidden>";

    $html .= "<button class=\"button\" type=\"button\" id=\"0\">UPDATE</button></form></td>";

    $html .= "<td><form action=\"Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "#header\" method=\"post\">";
    $html .= "<input type=\"text\" name=\"type\" value=\"delete\" hidden>";
    $html .= "<input type=\"text\" name=\"oldID\" value=\"" . $acc['UserID'] . "\" hidden>";

    $html .= "<input class=\"button\" type=\"button\" id=\"del\" value=\"DELETE\"></form></td>";

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
                $html .= "<td>" . $value . "</td>";
            }

            $html .= "<td><form id=\"mod$n\" action=\"Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "#$n\" method=\"post\">";

            foreach ($acc as $key => $value) {
                if($key != "Password")
                    $html .= "<input type=\"text\" name=\"" . $key . "\" value=\"" . $value . "\" hidden>";
            }

            $html .= "<input type=\"text\" name=\"type\" value=\"update\" hidden>";
            $html .= "<input type=\"text\" name=\"oldID\" value=\"" . $acc['UserID'] . "\" hidden>";
            $html .= "<input type=\"text\" name=\"oldMail\" value=\"" . $acc['Email'] . "\" hidden>";
            $html .= "<input type=\"text\" name=\"oldUser\" value=\"" . $acc['Username'] . "\" hidden>";

            $html .= "<button class=\"button\" type=\"button\" id=\"$n\">UPDATE</button></form></td>";

            $html .= "<td><form action=\"Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "#header\" method=\"post\">";
            $html .= "<input type=\"text\" name=\"type\" value=\"delete\" hidden>";
            $html .= "<input type=\"text\" name=\"oldID\" value=\"" . $acc['UserID'] . "\" hidden>";

            $html .= "<input class=\"button\" type=\"button\" id=\"del\" value=\"DELETE\"></form></td>";

            $html .= "</tr>";

            $n += 1;
        }       
    }
    $html .= "</table>";

    return $html;
}

function DisplayError(){
    if($_SERVER['REQUEST_METHOD']=="GET"){
        if(isset($_GET['error'])){
            $err = "<p style=\"color:red\">" . $_GET['error'] . "</p>";
            return $err;
        }       
    }

    return null;
}

function UpdateDB(){
    
    try {
        $conn = mysqli_connect(HOST, USER, PASS, DB);

        // ERRORE CONNESSIONE
        if (!$conn) {
            throw("Errore di connessione al DB. Riprovare più tardi.");
        }

        $id      = trim($_POST['UserID']);
        $nome    = trim($_POST['Nome']);
        $cognome = trim($_POST['Cognome']);
        $mail    = trim($_POST['Email']);
        $dob     = trim($_POST['Data_Nascita']);
        $user    = trim($_POST['Username']);
        $err     = trim($_POST['Errori']);
        $derr    = trim($_POST['Ultimo_Errore']);
        $dacc    = trim($_POST['Ultimo_Accesso']);
        $token   = trim($_POST['Token']);
        $dtoken  = trim($_POST['Token_Creation']);
        $oldID   = trim($_POST['oldID']);
        $oldMail  = trim($_POST['oldMail']);
        $oldUser   = trim($_POST['oldUser']);

        //CHECK ID
        $query = "SELECT COUNT(*) FROM utente WHERE UserID = ? AND UserID != ?";
        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_param($stmt, "ii", $id, $oldID);
        mysqli_stmt_execute($stmt);
        mysqli_stmt_bind_result($stmt, $count);
        mysqli_stmt_fetch($stmt);
        mysqli_stmt_close($stmt);

        if ($count > 0) {
            throw new Exception("Un utente con questo ID esiste già");
        }

        // CHECK nome
        if ($nome == "") {
            throw new Exception("Il campo \"NOME\" è vuoto");
        }

        // CHECK cognome
        if ($cognome == "") {
            throw new Exception("Il campo \"COGNOME\" è vuoto");
        }

        // CHECK mail
        if (!preg_match("/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/", $mail)) {
            throw new Exception("Il campo \"MAIL\" è errato");
        }

        $query = "SELECT COUNT(*) FROM utente WHERE Email = ? AND Email != ?";
        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_param($stmt, "ss", $mail, $oldMail);  // Qui si deve usare "s" per una stringa
        mysqli_stmt_execute($stmt);
        mysqli_stmt_bind_result($stmt, $count);
        mysqli_stmt_fetch($stmt);
        mysqli_stmt_close($stmt);

        if ($count > 0) {
            throw new Exception("Un utente con questa Email esiste già");
        }

        // CHECK data di nascita
        if ($date = strtotime($dob)) {
            if ($date >= strtotime(date("Y-m-d"))) {
                throw new Exception("La \"Data Di Nascita\" non è valida, data oltre quella odierna");
            }
        } else {
            throw new Exception("La \"Data Di Nascita\" non è valida, formato ANNO-MS-GG");
        }

        // CHECK user
        if (!preg_match("/^[a-zA-Z0-9]{4,50}$/", $user)) {
            throw new Exception("Il campo \"Username\" è errato, minimo 4 caratteri, massimo 50");
        }

        $query = "SELECT COUNT(*) FROM utente WHERE Username = ? AND Username != ?";
        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_param($stmt, "ss", $user, $oldUser);  // Qui si deve usare "s" per una stringa
        mysqli_stmt_execute($stmt);
        mysqli_stmt_bind_result($stmt, $count);
        mysqli_stmt_fetch($stmt);
        mysqli_stmt_close($stmt);

        if ($count > 0) {
            throw new Exception("Un utente con questo Username esiste già");
        }

        // CHECK Errori
        if (filter_var($err, FILTER_VALIDATE_INT) !== false) {
            $err = intval($err);
            if (!($err >= 0 && $err <= 5)) {
                throw new Exception("Il campo \"Errori\" è errato, è stato inserito un numero minore di 0 o maggiore di 5");
            }
        } else {
            throw new Exception("Il campo \"Errori\" è errato, è stato inserito un NaN");
        }

        // CHECK Data Ultimo Errore
        if (!strtotime($derr)) {
            throw new Exception("Il campo \"Ultimo_Errore\" è errato, usa il formato ANNO-MS-GG HH-MM-SS");
        }

        // CHECK Data Ultimo Accesso
        if (!strtotime($dacc)) {
            throw new Exception("Il campo \"Ultimo_Accesso\" è errato, usa il formato ANNO-MS-GG HH-MM-SS");
        }

        // CHECK Token
        if (!preg_match("/^[0-9]{6,6}$/", $token) && $token != "") {
            throw new Exception("Il campo \"Token\" è errato, è stato inserito un NaN o non esattamente 6 cifre");
        }

        // CHECK Data Token
        if (!strtotime($dtoken)) {
            throw new Exception("Il campo \"Token_Creation\" è errato, usa il formato ANNO-MS-GG HH-MM-SS");
        }


        $query = "UPDATE utente 
        SET UserID = ?, Nome = ?, Cognome = ?, Email = ?, Data_Nascita = ?, Username = ?, Errori = ?, Ultimo_Errore = ?, 
        Ultimo_Accesso = ?, Token = ?, Token_Creation = ?
        WHERE UserID = ?";

        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_param($stmt, "issssssssssi", $id, $nome, $cognome, $mail, $dob, $user, $err, $derr, $dacc, $token, $dtoken, $oldID);
        mysqli_stmt_execute($stmt);
        mysqli_stmt_close($stmt);

    } catch (\Throwable $th) {
        header("Location: Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&error=" . $th->getMessage() . "#header");
        exit;
    }
    
}

function deleteInDB(){
    try {
        $conn = mysqli_connect(HOST, USER, PASS, DB);

        $oldID = trim($_POST['oldID']);

        // ERRORE CONNESSIONE
        if (!$conn) {
            throw("Errore di connessione al DB. Riprovare più tardi.");
        }

        $query = "DELETE FROM utente WHERE UserID = ?";

        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_param($stmt, "s", $oldID);
        mysqli_stmt_execute($stmt);
        mysqli_stmt_close($stmt);
    } catch (\Throwable $th) {
        header("Location: Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&error=" . $th->getMessage() . "#header");
        exit;
    }
}
?>