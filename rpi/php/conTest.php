<?php
    //set these to your db settings.  We use MySQL
	$servername = "localhost";
	$username = "yourUserName";
	$password = "youPsswd";
	$dbName = "fsLocal";
	$nodeID = -1;
	$nodeID = $_GET["nodeID"];
    $sensor1 = -1;
    if(isset($_GET["sensor1"])){
	$sensor1 = $_GET["sensor1"];
    }
    $sensor2 = -1;
	$sensor2 = $_GET["sensor2"];
    $sensor3 = -1;
	$sensor3 = $_GET["sensor3"];
    $sensor4 = -1;
	$sensor4 = $_GET["sensor4"];
    $sensor5 = -1;
	$sensor5 = $_GET["sensor5"];
    $sensor6 = -1;
	$sensor6 = $_GET["sensor6"];
    
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
<?php echo date('Y-m-d H:i:s') ;?>