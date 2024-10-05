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
                </ul>
            </nav>
        </div>
        <div class="content">
        <?php
        // Imposta i parametri di connessione ODBC
        $dsn = 'AccessDB'; // Il nome del DSN
        $user = '';        // Nome utente, se necessario (di solito vuoto per Access)
        $password = '';    // Password, se necessaria (di solito vuoto per Access)

        // Prova a stabilire la connessione ODBC
        $conn = odbc_connect($dsn, $user, $password);

        if (!$conn) {
            // Gestisci l'errore di connessione
            die("Connessione ODBC fallita: " . odbc_errormsg());
        }

        // Costruisci la query per selezionare tutti i record dalla tabella
        $sql = "SELECT * FROM TabellaStudenti ORDER BY ID"; 

        // Esegui la query
        $result = odbc_exec($conn, $sql);

        if (!$result) {
            // Gestisci l'errore durante l'esecuzione della query
            die("Errore durante l'esecuzione della query: " . odbc_errormsg($conn));
        }

        // Supponiamo che tu abbia già ottenuto i dati dalla tabella
        if (odbc_fetch_row($result)) {
            echo "<h4>Lista dei record</h4>";
            echo "<table>";
            echo "<tr>";

            // Ottieni i nomi delle colonne
            $num_fields = odbc_num_fields($result);
            for ($i = 1; $i <= $num_fields; $i++) {
                $col_name = odbc_field_name($result, $i);
                echo "<th>" . htmlspecialchars($col_name) . "</th>";
            }
            echo "</tr>";

            // Recupera e stampa tutte le righe
            do {
                echo "<tr>";
                for ($i = 1; $i <= $num_fields; $i++) {
                    $col_name = odbc_field_name($result, $i); // Ottieni il nome della colonna in ogni iterazione
                    $cell = odbc_result($result, $i);

                    // Controlla se la colonna è per il campo DSA
                    if ($col_name === 'DSA') { 
                        echo "<td>" . htmlspecialchars($cell ? "SI" : "NO") . "</td>";
                    } else {
                        echo "<td>" . htmlspecialchars($cell) . "</td>";
                    }
                }
                echo "</tr>";
            } while (odbc_fetch_row($result));

            echo "</table>";
        } else {
            echo "Nessun record trovato.";
        }

        // Chiudi la connessione
        odbc_close($conn);
        ?>
        </div>
    </div>
    
    <footer>
        <p>&copy; 2024 Buongallino Alessandro</p>
    </footer>
</body>
</html>