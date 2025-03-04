<?php
require("Funzioni.php");
session_start();

if(CheckSessionRis()){
    $acc = fetch_all();
    if($_SERVER['REQUEST_METHOD']=="POST"){
        ChangeMail($_POST['mail']);
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
    <link rel="stylesheet" href="css/gestione.css">
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
                    <li><a href="Riservata.php"><u>Riservata</u></a></li>
                    <hr>                
                </ul>
            </nav>
        </div>
        <div class="content">
            <form action="<?= $_SERVER['PHP_SELF']?>" method="post">
                <div class="dati">
                    <label>E-mail:</label><br>
                    <input type="text" name="mail" placeholder="mario.rossi@mail.*" pattern="[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}" required>
                </div>
                <div class="dati2">
                    <p>E-mail In Utilizzo: <?= $acc['Email'] ?></p>
                </div> 
                <br>
                <input class="button" type="submit" value="Modifica">
                <a href="Riservata.php"><button type="button" class="button">Indietro</button></a>
            </form>
        </div>
    </div>

    <footer>
        <p>&copy; 2025 Buongallino Alessandro</p>
    </footer>
</body>
</html>
