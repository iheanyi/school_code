var $ = function (id) { return document.getElementById(id); };

function convertCelsiusToFahrenheit(temperature) {

}


function convertFahrenheitToCelsius(temperature, convertCelsius) {

}

window.onload = function () {
    var convert = $('convert');
    var to_celcius = $('to_celcius');
    var to_fahrenheit = $('to_fahrenheit');
    var deg_f = $('degrees_fahrenheit');
    var deg_c = $('degrees_celcius');

    console.log("ready!");
    to_fahrenheit.onclick = function() {
      deg_f.disabled = true;
      deg_c.disabled = false;
      console.log("Disabled Celsius!");
    }

    console.log(deg_f);
    console.log(deg_c);
    to_celcius.onclick = function() {
      deg_c.disabled = true;
      deg_f.disabled = false;
      console.log("Disabled Fahrenheit!");
    }

    convert.onclick = function() {
      if (to_celcius.checked) {
    /*    deg_f.disabled = false;
        deg_c.disabled = true;*/
        var degrees = (deg_f.value - 32) * 5/9;
        deg_c.value = degrees;
      } else {
/*        deg_f.disabled = true;
        deg_c.disabled = false;*/
        var degrees = (deg_c.value) * 9/5 + 32;
        deg_f.value = degrees;
      }
    }
};

