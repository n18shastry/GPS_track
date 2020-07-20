<?php
   
    $dbusername = "owner";  
    $dbpassword = "findmyloc123";  
    $server = "localhost"; 
  
    $dbconnect = mysqli_connect($server, $dbusername, $dbpassword);
    $dbselect = mysqli_select_db($dbconnect, "ipLoc");
  	
	$request= $_GET['loc'];

    $sql = "INSERT INTO ipLoc.locations (Coordinates) VALUES ('$request')";    
 
    mysqli_query($dbconnect, $sql);

?>