<?php
define("HOST", "localhost");
define("USER", "USERS");
define("PASS", "123");
define("DB", "es06");

function Login($usr, $psw, $cookies) {
    session_start(); // Assicura che la sessione sia avviata

    $conn = mysqli_connect(HOST, USER, PASS, DB);

    // ERRORE CONNESSIONE
    if (!$conn) {
        header("Location: Login.php?error=Errore di connessione al DB. Riprovare più tardi.");
        exit;
    }

    // STATEMENT PER EVITARE SQL INJECTION
    $query = "SELECT * FROM utente WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "s", $usr);
    mysqli_stmt_execute($stmt);
    $ris = mysqli_stmt_get_result($stmt);

    if ($ris && mysqli_num_rows($ris) > 0) {
        $acc = mysqli_fetch_assoc($ris);

        // Controllo errori login
        if ($acc['Errori'] >= 5) {
            $ultimo_errore = strtotime($acc['Ultimo_Errore']);

            if ((time() - $ultimo_errore) / 60 < 30) {
                header("Location: Login.php?error=Troppi accessi, riprova tra 30 minuti.");
                exit;
            } else {
                // Resetta il contatore errori dopo 30 minuti
                $query = "UPDATE utente SET Errori = 0 WHERE Username = ?";
                $stmt = mysqli_prepare($conn, $query);
                mysqli_stmt_bind_param($stmt, "s", $usr);
                mysqli_stmt_execute($stmt);
            }
        }

        // Controllo password con password_verify()
        if (password_verify($psw, $acc['Password'])) {
            $_SESSION['username'] = $usr;

            // Se l'utente vuole salvare l'username
            if ($cookies) {
                setcookie("user", $usr, time() + 3600, "/");
            }

            // Aggiorna dati login
            $query = "UPDATE utente SET Errori = 0, Ultimo_Accesso = CURRENT_TIMESTAMP WHERE Username = ?";
            $stmt = mysqli_prepare($conn, $query);
            mysqli_stmt_bind_param($stmt, "s", $usr);
            mysqli_stmt_execute($stmt);

            mysqli_close($conn);
            header("Location: Riservata.php");
            exit;
        } else {
            // PASSWORD ERRATA
            setError($conn, $acc);
            header("Location: Login.php?error=Credenziali errate.");
            exit;
        }
    } else {
        // Utente non trovato
        header("Location: Login.php?error=Credenziali errate.");
        exit;
    }
    
    mysqli_close($conn);
}

function Registration(){
    $conn = mysqli_connect(HOST, USER, PASS, DB);

    //ERRORE CONNESSIONE
    if(!$conn){
        header("Location: Login.php?error=Non è stato possibile creare l'account. Riprovare più tardi.");
        exit;
    } 
    
    $name = $_POST['name'];
    $surname = $_POST['surname'];
    $date = $_POST['date'];
    $email = strtolower($_POST['mail']);
    $user = $_POST['username'];
    $psw = password_hash(trim($_POST['password']), PASSWORD_BCRYPT);

    //STATEMENT PER EVITARE SQL INJECTION - Verifica se l'email esiste già
    $query = "SELECT COUNT(*) FROM utente WHERE Email = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "s", $email);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $count);
    mysqli_stmt_fetch($stmt);
    mysqli_stmt_close($stmt);

    if ($count > 0) {
        header("Location: Register.php?error=Email già registrata!");
        exit;
    }

    //STATEMENT PER EVITARE SQL INJECTION - Verifica se lo username esiste già
    $query = "SELECT COUNT(*) FROM utente WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "s", $username);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $count);
    mysqli_stmt_fetch($stmt);
    mysqli_stmt_close($stmt);

    if ($count > 0) {
        header("Location: Register.php?error=Username già in uso!");
        exit;
    }

    //CREO UNO STATEMENT PER EVITARE LA SQL INJECTION
    $query = "INSERT INTO utente (Nome, Cognome, Data_Nascita, Email, Username, Password) 
              VALUES (?, ?, ?, ?, ?, ?)";
    
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "ssssss", $name, $surname, $date, $email, $user, $psw);

    if(mysqli_stmt_execute($stmt)){
        header("Location: Login.php?succ=Account creato con successo");
        exit;
    } else {
        header("Location: Registrazione.php?error=Non è stato possibile creare l'account. Riprovare più tardi.");
        exit;
    }

    mysqli_stmt_close($stmt);
    mysqli_close($conn);
}

function setError($conn, $acc){
    $user = $acc['Username'];
    $error = $acc['Errori']+1;
    $query = "update utente set Errori = $error, Ultimo_Errore = CURRENT_TIMESTAMP() where Username = '$user'";
    mysqli_query($conn, $query);
}

function CheckSessionRis(){
    if(!isset($_SESSION['username'])){
        header("Location: Login.php?error=Entrata in pagina riservata non autorizzata");
        exit;
    } 

    return true;
}

