#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Expense
{
string category;
double amount;
};

int main() 
{ 
vector <Expense> expenses;

int numberOffExpenses;

cout << "=== Expense Data Analyzer ===" << endl;
cout << "How many expenses do you want to enter? ";
cin >> numberOffExpenses;

for (int i = 0; i < numberOffExpenses; i++) 
{
Expense expense;

cout << "\nExpense " << i + 1 << endl;

cout << "Enter category: ";
cin >> expense.category;

cout << "Enter amount: $";
cin >> expense.amount;

expenses.push_back(expense);
}

double total = 0;

for (const Expense& expense : expenses) {
total += expense.amount;
}

cout << fixed << setprecision(2);
cout << "\n=== Expense Summary ===" << endl;
cout << "Total expenses: $" << total << endl;

cout << "\nAll Expenses: " << endl;

for (const Expense& expense : expenses ) {
cout << expense. category << ": $" << expense.amount << endl;
}

return 0;
}
