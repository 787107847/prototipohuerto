<?php 

$hostname ="ecofloat.space";
$username ="";
$password = "";
$database = "";

$conn = mysqli_connect($hostname,$username,$password,$database);

if(!$conn){
    die("Connection failed: " . mysqli_connect_error());
}

echo "Database connection OK";

if(isset($_POST["temperatura"]) && isset($_POST["humedad"])) {

$t =$_POST["temperatura"];
$h = $_POST["humedad"];
$sql = "INSERT INTO medicion (Tiempo, Temperatura, Humedad, IdBalsa) VALUES (CURRENT_TIMESTAMP, ".$t.", ".$h.", 1)";

if(mysqli_query($conn,$sql)){
    echo "Insersión correcta";
}else{
    echo "Error: " . $sql. "<br>" . mysqli_error($conn);
} }

?>