function CheckSession(){
    if(isset($_SESSION['username'])){
        setUltimoAccesso();
        header("Location: Riservata.php");
        exit;
    }    
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

function DisplaySuccess(){
    if($_SERVER['REQUEST_METHOD']=="GET"){
        if(isset($_GET['succ'])){
            $succ = "<p style=\"color:#4CAF50\">" . $_GET['succ'] . "</p>";
            return $succ;
        }       
    }

    return null;
}

function getUltimoAccesso(){
    $conn = mysqli_connect(HOST, USER, PASS, DB);
    $usr = $_SESSION['username'];

    //ERRORE CONNESSIONE
    if(!$conn){
        return "ERROR";
    }

    $query = "select * from utente where Username = \"$usr\"";
    try {
        $ris = mysqli_query($conn, $query);

        if($ris){
            if(mysqli_num_rows($ris)>0){
                $acc = mysqli_fetch_assoc($ris);

                return $acc['Ultimo_Accesso'];

            } 
        } 
    } catch (\Throwable $th) {
        header("Location: Login.php?error=Errore DB: " . mysqli_error($conn));
    }  
}

function setUltimoAccesso(){
    $conn = mysqli_connect(HOST, USER, PASS, DB);
    $usr = $_SESSION['username'];

    //ERRORE CONNESSIONE
    if(!$conn){
        exit;
    }

    $query = "select * from utente where Username = \"$usr\"";
    try {
        $ris = mysqli_query($conn, $query);

        if($ris){
            if(mysqli_num_rows($ris)>0){
                $query = "update utente set Ultimo_Accesso = CURRENT_TIMESTAMP() where Username = '$usr'";
                mysqli_query($conn, $query);

            } 
        } 
    } catch (\Throwable $th) {
        header("Location: Login.php?error=Errore DB: " . mysqli_error($conn));
    }  
}

function ChangeUser($new_usr){
    $conn = mysqli_connect(HOST, USER, PSW, DB);
    $usr = $_SESSION['username'];

    if(!$conn){
        header("Location: Riservata.php?error=Non è stato possibile collegarsi, riprovare più tardi");
        exit;
    }

    //STATEMENT PER EVITARE SQL INJECTION - Verifica se lo username esiste già
    $query = "SELECT COUNT(*) FROM utente WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "s", $username);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $count);
    mysqli_stmt_fetch($stmt);
    mysqli_stmt_close($stmt);

    if ($count > 0) {
        header("Location: C_User.php?error=Username già in uso!");
        exit;
    }

    $query = "UPDATE utente SET Username = ? WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "ss", $new_usr, $usr);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);

    $_SESSION['username'] = $new_usr;

    header("Location: Riservata.php?succ=Username cambiato con successo");
    exit;
}

function ChangePsw($old_psw, $new_psw){
    $conn = mysqli_connect(HOST, USER, PSW, DB);
    $usr = $_SESSION['username'];
    $new_psw = password_hash(trim($new_psw), PASSWORD_BCRYPT);

    if(!$conn){
        header("Location: Riservata.php?error=Non è stato possibile collegarsi, riprovare più tardi");
        exit;
    }

    $query = "SELECT * FROM utente WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "s", $usr);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $pass);
    mysqli_stmt_close($stmt);

    if(!password_verify($pass, $old_psw)){
        header("Location: C_Psw.php?error=Password errata");
        exit;
    }

    $query = "UPDATE utente SET Password = ? WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "ss", $new_psw, $usr);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);

    header("Location: Riservata.php?succ=Password cambiata con successo");
    exit;
}

function ChangeMail($mail){
    $conn = mysqli_connect(HOST, USER, PSW, DB);
    $usr = $_SESSION['username'];

    if(!$conn){
        header("Location: Riservata.php?error=Non è stato possibile collegarsi, riprovare più tardi");
        exit;
    }

    //STATEMENT PER EVITARE SQL INJECTION - Verifica se l'email esiste già
    $query = "SELECT COUNT(*) FROM utente WHERE Email = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "s", $mail);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $count);
    mysqli_stmt_fetch($stmt);
    mysqli_stmt_close($stmt);

    if ($count > 0) {
        header("Location: C_Mail.php?error=Email già registrata!");
        exit;
    }

    $query = "UPDATE utente SET Email = ? WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "ss", strtolower($mail), $usr);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);

    header("Location: Riservata.php?succ=E-mail cambiata con successo");
    exit;
}

function ChangePData($nome, $cog, $dob){
    $conn = mysqli_connect(HOST, USER, PSW, DB);
    $usr = $_SESSION['username'];

    if(!$conn){
        header("Location: Riservata.php?error=Non è stato possibile collegarsi, riprovare più tardi");
        exit;
    }

    $query = "UPDATE utente SET Nome = ?, Cognome = ?, Data_Nascita = ? WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "sss", $nome, $cog, $dob, $usr);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);

    header("Location: Riservata.php?succ=Dati cambiati con successo");
    exit;
}

function Cancel(){
    $conn = mysqli_connect(HOST, USER, PASS, DB);
    $usr = $_SESSION['username'];

    if(!$conn){
        header("Location: Riservata.php?error=Non è stato possibile eliminare l'account");
        exit;
    }

    $query = "DELETE FROM utente WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "s", $usr);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);

    session_destroy();

    header("Location: Login.php?succ=Cancellazione avvenuta con successo");
    exit;
}

function fetch_all(){
    $conn = mysqli_connect(HOST, USER, PASS, DB);
    $usr = $_SESSION['username'];

    if(!$conn){
        header("Location: Riservata.php?error=Non è stato possibile collegarsi, riprovare più tardi");
        exit;
    }

    $query = "SELECT * FROM utente WHERE Username = ?";
    $stmt = mysqli_prepare($conn, $query);
    mysqli_stmt_bind_param($stmt, "s", $usr);
    mysqli_stmt_execute($stmt);
    $ris = mysqli_stmt_get_result($stmt);
    mysqli_stmt_close($stmt);

    return mysqli_fetch_assoc($ris);
}
?>