#include<bits/stdc++.h>
using namespace std;

class Restaurant 
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;

    Restaurant(int food_item_codes[12], string food_item_names[12], int food_item_prices[12]){
        for(int i=0;i<12;i++){
            this->food_item_codes[i] = food_item_codes[i];
            this->food_item_prices[i] = food_item_prices[i];
            this->food_item_names[i] = food_item_names[i];
        } 
        
    }

    void show_item(){
         cout<<"                                "<<"Make bill"<<endl;
         cout<<"                           "<<"___________________"<<endl<<endl;
         cout<<"Item code:"<<"      "<<"Item name:"<<"                      "<<"Item Price:"<<endl;
         for(int i=0;i<12;i++){
            cout<<food_item_codes[i]<<"             "<<left<<setw(25)<<food_item_names[i]<<"       "<<food_item_prices[i]<<endl;
         } 
    }


    void food_item(int item_count,int item_code[],int foodItem[]){
        for(int i=0;i<item_count;i++){
            for(int j=0;j<12;j++){
                if(item_code[i] == food_item_codes[j]) {
                    foodItem[i] = j;
                }
            }
        }
    }

};

Restaurant* takeInput(){
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>food_item_codes[i];
        cin.ignore();
        getline(cin, food_item_names[i]);
        cin>>food_item_prices[i];
    } 
    
    
    Restaurant *myRes = new Restaurant(food_item_codes,food_item_names,food_item_prices); 
    return myRes;
}


int main(){
    Restaurant *myRes = takeInput();
    myRes->show_item();

    //take input from the customer
    int table_no,item_count;

    cout<<"Enter table no: ";
    cin>>table_no;
    cout<<endl<<"Enter number of items: ";
    cin>>item_count;

    int item_code[item_count], quantity[item_count];
    
    for(int i=0;i<item_count;i++){
        cout<<endl<<"Ente item "<<i<<" code: ";
        cin>>item_code[i];
        cout<<endl<<"Ente item "<<i<<" quantity: ";
        cin>>quantity[i];
    }

    int foodIitem[item_count] = {-1};
    myRes->food_item(item_count,item_code,foodIitem);

    // for(int i=0;i<item_count;i++){
    //     cout<<endl<<"index"<<foodIitem[i];
    // }

    //Bill summary
    cout<<"                                "<<"Bill summary"<<endl;
    cout<<"                           "<<"___________________"<<endl<<endl;
    cout<<"table no: "<<table_no<<endl;
    
    
    return 0;
}