<?php

	$servername = "localhost";
	$username = "yourUserName";
	$password = "yourPsswd";
	$dbName = "fsLocal";
	$nodeID = 0;
	$nodeID = $_GET["nodeID"];
    $sensor1 = 0;
	$sensor1 = $_GET["sensor1"];
	// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbName);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
echo "Connected successfully". $nodeID;
$sql = "INSERT INTO nodeData (nodeID, sensor1)
VALUES (" . $nodeID . "," . $sensor1 . ");";

$setting = "SELECT * FROM `nodeSettings` WHERE nodeID=" . $nodeID;

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
$result = $conn->query($setting);

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["nodeID"]. $row["onTime"] .  $row["offTime"]
	. $row["waterThreshold"]. "<br>";
    }
} else {
    echo "0 results";
}
mysqli_close($conn);

?>
