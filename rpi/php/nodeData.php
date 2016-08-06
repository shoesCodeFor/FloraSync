<?php
	require ('connector.php');
	
	$nodeID = $_GET["nodeID"];
	$sensor1 = $_GET["sensor1"];
	connect();
	runQuery();
	closeLink();	
?>
