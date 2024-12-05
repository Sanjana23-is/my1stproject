let salary = 0;
let totalExpenses = 0;

document.addEventListener('submit', function(event) {
    event.preventDefault();
    let salaryInput = document.getElementById('salary-amount').value;
    console.log(salaryInput);
    salary = salaryInput;
    document.getElementById('display-salary').innerText = salaryInput;
});

document.addEventListener('submit1', function(event) {
    event.preventDefault();
    const expenseAmount = document.getElementById('expense-amount').value;

    totalExpenses = expenseAmount;

    document.getElementById('display-expenses').innerText = totalExpenses;
    displaySummary();
});

function displaySummary() {
    const savedMoney = salary - totalExpenses;
    document.getElementById('display-savings').innerText = savedMoney;
    if(savedMoney > 0) {
        document.getElementById('investment-suggestions').innerHTML = "hello"
    }
}