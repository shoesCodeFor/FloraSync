<?php 

   


	$servername = "localhost";
	$username = "yourUserName";
	$password = "yourPsswd";
	$dbName = "fsLocal";
	
	
	// Create connection
    $conn = mysqli_connect($servername, $username, $password);

    // Check connection
    if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
    }
    echo "victory";

    mysqli_close($conn);




?>