#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <algorithm> 
#include <fstream>
#include <sstream>

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

while (numberOffExpenses <= 0) {
    cout << "Please enter a number greater than 0: ";
    cin >> numberOffExpenses;
}

for (int i = 0; i < numberOffExpenses; i++) 
{
Expense expense;

cout << "\nExpense " << i + 1 << endl;

cout << "Enter category: ";
cin >> expense.category;

cout << "Enter amount: $";
cin >> expense.amount;

while (expense.amount < 0) { 
    cout << "Amount cannot be negative. Enter again: $";
    cin >> expense.amount;
}

expenses.push_back(expense);
}

//Calculate total spending
double total = 0;

for (const Expense& expense : expenses) {
total += expense.amount;
}

// Calculate average spending
double average =0;

if (!expenses.empty()) {
    average = total / expenses.size();
}

cout << fixed << setprecision(2);

cout << "\n=== Expense Summary ===" << endl;
cout << "Total expenses: $" << total << endl;
cout << "Average expense: $" << average << endl;

cout << "\nAll Expenses: " << endl;

for (const Expense& expense : expenses ) {
cout << expense. category << ": $" << expense.amount << endl;
}

// Calculating spending by category
map<string, double> categoryTotals;

for(const Expense& expense : expenses) { 
    categoryTotals[expense.category] += expense.amount;
}

cout << "\n=== Spending by Category ===" << endl;

for (const auto& category : categoryTotals) {
    cout << category.first << ": $" << category.second << endl;
}

// Find highest and lowest expense
if (!expenses.empty()) {
    Expense highest = expenses[0];
    Expense lowest = expenses[0];

    for (const Expense& expense : expenses) {
        if (expense.amount >highest.amount) {
            highest = expense;
        }

        if (expense.amount < lowest.amount) {
            lowest = expense;
        }
    }

    cout << "\n=== Highest and Lowest Expense ===" << endl;
    cout << "Highest expense: " << highest.category << " - $" << highest.amount << endl;
    cout << "Lowest expense: " << lowest.category << " - $ " << lowest.amount << endl;
}

// Search expenses by category
string searchCategory;

cout << "\n=== Search Expenses ===" << endl;
cout << "Enter a category to search: ";
cin >> searchCategory;

bool found = false;

for (const Expense& expense : expenses) {
    if (expense.category == searchCategory) {
        cout << expense.category << ": $" << expense.amount << endl;

        found = true;
    }
}

if (!found) {
    cout << " No expenses found for that category." << endl;
}

// Sort expenses from highest to lowest 
vector<Expense> sortedExpenses = expenses;

sort(sortedExpenses.begin(), sortedExpenses.end(), [](const Expense& a, const Expense& b) {
    return a.amount > b.amount;
});

cout << "\n=== Expenses Sorted by Amount ===" << endl;
for (const Expense& expense : sortedExpenses) {
    cout << expense.category << ": $" << expense.amount << endl;
}

// Save expenses to a CSV file
ofstream file("expense.csv");

file << "Category,Amount\n";

for (const Expense& expense : expenses) {
    file << expense.category << "," << expense.amount << "\n";
}

file.close();

cout << "\nExpenses saved to expenses.csv" << endl;

// Load expenses from CSV file
ifstream inputFile("expenses.csv");

string line;

cout << "\n=== Expenses Loaded from CSV ===" <<< endl;

// Skip the header 
getline(inputFile, line);

while 
return 0;
}