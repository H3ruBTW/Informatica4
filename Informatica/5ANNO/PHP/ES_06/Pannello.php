<?php
require "Fnz_pannello.php";
session_start();

$error = DisplayError();

$orderby = $_GET['orderby'] ?? "UserID";
$di = $_GET['di'] ?? "i";

if(!isset($error))
    $error = "<br>";

if($_SERVER['REQUEST_METHOD']=="POST"){
    switch ($_POST['type']) {
        case 'update':
            UpdateDB();
            break;

        case 'delete':
            
            break;
        
        default:
            break;
    }
}

$id = $_GET['id'] ?? "";

switch ($id) {
    case '1':
        $html = start1();
        break;
    
    case '2':
        $html = start2();
        break;
    
    default:
        $html = start1();
        break;
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
    <link rel="stylesheet" href="css/table.css">
    <title>Esecizi</title>
    <script>
        //oggetto globale per il browser per capire in che tabella si è nel .JS
        window.tab = <?= $id ?>;
        window.orderby = "<?= $orderby ?>";
        window.di = "<?= $di ?>";

        console.log("<?= $_POST['type']?>")
    </script>
    <script src="js/tabelle.js" defer></script>
</head>
<body>
    <header id="header"><h1>ESERCIZI PHP</h1></header>
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
            <div style="display:inline">
                <p><span style="font-size: 40px; font-weight:bold;">Tabella utenti</span>
                <a href="Pannello.php?id=1" class="link">Tabella 1</a> | 
                <a href="Pannello.php?id=2&orderby=UserID&di=i" class="link">Tabella 2</a>
                </p>
            </div>
            <?= $error ?>
            <?= $html ?>
            <br><br>
        </div>
    </div>

    <footer>
        <p>&copy; 2025 Buongallino Alessandro</p>
    </footer>
</body>
</html>