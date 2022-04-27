#include <iostream>
#include <vector>
using namespace std;

void fillTable(const std::vector<int> &coins, int amt, std::vector<std::vector<int>> &table)
{
    for (int i = 0; i < coins.size(); i++)
    {
        table[i].resize(amt);
        for (int j = 1; j <= amt; j++)
        {
            if (i == 0)
            {
                table[i][j - 1] = j;
            }
            else
            {
                int rem = j % coins[i];
                int div = j / coins[i];
                int remcoin = (rem == 0) ? 0 : table[i - 1][rem - 1];
                table[i][j - 1] = div + remcoin;
            }
        }
    }
}
void printCombination(int amt, const std::vector<int> &coins)
{
    cout << "\nCombination is : ";
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        int ncoins = amt / coins[i];
        amt = amt % coins[i];
        cout << "\n(" << ncoins << "*" << coins[i] << ")\t";
    }
}
void printTable(std::vector<std::vector<int>> &table, const std::vector<int> &coins)
{
    cout << "\t";
    for (int i = 1; i <= table[0].size(); i++)
    {
        cout << i << "\t";
    }
    cout << std::endl;
    for (int i = 0; i < table.size(); i++)
    {
        cout << coins[i] << "\t";
        for (int j = 0; j < table[i].size(); j++)
        {
            cout << table[i][j] << "\t";
        }
        cout << std::endl;
    }
}
int main()
{
    const std::vector<int> coins = {1, 2, 5, 10};
    std::vector<std::vector<int>> table;
    table.resize(coins.size());
    int amount = 0;
    cout << "---------- Minimum coins required ----------" << endl;
    cout << "--------------------------" << endl;
    cout << "Enter the amount: ";
    cin >> amount;
    cout << "--------------------------------------" << endl;
    fillTable(coins, amount, table);
    printTable(table, coins);
    cout << "--------------------------------------" << endl;
    cout << "\nMinimum coins required : " << table[coins.size() - 1][amount - 1];
    printCombination(amount, coins);
    cout << endl
         << "--------------------------------------" << endl;
    return 0;
}
