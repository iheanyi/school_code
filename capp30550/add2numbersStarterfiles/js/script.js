var $ = function(id) {
  return document.getElementById(id);
};

function performOperation(operation) {
  var total;

  var num1 = parseFloat($("n1").value);
  var num2 = parseFloat($("n2").value);

  if(operation == "add") {
    total = num1 + num2;
  } else if(operation == "sub") {
    total = num1 - num2;
  } else if(operation == "mult") {
    total = num1 * num2;
  } else if(operation == "div") {
    total = num1 / num2;
  }

  $("r1").value = total;
}

var add2numbers = function () {
  //assign numbers to variables from html input
  //alert("function started");
  perof
  var n1 = parseFloat($("n1").value);
  //alert("n1="+n1);
  var n2 = parseFloat($("n2").value);
  //alert("n2="+n2);
  //add n1 and n2
  var total = n1 + n2;
  //alert("total="+total);
  console.log("total="+total);
  //output total to input box with id=r1
  $("r1").value = total;
};

var sub2numbers = function () {
  //assign numbers to variables from html input
  //alert("function started");
  var n1 = parseFloat($("n1").value);
  //alert("n1="+n1);
  var n2 = parseFloat($("n2").value);
  //alert("n2="+n2);
  //add n1 and n2
  var total = n1 - n2;
  //alert("total="+total);
  console.log("total="+total);
  //output total to input box with id=r1
  $("r1").value = total;
};

var mult2numbers = function () {
  //assign numbers to variables from html input
  //alert("function started");
  var n1 = parseFloat($("n1").value);
  //alert("n1="+n1);
  var n2 = parseFloat($("n2").value);
  //alert("n2="+n2);
  //add n1 and n2
  var total = n1 * n2;
  //alert("total="+total);
  console.log("total="+total);
  //output total to input box with id=r1
  $("r1").value = total;
};

var div2numbers = function () {
  //assign numbers to variables from html input
  //alert("function started");
  var n1 = parseFloat($("n1").value);
  //alert("n1="+n1);
  var n2 = parseFloat($("n2").value);
  //alert("n2="+n2);
  //add n1 and n2
  var total = n1 / n2;
  //alert("total="+total);
  console.log("total="+total);
  //output total to input box with id=r1
  $("r1").value = total;
};

var random_number = function(min,max,digits){

  digits = isNaN(digits)?0:parseInt(digits);

  if(digits < 0){
    digits = 0;
  }else if(digits > 16){

    digits = 16;
  }

  if(digits = 0){
    return Math.floor(Math.random()*(max - min +1))+min;
  }else {

    var rand = Math.random()*(max - min)+min;
    return parseFloat(rand.toFixed(digits));
  }

};

window.onload = function(){

  $("btnAdd").onclick = function() {
    performOperation("add");
  };

  $("btnSub").onclick = function() {
    performOperation("sub");
  }

  $("btnMult").onclick = function() {
    performOperation("mult");
  }

  $("btnDiv").onclick = function() {
    performOperation("div");
  }

}
