<?php 
$servername = "localhost"; // O l'indirizzo del server (ad esempio, 'LaptopHeru')
$username = "root"; // Nome utente di MySQL (per default su XAMPP è 'root')
$password = ""; // Password di MySQL (per default su XAMPP è vuota)
$dbname = "studenti"; // Nome del database

// Crea la connessione
$conn = new mysqli($servername, $username, $password, $dbname);

// Verifica la connessione
if ($conn->connect_error) {
    die("Connessione fallita: " . $conn->connect_error);
}

$html = "";

$sql = "SELECT studente.ID, studente.cognome, voto.voto
        FROM studente
        LEFT JOIN voto ON studente.ID = voto.id_stud
        ORDER BY studente.ID";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Iterazione sui dati e costruzione della stringa HTML
    $currentStudentID = null;
    
    while($row = $result->fetch_assoc()) {
        // Se l'ID studente cambia, aggiungiamo il nome dello studente
        if ($currentStudentID != $row['ID']) {
            $currentStudentID = $row['ID'];
            $html .= "<h3>Studente: " . $row["cognome"] . " (ID: " . $row["ID"] . ")</h3>";
        }
        
        // Aggiungi il voto per questo studente
        $html .= "<p>Voto: " . ($row["voto"] ? $row["voto"] : 'Nessun voto') . "</p>";
    }
} else {
    $html .= "<div class='no-results'>0 risultati</div>";
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="shortcut icon" href="img/icon.png">
    <link rel="stylesheet" href="css/style.css">
    <link rel="stylesheet" href="css/table.css">
    <title>Esercizi</title>
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
                    <li><a href="prova/index.php"><u>HomePage prova</u></a></li>
                    <hr>
                </ul>
            </nav>
        </div>
        <div class="content">
            <?php echo $html; ?>
        </div>
    </div>
    
    <footer>
        <p>&copy; 2024 Buongallino Alessandro</p>
    </footer>
</body>
</html>