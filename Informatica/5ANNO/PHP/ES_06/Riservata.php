<?php
require("Funzioni.php");
session_start();
$html = "";
$error = DisplayError();

if(CheckSessionRis()){
    $user = $_SESSION['username'];
    $access = getUltimoAccesso();
    if(isset($_COOKIE['user'])){
        $html = <<<COD
        <p>LOGIN EFFETTUATO CON SUCCESSO con <b>$user</b><br><br>
        Ultimo Accesso: $access<br><br>
        Se vuoi effettuare il logout, <button id="button" data-b="button">PREMI QUI</button></p>
        COD;
    } else {
        $html = <<<COD
        <p>LOGIN EFFETTUATO CON SUCCESSO con <b>$user</b><br><br>
        Ultimo Accesso: $access<br><br>
        Se vuoi effettuare il logout, <a href="Logout.php"><button id="button" data-b="none">PREMI QUI</button></a></p>
        COD;
    }
    
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="../img/icon.png">
    <link rel="stylesheet" href="css/style.css">
    <link rel="stylesheet" href="css/base.css">
    <script src="js/script.js" defer></script>
    <title>Esecizi</title>
</head>
<body>
    <header><h1>ESERCIZI PHP</h1></header>
    <div class="divs">
        <div class="menu">
            <nav>
                <ul>
                    <hr>
                    <li><a href="../index.php"><b>HomePage PHP</b></a></li>
                    <hr>
                    <li><a href="index.php"><u>HomePage ES_06</u></a></li>
                    <hr>
                    <li><a href="Welcome.php"><u>Welcome</u></a></li>
                    <hr>
                    <li><a href="Riservata.php"><b>Riservata</b></a></li>
                    <hr>                
                </ul>
            </nav>
        </div>
        <div class="content">
            <h2>PAGINA ACCOUNT</h2>
            <?= $error ?>
            <?= $html ?>
            <h2>GESTIONE ACCOUNT</h2>
            <a href="Cancella.php"><button id="button">Cancellazione Account</button></a><br>
            <div id="box">
                <form action="Logout.php" method="post">
                    <p>Vuoi rimuovere anche i cookies?</p>
                    <input type="checkbox" name="cookies"><br><br>
                    <input id="button2" type="submit" value="Conferma" style="display: inline;">
                    <button type="button" id="button3">Annulla</button>
                </form>   
            </div>
            <br>
            <br>
        </div>
    </div>
    <footer>
        <p>&copy; 2025 Buongallino Alessandro</p>
    </footer>
</body>
</html>

