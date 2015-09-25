

var $ = function (id) {
    return document.getElementById(id);
}

// enter code here
window.onload = function() {

  var powers_button = $('showpowers');

  powers_button.addEventListener("click", function() {
    console.log("Pressed");
    var lines = "Base \t\tSquared \tCubed\n";  var lines = "Base \t\t Squared \t\tCubed\n";
    var maxbase = $('maxbase').value;
    var powers_table = $('powers');


    for(var i = 1; i <= maxbase; i++) {
      line = i + "\t\t " +  Math.pow(i, 2) + "\t\t\t" + Math.pow(i, 3) + "\n";
      lines += line;
    }

    console.log(lines);
    powers_table.value = lines;
  });

}