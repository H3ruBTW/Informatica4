<?php
require "config.php";
require __DIR__ . '/vendor/autoload.php';

use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;

$mail = new PHPMailer(true);

try {
    // Configura SMTP
    $mail->isSMTP();
    $mail->Host = 'smtp.gmail.com'; // SMTP del provider
    $mail->SMTPAuth = true;
    $mail->Username = EMAIL_SMTP; // Tua email
    $mail->Password = PASS_SMTP;  // Password per le app se usi Gmail
    $mail->SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS;
    $mail->Port = 587;

    // Configura mittente e destinatario
    $mail->setFrom(EMAIL_SMTP, 'Buongallino da PHP');
    $mail->addAddress(MAIL_BASE, 'Destinatario');

    // Oggetto dell'email
    $mail->Subject = 'Email di Test con PHPMailer';

    // Imposta il contenuto dell'email con HTML interno
    $mail->isHTML(true);
    $mail->Body = '
    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Conferma Email</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                margin: 0;
                padding: 0;
            }
            .container {
                max-width: 600px;
                margin: 20px auto;
                background: #ffffff;
                padding: 20px;
                border-radius: 8px;
                box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            }
            .header {
                background: #007bff;
                color: #ffffff;
                padding: 10px;
                text-align: center;
                font-size: 24px;
                border-radius: 8px 8px 0 0;
            }
            .content {
                padding: 20px;
                text-align: center;
            }
            .button {
                display: inline-block;
                padding: 10px 20px;
                margin-top: 20px;
                background: #007bff;
                color: #ffffff;
                text-decoration: none;
                border-radius: 5px;
            }
            .footer {
                margin-top: 20px;
                font-size: 12px;
                color: #666666;
                text-align: center;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <div class="header">Conferma la tua Email</div>
            <div class="content">
                <p>Ciao,</p>
                <p>Grazie per esserti registrato! Clicca sul pulsante qui sotto per confermare il tuo indirizzo email.</p>
                <a href="https://www.google.com" class="button">Conferma Email</a>
            </div>
            <div class="footer">
                Se non hai richiesto questa email, ignora questo messaggio.<br>
                &copy; 2025 Il Tuo Sito. Tutti i diritti riservati.
            </div>
        </div>
    </body>
    </html>
    ';

    // Invia l'email
    $mail->send();

    echo 'Email inviata con successo!';
} catch (Exception $e) {
    echo "Errore nell'invio dell'email: {$mail->ErrorInfo}";
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
                    <li><a href="PHPMailer.php"><u>PHPMailer</u></a></li>
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



