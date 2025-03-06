<?php
require __DIR__ . '/vendor/autoload.php';

use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;

require 'vendor/autoload.php';

$mail = new PHPMailer(true);


try {

    // Configura SMTP
    $mail->isSMTP();
    $mail->Host = 'smtp.gmail.com'; // Usa l'SMTP del tuo provider (Gmail, Outlook, Yahoo, ecc.)
    $mail->SMTPAuth = true;
    $mail->Username = getenv("EMAIL_SMTP"); // Sostituisci con la tua email
    $mail->Password = getenv("PASS_SMTP"); // Usa una "Password per le App" se usi Gmail
    $mail->SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS;
    $mail->Port = 587;
    // Configura il mittente e il destinatario
    $mail->setFrom(getenv("EMAIL_SMTP"), 'Buongallino da PHP');
    $mail->addAddress(getenv("MAIL_BASE"), 'Destinatario');
    // Imposta il contenuto dell'email
    $mail->Subject = 'Email di Test con PHPMailer';
    $mail->Body = 'Esatto, una mail di testing.';
    $mail->isHTML(true);
    // Invia l'email
    $mail->send();

    $html = 'Email inviata con successo!';
} catch (Exception $e) {
    $html = "Errore nell'invio dell'email: {$mail->ErrorInfo}";
}


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
                    <li><a href="index.php"><u>HomePage prova</u></a></li>
                    <hr>
                    <li><a href="APCu.php"><u>Prova APCu</u></a></li>
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



