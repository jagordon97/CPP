#include <iostream>
using namespace std;

int main() {
    int carb_grams, protein_grams, fat_grams, calories;

    cout << "Please input grams of carbs" << endl;
    cin >> carb_grams;
    cout << "Please input grams of protein" << endl;
    cin >> protein_grams;
    cout << "Please input grams of fat" << endl;
    cin >> fat_grams;

    calories = 4* carb_grams + 4*protein_grams + 9*fat_grams;
    cout << "There are " << calories << " calories in this dish" << endl;
    
    system("pause");
}