<?php
// Definizione delle costanti per la connessione al database
define("HOST", "localhost"); // Host del database
define("USER", "USERS");     // Nome utente per la connessione al database
define("PASS", "123");       // Password per la connessione al database
define("DB", "es06");        // Nome del database

// Funzione per mostrare una tabella senza possibilità di modifica
function show_table1(){
    $html = "<table>"; // Inizializzazione della tabella HTML

    try {
        // Connessione al database
        $conn = mysqli_connect(HOST, USER, PASS, DB);

        // Controllo errore di connessione
        if (!$conn) {
            $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
            return $html;
        }

        // Query per selezionare tutti i dati dalla tabella "utente"
        $query = "SELECT * from utente";
        $stmt = mysqli_prepare($conn, $query); // Preparazione della query
        mysqli_execute($stmt); // Esecuzione della query
        $ris = mysqli_stmt_get_result($stmt); // Ottenimento del risultato della query

        // Estrazione delle chiavi della tabella
        if(($acc = mysqli_fetch_assoc($ris)) != NULL || !$acc){
            $chiavi = array_keys($acc); // Ottiene le chiavi (nomi delle colonne)
            
            $html .= "<tr>"; // Inizio della riga delle intestazioni

            // Creazione delle intestazioni della tabella
            for($i=0; isset($chiavi[$i]); $i++){
                $html .= "<th>" . $chiavi[$i] . "</th>";
            }

            $html .= "</tr>"; // Fine della riga delle intestazioni
        }

        $html .= "<tr id=\"0\">"; // Inizio della prima riga dei dati
        
        // Aggiunta dei dati della prima riga
        foreach ($acc as $key => $value) {
            $html .= "<td>" . $value . "</td>";
        }

        $html .= "</tr>"; // Fine della prima riga

        // Numero della riga estratta
        $n = 1;

        // Ciclo per aggiungere tutte le righe successive
        while(($acc = mysqli_fetch_assoc($ris)) != NULL){
            if(!$acc){
                $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
            } else {
                $html .= "<tr id=\"$n\">"; // Inizio di una nuova riga
        
                foreach ($acc as $key => $value) {
                    $html .= "<td>" . $value . "</td>"; // Aggiunta dei dati alla riga
                }
                $html .= "</tr>"; // Fine della riga

                $n += 1; // Incremento del numero di riga
            }       
        }
        $html .= "</table>"; // Fine della tabella
    } catch (mysqli_sql_exception $th) {
        // Gestione degli errori
        $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
    }

    return $html; // Ritorna la tabella HTML
}

