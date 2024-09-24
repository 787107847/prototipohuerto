<?php 

$hostname ="ecofloat.space";
$username ="";
$password = "";
$database = "";

$conn = mysqli_connect($hostname,$username,$password,$database);
$rows = mysqli_query($conn,"SELECT * 
FROM medicion 
ORDER BY Tiempo DESC 
LIMIT 5
 ");

?>

<table border = 1 cellpadding = 10>

    <<tr>
        <td>#</td>
        <td>ID</td>
        <td>Tiempo</td>
        <td>Temperatura</td>
        <td>Humedad</td>
        <td>N° Balsa</td>
    </tr>

    <?php $i = 1; ?>
    <?php foreach($rows as $row) :?>
        <<tr>
        <td><?php echo $i++; ?></td>
        <td><?php echo $row["IdMedicion"]; ?></td>
        <td><?php echo $row["Tiempo"]; ?></td>
        <td><?php echo $row["Temperatura"]; ?></td>
        <td><?php echo $row["Humedad"]; ?></td>
        <td><?php echo $row["IdBalsa"]; ?></td>
    </tr>
    <?php endforeach; ?>


</table>