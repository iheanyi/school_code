<html>
<body>

<?php
  $theuser = $_POST['user'];
  $thepwd = $_POST['pwd'];
  $conn = oci_connect($theuser, $thepwd) 
     or die("<br>Couldn't connect");

  $query = "select user from dual";

  $stmt = oci_parse($conn, $query);
  oci_define_by_name($stmt, "USER", $u);
  oci_execute($stmt);
  oci_fetch($stmt);

  echo "Connected! The user is: $u";

  oci_close($conn);
?> 

</body>
</html>

