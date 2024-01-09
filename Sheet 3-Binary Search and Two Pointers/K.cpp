// Polycarpus loves hamburgers very much. He especially adores the hamburgers he makes with his own hands. 
// Polycarpus thinks that there are only three decent ingredients to make hamburgers from: a bread, 
// sausage and cheese. He writes down the recipe of his favorite "Le Hamburger de Polycarpus" as a string of 
// letters 'B' (bread), 'S' (sausage) и 'C' (cheese). The ingredients in the recipe go from bottom to top, 
// for example, recipe "ВSCBS" represents the hamburger where the ingredients go from bottom to top as bread, 
// sausage, cheese, bread and sausage again.
// Polycarpus has nb pieces of bread, ns pieces of sausage and nc pieces of cheese in the kitchen. 
// Besides, the shop nearby has all three ingredients, the prices are pb rubles for a piece of bread, 
// ps for a piece of sausage and pc for a piece of cheese.
// Polycarpus has r rubles and he is ready to shop on them. What maximum number of hamburgers can he cook? 
// You can assume that Polycarpus cannot break or slice any of the pieces of bread, sausage or cheese. 
// Besides, the shop has an unlimited number of pieces of each ingredient.
// Input
// The first line of the input contains a non-empty string that describes the recipe of 
// "Le Hamburger de Polycarpus". The length of the string doesn't exceed 100, the string contains only letters 
// 'B' (uppercase English B), 'S' (uppercase English S) and 'C' (uppercase English C).
// The second line contains three integers nb, ns, nc (1 ≤ nb, ns, nc ≤ 100) — the number of the pieces of bread, 
// sausage and cheese on Polycarpus' kitchen. 
// The third line contains three integers pb, ps, pc (1 ≤ pb, ps, pc ≤ 100) — the price of one piece of bread, 
// sausage and cheese in the shop. Finally, the fourth line contains integer r 
// (1 ≤ r ≤ 1012) — the number of rubles Polycarpus has.
// Please, do not write the %lld specifier to read or write 64-bit integers in С++.
// It is preferred to use the cin, cout streams or the %I64d specifier.
// Output
// Print the maximum number of hamburgers Polycarpus can make. If he can't make any hamburger, print 0.

#include <iostream>
#include <algorithm>

using namespace std;

long long solve(string recipe, long long bunsRequired, long long sauceRequired, long long cheeseRequired,long long bunCost, long long sauceCost, long long cheeseCost, long long budget) {
    long long left = 0, right = 1e15;
    long long maxHamburgers = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        long long extraBuns = max(0LL, mid * count(recipe.begin(), recipe.end(), 'B') - bunsRequired);
        long long extraSauce = max(0LL, mid * count(recipe.begin(), recipe.end(), 'S') - sauceRequired);
        long long extraCheese = max(0LL, mid * count(recipe.begin(), recipe.end(), 'C') - cheeseRequired);

        long long totalCost = extraBuns * bunCost + extraSauce * sauceCost + extraCheese * cheeseCost;

        if (totalCost <= budget) {
            maxHamburgers = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return maxHamburgers;
}
int main() {
    string recipe;
    cin >> recipe;

    long long bunsRequired, sauceRequired, cheeseRequired;
    cin >> bunsRequired >> sauceRequired >> cheeseRequired;

    long long bunCost, sauceCost, cheeseCost;
    cin >> bunCost >> sauceCost >> cheeseCost;

    long long budget;
    cin >> budget;

    long long maxHamburgers = solve(recipe, bunsRequired, sauceRequired, cheeseRequired,bunCost, sauceCost, cheeseCost, budget);

    cout << maxHamburgers << endl;

    return 0;
}