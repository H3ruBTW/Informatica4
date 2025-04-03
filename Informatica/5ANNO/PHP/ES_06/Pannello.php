<?php
require "Fnz_pannello.php";
session_start();

$html = start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="../img/icon.png">
    <link rel="stylesheet" href="css/style.css">
    <link rel="stylesheet" href="css/table.css">
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
                    <li><a href="Pannello.php"><b>Pannello</b></a></li>
                    <hr>                  
                </ul>
            </nav>
        </div>
        <div class="content">
            <h2>Tabella utenti</h2>
            <?= $html?>
            <br><br>
        </div>
    </div>

    <footer>
        <p>&copy; 2025 Buongallino Alessandro</p>
    </footer>
</body>
</html>