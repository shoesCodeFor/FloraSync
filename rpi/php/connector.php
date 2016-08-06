<?php 
	
	


        $link =  mysqli_connect("127.0.0.1", "yourUserName", "yourPassword", "fsLocal");

        if (!$link) {
            echo "Error: Unable to connect to MySQL." . PHP_EOL;
            echo "Debugging errno: " . mysqli_connect_errno() . PHP_EOL;
            echo "Debugging error: " . mysqli_connect_error() . PHP_EOL;
            exit;
        }

        echo "Success: A proper connection to MySQL was made! The my_db database is great." . PHP_EOL;
        echo "Host information: " . mysqli_get_host_info($link) . PHP_EOL;


	function runQuery(){
		$sql = "INSERT INTO nodeData (nodeID,sensor1)
		VALUES (" . $nodeID",". $sensor1 ." )";
		$query =  $sql;

		if ($link->query($sql) === TRUE) {
    		echo "New record created successfully";}
 		else {
    		echo "Error: " . $sql . "<br>" . $link->error;
		}
	}
	function closeLink(){
        mysqli_close($link);
    	}


	
	closeLink();
?>


