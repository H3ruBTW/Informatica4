<?php 
$html = <<<COD
<form action="" method="post">
<h4>Dati Personali</h4>
<label for="name">Nome:</label>
<input type="text" name="name" placeholder="Mario" required>
<label for="surname" >Cognome:</label>
<input type="text" name="surname" placeholder="Rossi" required>
<br><br>
<label for="dob">Data di nascita:</label>
<input type="date" name="date" required>
<label for="fiscale">Codice fiscale:</label>
<input type="text" name="codicefis" placeholder="MRIRSS...">
<br><br>
<label for="mail">E-mail:</label>
<input type="text" name="mail" placeholder="mario.rossi@mail.*" required>
<label for="cellnumber" >Numero di cellulare:</label>
<input type="text" name="tel" placeholder="39 333 333 3333" required>

<h4>Indirizzo</h4>
<label for="tipo">Tipo di strada:</label>
<select name="tipo">
    <option value="Via">Via</option>
    <option value="Viale">Viale</option>
    <option value="Vicolo">Vicolo</option>
    <option value="Corso">Corso</option>
</select>

<label for="nomevia">Nome Via:</label>
<input type="text" name="via" placeholder="Vittorio Emanuele III" required>
<br><br>
<label for="prov">Provincia:</label>
<input type="text" name="prov" placeholder="MI" required>
<label for="comune">Comune:</label>
<input type="text" name="comune" placeholder="Bollate" required>

<h4>Account</h4>
<label for="username">Username:</label>
<input type="text" name="user" required>
<label for="password">Password:</label>
<input type="text" name="password" placeholder="min 8 car./1 spec./1 maiu.">
<br><br>
<input id="button" type="submit" value="Crea Account">
</form>
COD;

if($_SERVER['REQUEST_METHOD'] == 'POST'){
    $nome = $_POST["name"];
    $cog = $_POST["surname"];
    $data = $_POST["date"];
    $codfis = ($_POST["codicefis"] != null) ? strtoupper($_POST["codicefis"]) : "";
    $mail = $_POST["mail"];
    $tel = $_POST["tel"];
    $tipo = $_POST["tipo"];
    $vian = $_POST["via"];
    $prov = strtoupper($_POST["prov"]);
    $com= $_POST["comune"]; 
    $user = $_POST["user"];
    $pass = $_POST["password"];
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
                    <li><a href="index.php"><u>HomePage ES_03</u></a></li>
                    <hr>
                    <li><a href="ES_A.php">ES_A</a></li>
                    <hr>
                    <li><a href="ES_B.php"><b>ES_B</b></a></li>
                    <hr>
                </ul>
            </nav>
        </div>
        <div class="content">
            <?=$html?>
        </div>
    </div>

    <footer>
        <p>&copy; 2024 Buongallino Alessandro</p>
    </footer>
</body>
</html>