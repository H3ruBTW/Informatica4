<?php
session_start();
$error = "";

if(isset($_SESSION['username'])){
    header("Location: ES_C-Riservata.php");
    exit;
}

if($_SERVER['REQUEST_METHOD']=="post"){
    $user = (isset($_POST["username"])) ? $_POST['username'] : "";
    $pass = (isset($_POST['password'])) ? $_POST['password'] : "";

    $status = Login($user, $pass);

    switch ($status) {
        case '0':
            $_SESSION['username'] = $user;
            header("Location: ES_C-Riservata.php");
            break;

        //ERRORI
        case '-1':
            $error = "<p style=\"color: red\">CREDENZIALI ERRATE</p>";
            break;
        
        case '-2':
            $error = "<p style=\"color: red\">ERRORE DI CONNESSIONE AL DB. RIPROVARE PIU' TARDI</p>";
            break;
        
        case '-3':
            $error = "<p style=\"color: red\">ERRORE NELLA RICERCA NEL DATABASE</p>";
            break;

        default:
            break;
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
                    <li><a href="index.php"><u>HomePage ES_04</u></a></li>
                    <hr>
                    <li><a href="ES_A_B-DB.php"><u>ES_AB - Accesso DB</u></a></li>
                    <hr>  
                    <li><a href="ES_C-Welcome.php"><u>ES_C - Welcome</u></a></li>
                    <hr>    
                    <li><a href="ES_C-Riservata.php"><u>ES_C - Riservata</u></a></li>
                    <hr>           
                </ul>
            </nav>
        </div>
        <div class="content">
            <br>
            <?php echo $error ?>
            <form action="<?php echo $_SERVER['PHP_SELF']?>" method="POST"> 
                <label>Username:</label><br>
                <input type="text" name="username" required><br>
                <label>Password:</label><br>
                <input type="text" name="password" required><br>
                <input id="button" type="submit" value="Accedi">
            </form>
        </div>
    </div>

    <footer>
        <p>&copy; 2025 Buongallino Alessandro</p>
    </footer>
</body>
</html>
