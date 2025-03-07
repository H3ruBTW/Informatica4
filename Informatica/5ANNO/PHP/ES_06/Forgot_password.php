<?php
require("Funzioni.php");
session_start();

$error = DisplayError();

if(!isset($error)){
    $error = "<br>";
}

if($_SERVER['REQUEST_METHOD'] == "POST"){
    $mail = $_POST['mail'];

    if(CheckMail($mail)){
        $_SESSION['mail'] = $mail;
        SetToken();

        header("Location: Token.php");
        exit;
    } else {
        header("Location: " . $_SERVER['PHP_SELF'] . "?error=Email non identificabile ad un account");
        exit;
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
            <?= $error ?>
            <form action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
                <div class="dati">
                    <label>E-mail:</label><br>
                    <input type="text" name="mail" placeholder="mario.rossi@mail.*" pattern="[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}" required>
                </div>
                <div class="dati2">
                    <br>
                </div> 
                <br><br>
                <input class="button" type="submit" value="Conferma">
                <a href="Login.php"><button type="button" class="button">Indietro</button></a>
            </form>
        </div>
    </div>

    <footer>
        <p>&copy; 2025 Buongallino Alessandro</p>
    </footer>
</body>
</html>
