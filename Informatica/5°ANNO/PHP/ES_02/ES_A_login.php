<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="../img/icon.png">
    <link rel="stylesheet" href="css/style.css">
    <link rel="stylesheet" href="css/base.css">
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
                    <li><a href="index.php"><u>HomePage ES_02</u></a></li>
                    <hr>
                    <li><a href="ES_A.php"><b>ES_A</b></a></li>
                    <hr>
                    <li><a href="ES_B.php">ES_B</a></li>
                    <hr>
                    <li><a href="ES_C.php">ES_C</a></li>
                    <hr>
                </ul>
            </nav>
        </div>
        <div class="content">
            <h4>Controllo Credenziali Login</h4>
            <?php 
                try {
                    $user = $_POST['username'];
                } catch (\Throwable $th) {
                    $user = "$th";
                }
                
                try {
                    $psw = $_POST['password'];
                } catch (\Throwable $th) {
                    $psw = "$th";
                }

                if($user == "admin" && $psw == "pass123"){
                    echo "<p>Login avvenuto con successo.<br>Benvenuto $user nella pagina privata.</p>";
                } else {
                    echo "<p>Login fallito.<br>Credenziali errate.</p>";
                }
                
            ?>
        </div>
    </div>

    <footer>
        <p>&copy; 2024 Buongallino Alessandro</p>
    </footer>
</body>
</html>