// Funzione per mostrare una tabella con ordinamento e paginazione
function show_table2(){
    $html = "<table>"; // Inizializzazione della tabella HTML

    try {
        // Connessione al database
        $conn = mysqli_connect(HOST, USER, PASS, DB);

        // Controllo errore di connessione
        if (!$conn) {
            $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
            return $html;
        }

        // Costruzione della query con ordinamento
        $query = "SELECT * FROM utente ORDER BY " . $_GET['orderby'];
        if($_GET['di'] == "i"){ // Controllo del tipo di ordinamento
            $query .= " asc"; // Ordinamento crescente
        } else {
            $query .= " desc"; // Ordinamento decrescente
        }

        // Aggiunta della paginazione
        if(isset($_GET['pag'])){
            $query .= " LIMIT 50 OFFSET " . $_GET['pag']*50-50; // Limita i risultati a 50 per pagina
            $pag = $_GET['pag']; // Numero di pagina corrente
        } else {
            $query .= " LIMIT 50 OFFSET 0"; // Prima pagina
            $pag = 1;
        }

        $stmt = mysqli_prepare($conn, $query); // Preparazione della query
        mysqli_execute($stmt); // Esecuzione della query
        $ris = mysqli_stmt_get_result($stmt); // Ottenimento del risultato della query

        // Estrazione delle chiavi della tabella
        if(($acc = mysqli_fetch_assoc($ris)) != NULL || !$acc){
            $chiavi = array_keys($acc); // Ottiene le chiavi (nomi delle colonne)
            
            $html .= "<tr id=\"keys\">"; // Inizio della riga delle intestazioni

            // Creazione delle intestazioni della tabella
            for($i=0; isset($chiavi[$i]); $i++){
                $html .= "<th id=\"key\">" . $chiavi[$i] . "</th>";
            }

            $html .= "<th>Modifica</th>"; // Colonna per i pulsanti di modifica
            $html .= "<th>Cancella</th>"; // Colonna per i pulsanti di cancellazione

            $html .= "</tr>"; // Fine della riga delle intestazioni
        }

        // Numero della riga estratta
        $n = 0;

        // Ciclo per aggiungere tutte le righe successive
        do{
            if(!$acc){
                $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
            } else {
                $html .= "<tr id=\"$n\">"; // Inizio di una nuova riga
        
                foreach ($acc as $key => $value) {
                    $html .= "<td>" . $value . "</td>"; // Aggiunta dei dati alla riga
                }

                // Aggiunta dei pulsanti di modifica e cancellazione
                $html .= "<td><form id=\"mod$n\" action=\"Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=". $_GET['pag'] ."#$n\" method=\"post\">";

                foreach ($acc as $key => $value) {
                    if($key != "Password") // Esclude la password
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

                $html .= "</tr>"; // Fine della riga

                $n += 1; // Incremento del numero di riga
            }
        } while(($acc = mysqli_fetch_assoc($ris)) != NULL);
        
        $html .= "</table><br>"; // Fine della tabella

        // Query per il conteggio totale delle righe
        $query = "SELECT COUNT(*) FROM utente";
        $stmt = mysqli_prepare($conn, $query); // Preparazione della query
        mysqli_stmt_bind_result($stmt, $count); // Associazione del risultato
        mysqli_execute($stmt); // Esecuzione della query
        mysqli_stmt_fetch($stmt); // Ottenimento del risultato

        // Aggiunta dei pulsanti di navigazione per la paginazione
        if($pag-1 != 0){
            $html .= " <a href=\"Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $pag-1 . "\"><button class=\"newbutton\"><= PRECEDENTE</button></a> ";
        }

        if($pag <= $count/50){
            $html .= " <a href=\"Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $pag+1 . "\"><button class=\"newbutton\">SUCCESSIVO =></button></a> ";
        }

        $html .= "<br>";

        // Creazione dei pulsanti per ogni pagina
        for($i=0; $i<$count/50; $i++){
            $html .= " <a href=\"Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $i+1 . "\"><button class=\"newbutton\">" . $i+1 . "</button></a> ";
        }
    } catch (mysqli_sql_exception $th) {
        // Gestione degli errori
        $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
    }  

    return $html; // Ritorna la tabella HTML
}

function show_table3(){
    $html = "<table>";
    try {
        $conn = mysqli_connect(HOST, USER, PASS, DB);

        // ERRORE CONNESSIONE
        if (!$conn) {
            $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
            return $html;
        }

        $query = "SELECT * FROM utente ORDER BY " . $_GET['orderby'];
        if($_GET['di'] == "i"){
            $query .= " asc";
        } else {
            $query .= " desc";
        }

        if(isset($_GET['pag'])){
            $query .= " LIMIT 50 OFFSET " . $_GET['pag']*50-50;
            $pag = $_GET['pag'];
        } else {
            $query .= " LIMIT 50 OFFSET 0";
            $pag = 1;
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

        //Numero riga estratta
        $n = 0;

        //@RETURN mysqli_fetch_assoc array|false|null
        do{
            if(!$acc){
                $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
            } else {
                $html .= "<tr id=\"$n\">";
        
                foreach ($acc as $key => $value) {
                    $html .= "<td data-old=\"" . $value . "\">" . $value . "</td>";
                }

                $html .= "<td><form id=\"mod$n\"  method=\"post\">";

                foreach ($acc as $key => $value) {
                    if($key != "Password")
                        $html .= "<input type=\"text\" name=\"" . $key . "\" value=\"" . $value . "\" hidden>";
                }

                $html .= "<input type=\"text\" name=\"type\" value=\"update\" hidden>";
                $html .= "<input type=\"text\" name=\"oldID\" value=\"" . $acc['UserID'] . "\" hidden>";
                $html .= "<input type=\"text\" name=\"oldMail\" value=\"" . $acc['Email'] . "\" hidden>";
                $html .= "<input type=\"text\" name=\"oldUser\" value=\"" . $acc['Username'] . "\" hidden>";

                $html .= "<button class=\"button\" type=\"button\" id=\"$n\">UPDATE</button></form></td>";

                $html .= "<td><form action=\"Pannello.php?id=3&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "#header\" method=\"post\">";
                $html .= "<input type=\"text\" name=\"type\" value=\"delete\" hidden>";
                $html .= "<input type=\"text\" name=\"oldID\" value=\"" . $acc['UserID'] . "\" hidden>";

                $html .= "<input class=\"button\" type=\"button\" id=\"del\" value=\"DELETE\"></form></td>";

                $html .= "</tr>";

                $n += 1;
            }
        } while(($acc = mysqli_fetch_assoc($ris)) != NULL);
        
        $html .= "</table><br>";

        $query = "SELECT COUNT(*) FROM utente";
        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_result($stmt, $count);
        mysqli_execute($stmt);
        mysqli_stmt_fetch($stmt);

        if($pag-1 != 0){
            $html .= " <a href=\"Pannello.php?id=3&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $pag-1 . "\"><button class=\"newbutton\"><= PRECEDENTE</button></a> ";
        }

        if($pag <= $count/50){
            $html .= " <a href=\"Pannello.php?id=3&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $pag+1 . "\"><button class=\"newbutton\">SUCCESSIVO =></button></a> ";
        }

        $html .= "<br>";

        for($i=0; $i<$count/50; $i++){
            $html .= " <a href=\"Pannello.php?id=3&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $i+1 . "\"><button class=\"newbutton\">" . $i+1 . "</button></a> ";
        }
    } catch (mysqli_sql_exception $th) {
        $html .= "</table><br><p style=\"color:red\">Errore di fetching dei dati</p>";
    }
    
    return $html;
}

function DisplayError(){
    if($_SERVER['REQUEST_METHOD']=="GET"){
        if(isset($_GET['error'])){
            $err = $_GET['error'];
            return $err;
        }       
    }

    return null;
}

function DisplaySuccess(){
    if($_SERVER['REQUEST_METHOD']=="GET"){
        if(isset($_GET['succ'])){
            $succ = $_GET['succ'];
            return $succ;
        }       
    }

    return null;
}

function UpdateTable(){
    
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
            throw new Exception("L'utente con ID:" . $id . " esiste già");
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

        $query = "SELECT COUNT(*), UserID FROM utente WHERE Email = ? AND Email != ?";
        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_param($stmt, "ss", $mail, $oldMail); 
        mysqli_stmt_execute($stmt);
        mysqli_stmt_bind_result($stmt, $count, $exist);
        mysqli_stmt_fetch($stmt);
        mysqli_stmt_close($stmt);

        if ($count > 0) {
            throw new Exception("L'utente con id:". $exist . " ha questa Email");
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
            throw new Exception("Il campo \"Username\" è errato, minimo 4 caratteri alfanumerici, massimo 50");
        }

        $query = "SELECT COUNT(*), UserID FROM utente WHERE Username = ? AND Username != ?";
        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_param($stmt, "ss", $user, $oldUser);  // Qui si deve usare "s" per una stringa
        mysqli_stmt_execute($stmt);
        mysqli_stmt_bind_result($stmt, $count, $exist);
        mysqli_stmt_fetch($stmt);
        mysqli_stmt_close($stmt);

        if ($count > 0) {
            throw new Exception("L'utente con id:". $exist . " ha questo Username");
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
            throw new Exception("Il campo \"Ultimo_Errore\" è errato, usa il formato ANNO-MS-GG HH:MM:SS");
        }

        // CHECK Data Ultimo Accesso
        if (!strtotime($dacc)) {
            throw new Exception("Il campo \"Ultimo_Accesso\" è errato, usa il formato ANNO-MS-GG HH:MM:SS");
        }

        // CHECK Token
        if (!preg_match("/^[0-9]{6,6}$/", $token) && $token != "") {
            throw new Exception("Il campo \"Token\" è errato, è stato inserito un NaN o non esattamente 6 cifre");
        }

        // CHECK Data Token
        if (!strtotime($dtoken)) {
            throw new Exception("Il campo \"Token_Creation\" è errato, usa il formato ANNO-MS-GG HH:MM:SS");
        }


        $query = "UPDATE utente 
        SET UserID = ?, Nome = ?, Cognome = ?, Email = ?, Data_Nascita = ?, Username = ?, Errori = ?, Ultimo_Errore = ?, 
        Ultimo_Accesso = ?, Token = ?, Token_Creation = ?
        WHERE UserID = ?";

        $stmt = mysqli_prepare($conn, $query);
        mysqli_stmt_bind_param($stmt, "issssssssssi", $id, $nome, $cognome, $mail, $dob, $user, $err, $derr, $dacc, $token, $dtoken, $oldID);
        mysqli_stmt_execute($stmt);
        mysqli_stmt_close($stmt);

        header("Location: Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $_GET['pag'] . "&succ=Utente con id: " . $oldID . " modificato con successo");
        exit;
    } catch (mysqli_sql_exception $th) {
        header("Location: Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $_GET['pag'] . "&error=Errore di connessione al DB");
        exit;
    } catch (\Throwable $th) {
        header("Location: Pannello.php?id=2&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $_GET['pag'] . "&error=" . $th->getMessage());
        exit;
    }
    
}

function deleteInDB(){
    try {
        $conn = mysqli_connect(HOST, USER, PASS, DB);

        $id = $_GET['id'] ?? "2";

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

        header("Location: Pannello.php?id=" . $id . "&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&succ=Utente con id: ". $oldID ." cancellato con successo#header");
        exit;
    } catch (mysqli_sql_exception $th) {
        header("Location: Pannello.php?id=" . $id . "&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $_GET['pag'] . "&error=Errore di connessione al DB");
        exit;
    } catch (\Throwable $th) {
        header("Location: Pannello.php?id=" . $id . "&orderby=" . $_GET['orderby'] . "&di=" . $_GET['di'] . "&pag=" . $_GET['pag'] . "&error=" . $th->getMessage());
        exit;
    }
}
?>