var $ = function (id) {
    return document.getElementById(id);
}


function makeChange(cents, denominator, amount) {
  if (cents-denominator < 0) {
    return amount;
  } else {

    return makeChange(cents - denominator, denominator, amount+1);
  }


}
window.onload = function(){
  var calculateButton = $('calculate');


  calculateButton.addEventListener('click', function() {
    var changeValue = parseInt($('cents').value);
    var quartersTag = $('quarters');
    var dimesTag = $('dimes');
    var nickelsTag = $('nickels');
    var penniesTag = $('pennies');

    // Get maximum number of quarters first
    var quartersValue = makeChange(changeValue, 25, 0);
    changeValue -= quartersValue*25;
    $('quarters').value = quartersValue;

    // Next dimes
    var dimesValue = makeChange(changeValue, 10, 0);
    changeValue -= dimesValue*10;
    $('dimes').value = dimesValue;

    // Next nickels
    var nickelsValue = makeChange(changeValue, 5, 0);
    changeValue -= nickelsValue*5;
    $('nickels').value = nickelsValue

    // Then pennies;
    var penniesValue = makeChange(changeValue, 1, 0);
    $('pennies').value = penniesValue;
  });
}