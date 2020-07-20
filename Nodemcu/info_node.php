<?php
   
    $dbusername = "owner";  
    $dbpassword = "findmyloc123";  
    $server = "localhost"; 
  
    $dbconnect = mysqli_connect($server, $dbusername, $dbpassword);
    $dbselect = mysqli_select_db($dbconnect, "ipLoc");
  	
	$request= $_GET['lat'];
	$req= $_GET['lon'];
    $sql = "INSERT INTO ipLoc.nodemcu (latitude,longitude) VALUES ('$request','$req')";    
 
    mysqli_query($dbconnect, $sql);

?>