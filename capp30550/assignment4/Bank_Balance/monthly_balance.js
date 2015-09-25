var $ = function(id) { return document.getElementById(id); };

function updateTransactions() {
  trans_list.innerHTML = "";
  output = "";
  for(var i = 0; i < transactions.length; i++) {
    if(i == 0) {
          output += transactions[i][0] + "\t\t\t" + transactions[i][1] + "\t\t" + transactions[i][2] + "\n";
        } else if(i == 1) {
           output += transactions[i][0] + "\t" + transactions[i][1] + "\t" + transactions[i][2] + "\n";
        } else {
          output += transactions[i][0] + "\t$\t" + transactions[i][1] + "\t\t$\t" + transactions[i][2].toFixed(2) + "\n";
        }

  }
  trans_list.innerHTML = output;
}

function initializeVariables() {
  startBalanceText = $('starting_balance');
  transDate = $('trans_date');
  trans_type = $('trans_type');
  endBalanceText = $('ending_balance');
  totalDepositsText = $('total_deposits');
  totalWithdrawalsText = $('total_withdrawals');
  transactionButton = $('add_trans');
  transList = $('trans_list');
  transAmount = $('trans_amount');
  transType = $('trans_type');
  transactions = [];

  transactions.push(["Date", "Amount", "Running Balance"]);
  transactions.push(["---------", "---------", "-----------"]);


  startBalance = 2000.00;
  endingBalance = startBalance;
  totalDeposits = 0;
  totalWithdrawals = 0;
}

function updateSummary() {
    startBalanceText.value = startBalance.toFixed(2);
    endBalanceText.value = endingBalance.toFixed(2);
    totalDepositsText.value = totalDeposits.toFixed(2);
    totalWithdrawalsText.value = totalWithdrawals.toFixed(2);
}

function updateScreen() {
  updateTransactions();
  updateSummary();
}

function addTransaction() {
  var new_date = transDate.value;
  var amount = parseFloat(transAmount.value);

  console.log(trans_type.value);
  if(trans_type.value == "deposit") {
    totalDeposits += amount;
    endingBalance += amount;
    transactions.push([new_date, amount, endingBalance]);
  } else {
    totalWithdrawals -= amount;
    endingBalance -= amount;
    transactions.push([new_date, -1*amount, endingBalance]);
  }

}
window.onload = function () {
    initializeVariables();
    updateScreen();

    transactionButton.onclick = function() {
      addTransaction();
      updateScreen();
    }
};

