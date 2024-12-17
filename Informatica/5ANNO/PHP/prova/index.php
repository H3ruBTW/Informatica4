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

$sql = "SELECT studente.ID, studente.cognome, materia.codice AS materia, voto.voto
        FROM studente
        LEFT JOIN voto ON studente.ID = voto.id_stud
        LEFT JOIN materia ON materia.ID = voto.id_materia
        ORDER BY studente.ID, materia.codice";
$result = $conn->query($sql);

if ($result && $result->num_rows > 0) {
    $currentStudentID = null;
    $studentData = []; // Array per organizzare i dati per studente

    // Organizza i dati
    while ($row = $result->fetch_assoc()) {
        $studentID = $row['ID'];
        $studentName = $row['cognome'];
        $materia = $row['materia'] ?? "N/A";
        $voto = $row['voto'];

        if (!isset($studentData[$studentID])) {
            $studentData[$studentID] = [
                'name' => $studentName,
                'materie' => []
            ];
        }

        if (!isset($studentData[$studentID]['materie'][$materia])) {
            $studentData[$studentID]['materie'][$materia] = [];
        }

        // Aggiungi i voti (anche se vuoti)
        $studentData[$studentID]['materie'][$materia][] = $voto;
    }

    // Genera l'HTML
    foreach ($studentData as $studentID => $data) {
        $html .= "<h3>Studente: " . htmlspecialchars($data['name']) . " (ID: $studentID)</h3>";
        $html .= "<table class='styled-table'>";

        // Intestazione con i nomi delle materie
        $html .= "<thead><tr>";
        foreach ($data['materie'] as $materia => $voti) {
            $html .= "<th>" . htmlspecialchars($materia) . "</th>";
        }
        $html .= "</tr></thead><tbody><tr>";

        // Righe con i voti verticali
        $maxRows = max(array_map('count', $data['materie'])); // Trova il numero massimo di voti
        for ($i = 0; $i < $maxRows; $i++) {
            $html .= "<tr>";
            foreach ($data['materie'] as $materia => $voti) {
                $html .= "<td>" . (isset($voti[$i]) ? htmlspecialchars($voti[$i]) : "") . "</td>";
            }
            $html .= "</tr>";
        }

        $html .= "</tbody></table>";
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