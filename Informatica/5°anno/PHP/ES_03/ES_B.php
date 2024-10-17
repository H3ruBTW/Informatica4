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
<input type="text" name="codicefis" placeholder="MRIRSS..." pattern="[a-zA-Z]{6}[\d]{2}[a-zA-Z][\d]{2}[a-zA-Z][\d]{3}[a-zA-Z]" title=" \nFormato del codice fiscale errato">
<br><br>
<label for="mail">E-mail:</label>
<input type="text" name="mail" placeholder="mario.rossi@mail.*" pattern="[a-zA-Z0-9\.\-_]{1,}[@][a-zA-Z0-9]{1,}[\.][a-zA-Z]{2,}" required title=" \nSi prega di inserire una mail valida">
<label for="cellnumber" >Numero di cellulare:</label>
<input type="tel" name="tel" placeholder="39 333 333 3333" pattern="[0-9]{11,12}" required title=" \nNumero di telefono non valido\nInserire anche il prefisso">

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
<input type="text" name="prov" placeholder="MI" pattern="[a-zA-Z]{2}" required title=" \nScrivere l'ABBREVIAZIONE della provincia">
<label for="comune">Comune:</label>
<input type="text" name="comune" placeholder="Bollate" required>

<h4>Account</h4>
<label for="username">Username:</label>
<input type="text" name="user" pattern=".{4,}" required title=" \nL'username deve essere di minimo 4 caratteri">
<label for="password">Password:</label>
<input type="text" name="password" placeholder="min 8 car./1 spec./1 maiu." pattern="(?=.*\d)(?=.*[A-Z])(?=.*[a-z])(?=.*[!@#$%&\-_+=?]).{8,}" required title=" \nNon hai inserito una o più delle seguenti cose\nUna maiuscola, Un Carattere Speciale, La password è più corta di 8 caratteri">
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
    $ind = $_POST["tipo"] . " " . $_POST["via"] . ", " . strtoupper($_POST["prov"]) . " " . $_POST["comune"];
    $user = $_POST["user"];
    $pass = $_POST["password"];

    $html = "<h3>Dati Inseriti</h3>\n";
    $html = $html . "<h4>Dati Personali</h4><br>\n";
    $html = $html . "<p>Nome e Cognome: $nome $cog<br>\n";
    $html = $html . "Nato il: $data<br>\n";
    if($_POST["codicefis"] != null){
        $html = $html . "Codice Fiscale: $codfis<br>\n";
    }
    $html = $html . "Mail Personale: $mail<br>\n";
    $html = $html . "Telefono Personale: $tel<br>\n";
    $html = $html . "Indirizzo Completo: $ind</p><br>\n";
    $html = $html . "<h4>Dati D'Accesso</h4>\n";  
    $html = $html . "<p>Username: $user<br>\n";
    $html = $html . "<p>Password: $pass<br>\n";
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