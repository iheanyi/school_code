
var $ = function (id) {
    return document.getElementById(id);
}

window.onload = function(){
  var calculateButton = $('calculate');

  calculateButton.addEventListener("click", function() {
    var length = $('length').value;
    var width = $('width').value;

    if (length < 0 || width < 0 || isNaN(length) || isNaN(width)) {
      alert("You've entered at least one invalid value, please enter a positive number for the length and width.");
    } else {
      var area_tag = $('area');
      var perimeter_tag = $('perimeter');

      var area = length*width;
      var perimeter = 2*width + 2*length;

      area_tag.value = area.toFixed(2);
      perimeter_tag.value = perimeter.toFixed(2);;
    }

  });

}