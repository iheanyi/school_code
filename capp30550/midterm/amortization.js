// start helper functions
var $ = function (id) {
    return document.getElementById(id);
};

var buildTableHead = function (h1, h2, h3, h4, h5, h6) {
   return "<table border='1'><tr><th>"+h1+"</th><th>"+h2+"</th><th>"+h3+"</th><th>"+h4+"</th><th>"+h5+"</th><th>"+h6+"</th></tr>";
};

var buildTableRow = function (month, rp, pp, ip, tip, tpp) {
   return "<tr><td>" + month + "</td><td align='right'>" + rp.toFixed(2) + "</td><td align='right'>" + pp.toFixed(2) + "</td><td align='right'>" + ip.toFixed(2) + "</td><td align='right'>" + tip.toFixed(2) + "</td><td align='right'>" + tpp.toFixed(2) + "</td></tr>";
};

var closeTable = function () {
   return "</table>";
};
// end helper functions

var calculate = function () {
    // alert("Test Click");
    // declare and assign variable values
    var principal = parseFloat(document.getElementById('principal').value);
    var interestRate = parseFloat(document.getElementById('interest').value);
    var payment = parseFloat(document.getElementById('payment').value);


    var monthlyInterestRate = interestRate / 12;

    var output = buildTableHead("Month", "Remaining Principal", "Principal Paid", "Interest Paid", "Total Interest Paid", "Total Principal Paid");

    var totalPrincipalPaid = 0
    var totalInterestPaid = 0;
    var remainingPrincipal = principal;
    var months = 1;

    while (remainingPrincipal > 0 || remainingPrincipal > payment) {
      monthlyInterestPaid = remainingPrincipal * monthlyInterestRate;
      principalPaid = payment - monthlyInterestPaid;
      remainingPrincipal -= principalPaid;
      totalInterestPaid += monthlyInterestPaid;
      totalPrincipalPaid += principalPaid;

      output += buildTableRow(months, remainingPrincipal, principalPaid, monthlyInterestPaid, totalInterestPaid, totalPrincipalPaid);

      months++;
      console.log(months);
    }

    console.log(output);



    // define loop to perform calculations and build amortization schedule table



    // end loop


    // HINT
    $("atable").innerHTML = output;
};

//wire calculate button click event
window.onload = function () {
    $("calculate").onclick = calculate;
};