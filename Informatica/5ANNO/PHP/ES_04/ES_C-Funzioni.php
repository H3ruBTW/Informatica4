<?php
function CheckSession(){
    if(isset($_SESSION['usernameC'])){
        header('Location: ES_C-Riservata.php');
    } 
}

function DisplayError(){
    if($_SERVER['REQUEST_METHOD']=="GET"){
        if(isset($_GET['error'])){
            $html = "<p style=\"color:red\">" . $_GET['error'] . "</p>";
        }

        return $html;
    }

    return "";
}


?>