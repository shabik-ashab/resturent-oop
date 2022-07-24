#include <bits/stdc++.h>
using namespace std;

int main()
{
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];

    cin>>food_item_codes[0];
    getline(cin >> ws, food_item_names[0]);
    cin>>food_item_prices[0];
    

    cout<<"codes"<<food_item_codes[0]<<endl;
    cout<<"price"<<food_item_prices[0]<<endl;
    cout<<"name"<<food_item_names[0]<<endl;
    return 0;
}